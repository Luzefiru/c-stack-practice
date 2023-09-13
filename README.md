# c-stack-practice

Different implementations of a stack data structure in C, inspired by JavaScript.

# Usage

```bash
git clone git@github.com:Luzefiru/c-stack-practice.git
cd c-stack-practice

make start # builds & runs the program
make clean # deletes build artifacts
```

You'll need to run `make start` in a Bash instance or use [GNUWin](https://gnuwin32.sourceforge.net/install.html) to add the `make` command to cmd.

- add makefile scripts and descriptions

# File Structure

> File directory structure follows the [pitchfork](https://github.com/vector-of-bool/pitchfork) convention used in big C++ and C projects.

```
Makefile              # build scripts
src/
├── main.c            # driver program
└── stack/
    ├── array/
    │   └── stack.c   # array implementation
    └── list/
        └── stack.c   # linked list implementation
include/
└── stack.h           # included header file with function prototypes & documentation
```

# Credits

- [C ASCII Color Escape Sequences](https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a)
- [C & C++ Pitchfork File Directory Structure Convention](https://github.com/vector-of-bool/pitchfork)
