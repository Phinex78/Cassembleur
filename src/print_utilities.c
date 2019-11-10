/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Print utilities without printf ...
*/
#include "lib/header.h"

void print_error (char *error, int line_number)
{
    write (STDOUT, error, my_strlen (error));
    write (STDOUT, LINE, my_strlen (LINE));
    my_putnbr (line_number);
    write (STDOUT, "\n", 1);
}