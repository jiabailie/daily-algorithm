#include <iostream>
#include <string>
#include <vector>

#include "leetcode/Base.h"

namespace {
    // Print the discovered registry entries so the runner stays self-documenting.
    void printUsage(const std::vector<std::string>& keys) {
        std::cout << "Usage: ./algorithm <problem-id>" << std::endl;
        std::cout << "Available problem ids:" << std::endl;
        for (const std::string& key: keys) {
            std::cout << "  " << key << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    const std::vector<std::string> keys = SolutionRegistry::instance().keys();

    if (argc != 2) {
        printUsage(keys);
        return 1;
    }

    const std::string problemId = argv[1];
    // Solutions self-register in their .cpp files, so lookup is data-driven here.
    std::unique_ptr<Base> solution = SolutionRegistry::instance().create(problemId);
    if (solution == nullptr) {
        std::cout << "Unknown problem id: " << problemId << std::endl;
        printUsage(keys);
        return 1;
    }

    solution->test();
    return 0;
}
