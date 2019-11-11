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
    int dot_pos = 0;
    double sign = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        if (str[i] == '.')
            dot_pos = len - i - 1;
        else
            result = result * 10.0 + (str[i] - '0');
    }
    while (dot_pos--) {
        result /= 10.0;
    }
    return result * sign;
}

char *my_itoa (int integer)
{
    int flag = 0;
    char *str_int = malloc (sizeof (char) * (128 + 1));
    int i = 126;
    if (integer >= MAX_INT32 && integer <= MIN_INT32)
        return 0;
    if (integer < 0) {
        flag = 1;
        integer = -integer;
    }
    while (integer != 0) {
        str_int[i--] = (integer % 10) + '0';
        integer /= 10;
    }
    if (flag)
        str_int[i--] = '-';
    return str_int + i + 1;
    free (str_int);
}

char *my_dtoa (double num)
{
    int i = 0;
    int numI = (int)num;
    char *str = malloc (sizeof (char) * (1024 + 1));
    int tmp[1024];
    for (; numI / 10 != 0; i++) {
        tmp[i] = numI % 10;
        numI /= 10;
    }
    tmp[i] = numI;
    int j = 0;
    for (; i >= 0; i--)
        str[j++] = tmp[i] + '0';
    str[j++] = '.';
    for (i = 0; i < 3; i++) {
        num -= (int)num;
        num *= 10.0;
        str[j++] = num + '0';
    }
    return str;
    free (str);
}
