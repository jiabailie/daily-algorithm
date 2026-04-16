//
// Created by Ruiguo Yang on 2026/4/16.
//

#ifndef ALGORITHM_BASH_H
#define ALGORITHM_BASH_H

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Base {
public:
    virtual ~Base() = default;
    virtual void test() {}
};

class SolutionRegistry {
public:
    using Factory = std::function<std::unique_ptr<Base>()>;

    static SolutionRegistry& instance() {
        static SolutionRegistry registry;
        return registry;
    }

    void add(std::string key, Factory factory) {
        factories_[std::move(key)] = std::move(factory);
    }

    // Build a fresh solution instance for the requested problem id.
    std::unique_ptr<Base> create(const std::string& key) const {
        auto it = factories_.find(key);
        if (it == factories_.end()) {
            return nullptr;
        }
        return it->second();
    }

    std::vector<std::string> keys() const {
        std::vector<std::string> result;
        result.reserve(factories_.size());
        for (const auto& [key, _]: factories_) {
            result.push_back(key);
        }
        return result;
    }

private:
    // Keep ids ordered so the CLI usage output is stable and easy to scan.
    std::map<std::string, Factory> factories_;
};

class SolutionRegistrar {
public:
    // Register during static initialization so main() only needs a problem id.
    SolutionRegistrar(std::string key, SolutionRegistry::Factory factory) {
        SolutionRegistry::instance().add(std::move(key), std::move(factory));
    }
};

#define ALGORITHM_CONCAT_INNER(X, Y) X##Y
#define ALGORITHM_CONCAT(X, Y) ALGORITHM_CONCAT_INNER(X, Y)

// __COUNTER__ gives each translation unit its own unique registrar symbol.
#define REGISTER_LEETCODE_SOLUTION_IMPL(PROBLEM_ID, TYPE, N) \
    namespace { \
        SolutionRegistrar ALGORITHM_CONCAT(solution_registrar_, N)(PROBLEM_ID, []() { \
            return std::make_unique<TYPE>(); \
        }); \
    }

#define REGISTER_LEETCODE_SOLUTION(PROBLEM_ID, TYPE) \
    REGISTER_LEETCODE_SOLUTION_IMPL(PROBLEM_ID, TYPE, __COUNTER__)

#endif //ALGORITHM_BASH_H
