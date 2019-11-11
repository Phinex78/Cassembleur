/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** main
*/
#include "lib/header.h"

int main ()
{
    char *value1= "11";
    char *value2 = "3";

    char *result = mod(value1, value2);
    printf("r : %s", result);
}