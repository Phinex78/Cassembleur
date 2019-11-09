/*
** ETNA, 2019
** AbstractVM
** File description:
**     String utilities
*/
#include "lib/header.h"

int my_strcmp (const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

char *my_strcpy (char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strlen (const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void my_putchar (const char c)
{
    write (1, &c, 1);
}

void my_putnbr (const int n)
{
    long nb = n;
    long number = 1;

    if (nb == 0)
        my_putchar ((nb % 10) + 48);
    if (nb < 0) {
        my_putchar ('-');
        nb *= -1;
    }
    while (nb > 0) {
        number = number * 10 + (nb % 10);
        nb /= 10;
    }
    while (number > 1) {
        my_putchar ((number % 10) + 48);
        number /= 10;
    }
}
