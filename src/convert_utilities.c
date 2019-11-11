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
char *my_itoa(int integer)
{
    int flag = 0;
    char *str = malloc (sizeof (char) * (128 + 1));
    int i = 126;
    // if (integer > MAX_INT32 && integer < MIN_INT32)
    //     return 0;
    if (integer < 0) {
        flag = 1;
        integer = -integer;
    }
    while (integer != 0) {
        str[i--] = (integer % 10) + '0';
        integer /= 10;
    }
    if (flag)
        str[i--] = '-';

    return str + i + 1;
}

char *my_dtoa (double num)
{
    int i = 0;
    int numI = (int)num;
    char *str = malloc (sizeof (char) * (BUFSIZ + 1));
    int tmp[BUFSIZ];
    for (; numI / 10 != 0; i++) {
        tmp[i] = numI % 10;
        numI /= 10;
    }
    tmp[i] = numI;
    int j = 0;
    for (; i >= 0; i--)
        str[j++] = tmp[i] + '0';
    str[j++] = '.';
    num -= (int)num;
    for (i = 0; i < 6; i++) {
        num *= 10;
        str[j++] = (int)num + '0';
        num -= (int)num;
    }
    return str;
}