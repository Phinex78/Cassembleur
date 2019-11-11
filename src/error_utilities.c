/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Print utilities without printf ...
*/
#include "lib/header.h"

char *valid_type (char *type, char *valueStr, int line_number)
{
    if (is_valid_value (type, valueStr)) {
        return valueStr;
    } else {
        print_error (BAD_INSTRUCTION, line_number);
        return BAD_TYPE;
    }
}

void print_error (char *error, int line_number)
{
    write (STDOUT, error, my_strlen (error));
    write (STDOUT, LINE, my_strlen (LINE));
    my_putnbr (line_number);
    write (STDOUT, "\n", 1);
}