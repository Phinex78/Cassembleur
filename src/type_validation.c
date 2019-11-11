/*
** ETNA PROJECT, 2019
** type_validation
** File description:
** Verification utilities for types
*/

#include "lib/header.h"

int type_number (char *type)
{
    if (my_strcmp (type, "int8") == 0) {
        return 1;
    } else if (my_strcmp (type, "int16") == 0) {
        return 2;
    } else if (my_strcmp (type, "int32") == 0) {
        return 3;
    } else if (my_strcmp (type, "float") == 0) {
        return 4;
    } else if (my_strcmp (type, "double") == 0) {
        return 5;
    }
    return 0;
}

Bool is_valid_int8 (double value)
{
    int tested_value = (int)value;
    if (tested_value >= MIN_INT8 && tested_value <= MAX_INT8) {
        return true;
    }

    return false;
}

Bool is_valid_int16 (double value)
{
    int tested_value = (int)value;
    if (tested_value >= MIN_INT16 && tested_value <= MAX_INT16) {
        return true;
    }

    return false;
}

Bool is_valid_int32 (double value)
{
    int tested_value = (int)value;
    if (tested_value >= MIN_INT32 && tested_value <= MAX_INT32) {
        return true;
    }

    return false;
}