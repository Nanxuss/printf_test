#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    char string_ex[] = "Example string";
    int integer_ex = 420;
    char char_ex = '?';
    float float_ex = 0.635;
    double double_ex = 9.11654;
    int hex_ex = 653;
    int oct_ex = 653;
    int bin_ex = 653;
    
    _printf("This is a string: %s\n", string_ex);
    _printf("This is an integer: %d\n", integer_ex);
    _printf("This is a char: %c\n", char_ex);
    _printf("This is a float: %.3f\n", float_ex);
    _printf("This is a double: %f\n", double_ex);
    _printf("This is conversion from decimal to hex: %x\n", hex_ex);
    _printf("This is conversion from decimal to octal: %o\n", oct_ex);
    _printf("This is conversion from decimal to binary: %b\n", bin_ex);
    _printf("This is a border case: %%");
}