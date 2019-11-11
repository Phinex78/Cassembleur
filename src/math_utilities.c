/*
** ETNA PROJECT, 2019
** math_utilities
** File description:
** This file contain 5 utilities to manage instructions
*/
#include "lib/header.h"

char *add(char *value1, char *value2) {

    double sum;

    sum = my_atod (value1) + my_atod(value2);

    return my_dtoa(sum);
}

char *sub(char *value1, char *value2)
{
    double sum;

    sum = my_atod (value1) - my_atod(value2);

    return my_dtoa(sum);
}

char *mul(char *value1, char *value2)
{
    double sum;

    sum = my_atod (value1) * my_atod(value2);

    return my_dtoa(sum);
}

char *divi(char *value1, char *value2)
{
    double sum;
    if (my_atod(value2) != 0 && my_atod(value2) > 0){
    sum = my_atod (value1) % my_atod(value2);

    return my_dtoa(sum);
    }
    return "can't div with 0";
}

char *mod(char *value1, char *value2)
{
    double sum;
    if (my_atod(value2) != 0 && my_atod(value2) > 0){
    sum = my_atod (value1) % my_atod(value2);

    return my_dtoa(sum);
    }
    return "can't div with 0";
}