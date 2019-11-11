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
    int len = my_strlen (str);
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

// char *my_atod_reverse (double dbl)
// {
//     char *result;
//     my_putstr(dbl);
//     return dbl;

//     int len = my_strlen (dbl);
//     int dotPos = 0;

//     for (int i = 0; i < len; i++) {
//         if (dbl[i] == '.') {
//             dotPos = len - i - 1;
//         } else {
//             *result = *result * 10.0 + (dbl[i] - '0');
//         }
//     }

//     while (dotPos--) {
//         *result /= 10.0;
//     }

//     return *result;
// }