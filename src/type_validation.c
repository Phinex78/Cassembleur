/*
** ETNA PROJECT, 2019
** type_validation
** File description:
** Verification utilities for types
*/

#include "lib/header.h"

Bool is_valid_int8 (double value)
{
    if (value >= MIN_INT8 && value <= MAX_INT8) {
        int testedVal = (int)value;
        if (testedVal == value)
            return true;
    }

    return false;
}

Bool is_valid_int16 (double value)
{
    if (value >= MIN_INT16 && value <= MAX_INT16) {
        int testedVal = (int)value;
        if (testedVal == value)
            return true;
    }

    return false;
}

Bool is_valid_int32 (double value)
{
    if (value >= MIN_INT32 && value <= MAX_INT32) {
        int testedVal = (int)value;
        if (testedVal == value)
            return true;
    }

    return false;
}