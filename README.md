# daily-algorithm

This repository contains C++ solutions for algorithm problems, currently organized around LeetCode problem IDs.
Each problem is implemented as a small class under `leetcode/<problem-id>/`, and the project is built as a single CMake executable for quick local testing.

## Overview

- Language: C++
- Build system: CMake
- Main executable: `algorithm`
- Current workflow: add a problem class, register it in its `.cpp` file, rebuild, and run it by problem id

The codebase is set up for iterative problem solving rather than as a reusable library. Each solution class usually contains:

- the core algorithm method for the problem
- a lightweight `test()` entry point for local verification
- a small self-registration hook so `main.cpp` can discover it automatically

## Build And Run

### Option 1: Build with CMake manually

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
./cmake-build-debug/algorithm 3488
```

### Option 2: Use an IDE with CMake support

This repository also works well with CLion or other IDEs that understand `CMakeLists.txt`. The existing `cmake-build-debug/` directory suggests that is the current local workflow.

## Repository Structure

```text
.
├── CMakeLists.txt
├── main.cpp
├── README.md
└── leetcode
    ├── Base.h
    ├── 3488/
    ├── 3573/
    └── 3650/
```

### Key Files

- `CMakeLists.txt`: defines the `algorithm` executable and auto-discovers files under `leetcode/`
- `main.cpp`: looks up a solution by problem id and runs its `test()` method
- `leetcode/Base.h`: defines the shared base class plus the solution registry used by the runner
- `leetcode/<problem-id>/`: contains one problem per folder, typically with a `.h` and `.cpp` pair

## LeetCode Folder Convention

Each problem lives in its own folder named after the LeetCode problem ID:

```text
leetcode/
└── 3488/
    ├── ClosetEqualElementQueries.h
    └── ClosetEqualElementQueries.cpp
```

Typical pattern:

1. Declare a solution class in the header file.
2. Inherit from `Base`.
3. Implement the algorithm method in the `.cpp` file.
4. Implement `void test() override;` for local verification.
5. Register the solution in the `.cpp` file with a `SolutionRegistrar`.

Example shape:

```cpp
class SomeProblem : public Base {
public:
    int solve(...);
    void test() override;
};
```

## `test()` Entry Points

`Base` defines a virtual `test()` method, and each problem class can override it to provide local test cases.

Current execution flow:

1. Each solution registers itself with a problem id.
2. `main.cpp` reads the target problem id from the command line.
3. The runner creates that solution instance and calls `solution.test()`.
4. The selected problem prints results directly to standard output.

This keeps local verification simple without requiring per-problem edits to `main.cpp`.

### To run a different problem

```bash
./cmake-build-debug/algorithm <problem-id>
```

Example:

```bash
./cmake-build-debug/algorithm 3573
```

## Adding A New Problem

To add a new LeetCode solution:

1. Create a new folder under `leetcode/<problem-id>/`.
2. Add the corresponding `.h` and `.cpp` files.
3. Inherit the class from `Base`.
4. Declare and implement `void test() override;`.
5. Register the solution in the `.cpp` file using `REGISTER_LEETCODE_SOLUTION`.
6. Rebuild and run `./cmake-build-debug/algorithm <problem-id>`.

Example registration:

```cpp
REGISTER_LEETCODE_SOLUTION("1234", leetcode::SomeProblem);
```

## Notes

- `CMakeLists.txt` now auto-discovers files under `leetcode/`, so new solution files do not need to be added manually.
- The project builds all registered solution files into a single executable.
- If a `.cpp` file defines `ClassName::test()`, the header must also declare `void test() override;`.
- Local tests are intentionally lightweight and stdout-based, which is convenient for daily practice and debugging.
