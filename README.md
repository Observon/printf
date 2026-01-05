*This project has been created as part of the 42 curriculum by eride-ol.*

# ft_printf

## Description
The `./printf` directory hosts the `ft_printf` sources and builds the static library (`libftprintf.a`), a focused reimplementation of the standard `printf`.
Supported conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%%`.
Output is written directly with `write`, so it appears immediately; advanced flags, width, and precision from the libc `printf` are out of scope.

## Instructions
- **Build**: `cd printf && make`. This also builds the bundled `libft` dependency and produces `libftprintf.a` in the `./printf` directory.
- **Use in your project**: link against the library and include the header:
  - `cc your_code.c libftprintf.a `
- **Clean artifacts**: `make clean` removes objects, and `make fclean` removes the library (run inside `./printf`).
- **Rebuild from scratch**: `make re`.

## Algorithm and data structure choices
- `ft_printf` parses the format string sequentially, copying literal characters until it sees `%`.
- A dispatcher (`ft_handle_specifier`) maps each specifier to a dedicated printer that pulls the next variadic argument via `stdarg`.
- Numeric conversions share a recursive base writer (`ft_putnbr_base`) that walks digits from most significant to least using a constant base alphabet (e.g., lowercase or uppercase hex).
- Pointer rendering prefixes addresses with `0x` and emits `(nil)` for `NULL` pointers.
- Each helper returns the number of bytes written and propagates `-1` on error, mirroring `printf` failure semantics while avoiding extra data structures.

## Resources
- 42 subject overview.
- `man printf`, `man write`, and `man stdarg` for variadic semantics.
- Articles on recursive number printing in arbitrary bases for `%x`/`%X`/`%p`.
