/*
** ETNA PROJECT, 2019
** convert_utilities.c
** File description:
** Functions to convert strings to number
*/

#include "lib/header.h"

double my_atod (char *str)
{
    double result = 0.0;
    int len = strlen (str);
    int dotPos = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            dotPos = len - i - 1;
        } else {
            result = result * 10.0 + (str[i] - '0');
        }
    }

    while (dotPos--) {
        result /= 10.0;
    }

    return result;
}