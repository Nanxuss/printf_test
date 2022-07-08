#include "_printf.h"

int main(void)
{
    char string_ex[] = "Example string";
/*     int integer_ex = -42069; */
    char char_ex = '?';
/*     float float_ex = 0.635;
    double double_ex = 9.11654; */
    
    _printf("This is a string: %s\n", string_ex);
/*     _printf("This is an integer: %d\n", integer_ex); */
    _printf("This is a char: %c\n", char_ex);
/*     _printf("This is a float: %.3f\n", float_ex);
    _printf("This is a double: %f\n", double_ex);
    _printf("This is conversion from decimal to hex: %x\n", integer_ex);
    _printf("This is conversion from decimal to octal: %o\n", integer_ex);
    _printf("This is conversion from decimal to binary: %b\n", integer_ex);
    _printf("This is a border case: %% \n"); */
    return (0);
}