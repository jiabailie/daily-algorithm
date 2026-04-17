#include <algorithm>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "leetcode/Base.h"

namespace {
    std::vector<std::string> discover_problem_ids() {
        std::vector<std::string> problem_ids;
        const std::filesystem::path leetcode_dir = std::filesystem::path(ALGORITHM_SOURCE_DIR) / "leetcode";

        for (const auto& entry : std::filesystem::directory_iterator(leetcode_dir)) {
            if (!entry.is_directory()) {
                continue;
            }
            problem_ids.push_back(entry.path().filename().string());
        }

        std::sort(problem_ids.begin(), problem_ids.end());
        return problem_ids;
    }

    bool contains(const std::vector<std::string>& values, const std::string& target) {
        return std::find(values.begin(), values.end(), target) != values.end();
    }
}

int main() {
    const std::vector<std::string> expected_ids = discover_problem_ids();
    const std::vector<std::string> registered_ids = SolutionRegistry::instance().keys();

    bool passed = true;

    if (expected_ids.empty()) {
        std::cerr << "No problem directories were found under leetcode/" << '\n';
        return 1;
    }

    for (const std::string& problem_id : expected_ids) {
        if (!contains(registered_ids, problem_id)) {
            std::cerr << "Missing registry entry for problem id " << problem_id << '\n';
            passed = false;
        }

        std::unique_ptr<Base> solution = SolutionRegistry::instance().create(problem_id);
        if (solution == nullptr) {
            std::cerr << "Failed to construct solution for problem id " << problem_id << '\n';
            passed = false;
        }
    }

    if (!passed) {
        return 1;
    }

    std::cout << "Registered " << registered_ids.size() << " solutions." << std::endl;
    return 0;
}
