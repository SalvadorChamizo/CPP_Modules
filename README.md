# CPP_Modules

Short collection of focused C++ exercises (Module_00–Module_09) that demonstrate core and intermediate C++ concepts: object-oriented design, memory management (RAII), templates, STL usage, file I/O, and small CLI utilities. Each exercise is self-contained and built with a Makefile to support incremental evaluation.

## Key Features

- Implement and validate core C++ concepts (classes, copy semantics, exceptions, RAII).
- Build and run individual exercises via Makefiles (consistent `all`, `clean`, `fclean`, `re` targets).
- Hands-on utilities and algorithms: CLI tools (PhoneBook, RPN), file parsers (BitcoinExchange), algorithmic exercises (PmergeMe), and template utilities (MutantStack, Span).
- Focus on correctness, exception safety, and memory safety (intended to be checked with valgrind or sanitizers).
- Small, independent exercises suitable for technical assessment and interview demos.

## Tech Stack

- Language: **C++** (many exercises target C++98; some are compatible with later standards)
- Compiler: **g++ (GNU GCC)**
- Build: **Make** (per-exercise Makefiles)
- Libraries: **STL** (vector, list, stack, deque, algorithms), standard I/O and file streams
- Tools: **gdb**, **valgrind**, **clang-tidy** (recommended)
- Platform: POSIX-compatible systems (Linux/macOS assumed)

## Architecture & Design

The repository is organized by module and exercise (`Module_XX/exYY`). Each exercise is intentionally small and focused, typically containing a header (`.hpp`), implementation (`.cpp`), and a `Makefile`.

Design principles emphasized:

- Separation of interface and implementation
- Rule of Three/Five and RAII for resource management
- Explicit error handling and custom exception types
- Reusable templates and iterator-aware utilities

## Getting Started

### Prerequisites

- POSIX-compatible shell (Linux or macOS)
- `g++` (GNU C++) and `make`
- Optional: `valgrind` or AddressSanitizer for memory checks

### Installation

Clone the repository (or use your local copy):

```sh
git clone <repo-url>
cd CPP_Modules
```

Build a specific exercise (example):

```sh
cd Module_00/ex01
make
```

Most exercise folders include `Makefile` targets: `all`, `clean`, `fclean`, `re`.

### Running the project

After running `make`, execute the produced binary in the exercise folder:

```sh
# Example (replace <executable> with the produced binary)
./<executable>
```

For file-based utilities, pass input files as documented in the exercise's `main.cpp` or comments (for example, `BitcoinExchange` expects a data input file).

## Usage

- Interactive programs: run the compiled binary and follow on-screen prompts (see each exercise's `main.cpp` for examples).
- File-based utilities: provide an input file path as a command-line argument where applicable.
- Library-style/template exercises: inspect and run the included `main.cpp` examples for API usage.

Tip: Use `make clean` then `make` in an exercise folder to rebuild after changes. Run `valgrind ./<executable>` or build with sanitizers for memory/error checks.

## What I Learned / Technical Challenges

- Proper application of the Rule of Three/Five and correct copy/move semantics
- Designing exception-safe interfaces and meaningful custom exceptions
- Implementing efficient, correct algorithms and measuring performance
- Robust input parsing and defensive programming to handle malformed data
- Using templates to create generic, iterator-aware utilities

## Future Improvements

- Add automated unit tests and CI (GitHub Actions) for continuous validation
- Consolidate builds with CMake for cross-platform consistency
- Add static analysis, sanitizers, and coverage reporting in CI
- Provide modernized C++ variants (C++17/C++20) with feature flags where useful

## Author & Contact

**schamizo** — salvadorchamizo@gmail.com

---

Assumptions: the repository targets POSIX systems and uses `g++` and Make for builds. If you want, I can add a top-level `Makefile` to build selected exercises or draft a GitHub Actions workflow for CI and static analysis.