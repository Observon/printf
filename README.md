# ft_printf

![C](https://img.shields.io/badge/Language-C-00599C?logo=c&logoColor=white)
![42 School](https://img.shields.io/badge/School-42-000000?logo=42&logoColor=white)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen)
![Compiler](https://img.shields.io/badge/Compiler-cc%20-Wall%20-Wextra%20-Werror-blue)
![Status](https://img.shields.io/badge/Status-Complete-success)

This repository is a public version of the **ft_printf** project developed in the 42 curriculum by eride-ol.

It showcases a fundamental milestone in the program, focused on validating **string parsing logic**, **variadic function design**, **type conversion fundamentals**, and **low-level C programming** under strict guidelines.

## Description

ft_printf is a lightweight reimplementation of the standard `printf()` function in C. The project validates understanding of:

- **Variadic functions and argument handling** (`stdarg.h`)
- **String parsing and state-machine logic** for format string interpretation
- **Type conversion and base conversion algorithms** (binary manipulations for hex/octal/decimal)
- **Modular architecture** with single-responsibility functions for each specifier
- **Error handling and edge case management** (NULL pointers, negative numbers, overflow)
- **I/O operations** using low-level `write()` system calls

The program outputs a precise byte count matching `printf` semantics, including `-1` on error.

## Quick View for Recruiters

### Why this project matters

Within the 42 curriculum, ft_printf is a **foundational exercise** that validates:
- Ability to break down a complex problem (parsing + dispatching + conversion) into modular, testable pieces
- Deep understanding of C fundamentals: variadic functions, memory layout, type conversions
- Attention to specification details and edge cases
- Clean code organization and efficiency considerations

### Skills demonstrated

- **Parsing logic**: Single-pass format string interpretation with state tracking
- **Design patterns**: Dispatcher pattern for specifier-to-handler mapping
- **Algorithms**: Recursive base conversion (works for any radix, not just 10)
- **Low-level programming**: `write()` system calls, pointer arithmetic, type casting
- **Error handling**: Defensive validation and consistent error propagation
- **Code organization**: Modular structure with each specifier in its own file

## Supported Conversions

| Specifier | Type | Behavior |
|-----------|------|----------|
| `%c` | Character | Outputs single character |
| `%s` | String | Outputs string, prints `(null)` for NULL pointer |
| `%p` | Pointer | Outputs address in hex with `0x` prefix, prints `(nil)` for NULL |
| `%d` | Signed int | Outputs decimal integer (including negative sign) |
| `%i` | Signed int | Identical to `%d` |
| `%u` | Unsigned int | Outputs unsigned decimal integer |
| `%x` | Hex (lowercase) | Outputs hexadecimal with lowercase a-f |
| `%X` | Hex (uppercase) | Outputs hexadecimal with uppercase A-F |
| `%%` | Literal % | Outputs single `%` character |

Return value: Number of bytes written, or `-1` on error (mirroring `printf` semantics)

## Compilation and Usage

```bash
# Compile the library
cd printf && make

# Use in your project
cc your_code.c libftprintf.a -I.

# Clean build artifacts
make clean      # Remove object files
make fclean     # Remove object files and library
make re         # Clean and recompile
```

Note: Uses `cc` compiler with flags `-Wall -Wextra -Werror`. Automatically compiles `libft/libft.a` as a dependency.

### Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");           // "Hello World!\n"
    ft_printf("Number: %d, Hex: %x\n", 42, 42);  // "Number: 42, Hex: 2a\n"
    ft_printf("Pointer: %p\n", (void *)NULL);     // "Pointer: (nil)\n"
    ft_printf("%c%c%c\n", 'A', 'B', 'C');         // "ABC\n"
    return 0;
}
```


## Technical Implementation

### Data Flow

```
Format String
    ↓
[Parse/Scan] → Detect '%' or literal character
    ↓
  If '%': Extract specifier character
    ↓
[Dispatch] → ft_handle_specifier() routes to appropriate handler
    ↓
[Convert] → Handler extracts argument via va_arg() and transforms it
    ↓
[Output] → write() sends bytes to stdout
    ↓
[Count] → Return bytes written (or -1 on error)
```

### Code Organization

**Core Processing:**
- `ft_printf.c` - Main entry point, argument list initialization, format string iteration
- `ft_printf_utils.c` - Shared utilities: byte-counting write, generic base conversion
- `ft_handle_specifier()` - Dispatcher mapping specifiers to handlers

**Specifier Handlers (one file per conversion type):**
- `ft_print_char.c` - `%c` handler
- `ft_print_string.c` - `%s` handler  
- `ft_print_pointer.c` - `%p` handler (includes `0x` prefix and NULL handling)
- `ft_print_number.c` - `%d` / `%i` handler (handles sign, calls base converter)
- `ft_print_unsigned.c` - `%u` handler
- `ft_print_hex.c` - `%x` / `%X` handler (delegates to base converter with hex alphabet)

**Supporting Infrastructure:**
- `ft_printf.h` - Function declarations and includes
- `libft/` - Utility library (strlen, memory operations, etc.)

### Key Algorithms

**Recursive Base Conversion** (`ft_putnbr_base`)

Handles decimal, hexadecimal, and any base 2-36:

```
ft_putnbr_base(n=42, base="0123456789abcdef"):
  42 >= 16 → recurse with 42/16 = 2
    2 >= 16 → false, output base[2] = '2'
  output base[42 % 16] = base[10] = 'a'
  Result: "2a"
```

Advantages:
- Single function handles all radix conversions
- Efficient (no string building, direct output via `write()`)
- Scalable to any numeric base

**Format String Parser**

Simple state machine:
1. Scan character
2. If `%` and next char exists: extract specifier, dispatch handler
3. If literal character: output directly
4. Continue until null terminator

Error propagation: Any handler returning `-1` immediately returns `-1` to caller.

### Design Decisions

| Decision | Rationale |
|----------|-----------|
| **Separate handler files** | Single responsibility, easier testing and modification |
| **Recursive base converter** | Works for any base, avoids string operations, efficient |
| **Dispatcher pattern** | Cleanly separates parsing from type-specific logic |
| **Direct `write()` usage** | Low overhead, matches printf semantics, shows system-level understanding |
| **Consistent error `-1`** | Matches libc convention, enables upstream error detection |

## Concepts Demonstrated

- **Variadic Functions** (`stdarg.h`): Safe handling of variable argument lists with type safety via specifiers
- **String Parsing**: State machine logic for interpreting format strings and extracting specifiers
- **Algebraic Base Conversion**: Recursive algorithm for converting numbers to any radix (decimal, hex, octal, etc.)
- **Pointer Arithmetic and Type Casting**: Safe navigation and reinterpretation of generic pointers
- **Edge Case Handling**: NULL pointers, negative number signs, integer overflow scenarios
- **Modular Design**: Clear separation of concerns across files for maintainability
- **System-Level Programming**: Direct use of `write()` syscall, understanding of stdout buffering
- **Error Propagation**: Consistent error semantics matching standard library conventions

## How This Project Connects to Career Growth

### For Junior Developer Roles (Python/FastAPI/React stack)

This project demonstrates **foundational thinking** that transfers across languages:
- ✅ **Problem decomposition**: Breaking format string parsing into independent handlers
- ✅ **Algorithm design**: Implementing recursive conversion instead of naive string building
- ✅ **Low-level understanding**: Knowing how data flows at the byte level informs higher-level decisions
- ✅ **Testing mindset**: Each handler is independently testable and verifiable

### For Internship Positions

This code proves **rapid learning and fundamentals**:
- ✅ **Curiosity**: Understanding variadic functions and system calls beyond "hello world"
- ✅ **Structured thinking**: Clear modular organization from the start
- ✅ **Data structures**: Competent use of pointers, linked lists (via libft)
- ✅ **Algorithmic thinking**: Choosing efficient algorithms (recursion vs. iteration, base conversion method)
- ✅ **Attention to detail**: Proper error handling, NULL checks, specification compliance

## About 42 School

This project was developed as part of the **[42 School](https://42.fr/)** curriculum, an internationally recognized coding bootcamp with a unique peer-learning model. The 42 approach:

- ❌ **No traditional lectures** — Learning through project-based challenges and peer collaboration
- ✅ **Rigorous standards** — Projects must compile without warnings and meet strict specifications
- ✅ **Skill-based progression** — Each project builds on previous fundamentals
- ✅ **Real problem-solving** — Code must work, not just compile

**Why recruiters value 42 graduates:**
- Proven self-directed learning ability
- Comfort with low-level programming and systems concepts
- High standards for code quality and correctness
- Ability to tackle complex problems independently

## Resources & References

**Official 42 Resources:**
- 42 School ft_printf Project Specification
- 42 School Curriculum Structure & Progression

**Standard C Documentation:**
- `man printf` — Printf format and behavior specification
- `man write` — Low-level I/O system call semantics  
- `man stdarg` — Variadic function macros and usage patterns

**Learning References:**
- "The C Programming Language" (Kernighan & Ritchie) — Definitive C reference
- Data Structures and Algorithm Analysis in C (Weiss) — Algorithms and complexity
- Introduction to Algorithms (Cormen et al.) — Algorithm design principles

## Notes

- This is a **public portfolio version** of a 42 curriculum project
- Original 42 style constraints (Makefile, C naming conventions, libft dependency) preserved for authenticity
- Tested on Linux/macOS with `cc` compiler
- Available for reference, study, and portfolio demonstration

---

**Developed as a fundamentalist C programming exercise showcasing parsing, type conversion, and modular design.**
