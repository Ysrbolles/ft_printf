# ft_printf
This project is a copy of the original printf function of C langage.

This code complies with the 42 school norm: https://github.com/AnthonyLedru/norm/blob/master/norme.pdf

## Features

Supports all these converters, flags and modifiers:

 Type        | Name
------------ | -------------------------------------------------------------------------------
 Converters  |  %d / %s / %p / %d / %i / %o / %u / %x / %X / %c/ %%
 Flags       |  # / 0 / - / + / .
 Modifiers   |  hh / h / l / ll 


## Compilation

Run `make` command to compile the libftprintf library.

## Usage

Compile your project with libftprintf.a.
Don't forget to include "ft_printf.h"

To compile with the repository main:
```
gcc -Wall -Werror -Wextra main.c libftprintf.a -Iincludes/
```

## Subject

https://github.com/AnthonyLedru/ft_printf/blob/master/ft_printf.pdf
