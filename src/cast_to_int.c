/*
** ETNA PROJECT, 2019
** cast_to_int
** File description:
** Cast double to int
*/
#include "lib/header.h"

char *cast_to_int (char *value)
{
    double tmp_double;
    char *result;
    tmp_double = my_atod (value);
    result = my_itoa ((int)tmp_double);
    return result;
}