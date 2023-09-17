# c-stack-practice

Implementations of a stack data structure in C & Java.

<img src="demo.gif" />

# Usage

```bash
git clone git@github.com:Luzefiru/c-stack-practice.git
cd c-stack-practice

make             # builds & runs main.c based on the #include header

make start-java  # builds & runs the Java implementation
make clean       # deletes .o & .class build artifacts
```

You'll need to run `make start` in a Bash instance or use [GNUWin](https://gnuwin32.sourceforge.net/install.html) to add the `make` command to cmd.

### Changing the Implementation

The `#include ./src/<TYPE>/stack.h` determines the implementation used. In order to change it, just change the `<TYPE>` placeholder into any of the three:

- `array`
- `cursor`
- `list`

```c
// change directory for different implementation: array | cursor | list
// then run: make
#include "./list/stack.h"
#include <stdio.h>
```

# File Structure

> File directory structure follows the [pitchfork](https://github.com/vector-of-bool/pitchfork) convention used in big C++ and C projects.

```
Makefile              # build scripts
src/
├── main.c            # driver program
│
├── array/
│   └── stack.h       # array implementation
├── cursor/
│   └── stack.c       # cursor-based list implementation
│── list/
│   └── stack.c       # linked list implementation
│
└── java/             # Java implementation
    ├── Main.class    # Java driver program
    ├── Stack.class   # Stack class & method definitions
    └── IStack.class  # IStack interface imitating a header file
```

# Credits

- [C ASCII Color Escape Sequences](https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a)
- [C & C++ Pitchfork File Directory Structure Convention](https://github.com/vector-of-bool/pitchfork)
