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

// int my_putstr(char *str)
// {
//     if (*str != '\0')
//     {
//       my_putchar(*str);
//       my_putstr(str + 1);
//     }

// }

void swap(char *x, char *y) {
	char t = *x; *x = *y; *y = t;
}

char* reverse(char *buffer, int i, int j)
{
	while (i < j)
		swap(&buffer[i++], &buffer[j--]);

	return buffer;
}

char* itoamoi(int value, char* buffer, int type)
{
	if (type < 2 || type > 32)
		return buffer;

	int n = abs(value);

	int i = 0;
	while (n)
	{
		int r = n % type;

		if (r >= 10) 
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / type;
	}

	if (i == 0)
		buffer[i++] = '0';


	if (value < 0 && type == 10)
		buffer[i++] = '-';

	buffer[i] = '\0'; 
	return reverse(buffer, 0, i - 1);
}

