#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace {
    std::vector<std::string> discover_problem_ids() {
        std::vector<std::string> problem_ids;
        const std::filesystem::path leetcode_dir = std::filesystem::path(ALGORITHM_SOURCE_DIR) / "leetcode";

        for (const auto& entry : std::filesystem::directory_iterator(leetcode_dir)) {
            if (!entry.is_directory()) {
                continue;
            }

            const std::string name = entry.path().filename().string();
            if (!std::all_of(name.begin(), name.end(), ::isdigit)) {
                continue;
            }
            problem_ids.push_back(name);
        }

        std::sort(problem_ids.begin(), problem_ids.end());
        return problem_ids;
    }
}

int main() {
    const std::vector<std::string> problem_ids = discover_problem_ids();

    if (problem_ids.empty()) {
        std::cerr << "No problem directories were found under leetcode/" << '\n';
        return 1;
    }

    bool passed = true;
    const std::filesystem::path executable = std::filesystem::path(ALGORITHM_BINARY_PATH);
    for (const std::string& problem_id : problem_ids) {
        const std::string command = "\"" + executable.string() + "\" " + problem_id + " > /dev/null";
        const int exitCode = std::system(command.c_str());
        if (exitCode != 0) {
            std::cerr << "Failed to run problem id " << problem_id << '\n';
            passed = false;
        }
    }

    if (!passed) {
        return 1;
    }

    std::cout << "Validated " << problem_ids.size() << " solutions." << std::endl;
    return 0;
}
