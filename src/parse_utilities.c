/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Utilities to parse intructions
*/

#include "lib/header.h"

Bool is_char_condition_true (char c)
{
    if (c != '\0' && c != ' ' && c != '\n' && c != ';')
        return true;
    return false;
}

Bool is_valid_instruction_with_value (char *instruction)
{
    for (int i = 0; i < INSTRUCTIONS_WITH_VALUE_SIZE; i++) {
        if (my_strcmp (instruction, INSTRUCTIONS_WITH_VALUE[i]) == 0)
            return true;
    };
    return false;
}

Bool is_valid_instruction (char *instruction)
{
    for (int i = 0; i < INSTRUCTIONS_SIZE; i++) {
        if (my_strcmp (instruction, INSTRUCTIONS[i]) == 0)
            return true;
    }

    if (is_valid_instruction_with_value (instruction))
        return true;

    return false;
}

Bool is_valid_type (char *type)
{
    for (int i = 0; i < TYPES_SIZE; i++) {
        if (my_strcmp (type, TYPES[i]))
            return true;
    }

    return false;
}

Bool is_valid_value (char *type, char *valueStr)
{
    double value = my_atod (valueStr);

    if (my_strcmp (type, "int8") == 0)
        if (is_valid_int8 (value))
            return true;
    if (my_strcmp (type, "int16") == 0)
        if (is_valid_int16 (value))
            return true;
    if (my_strcmp (type, "int32") == 0)
        if (is_valid_int32 (value))
            return true;
    if (my_strcmp (type, "double") == 0)
        return true;
    if (my_strcmp (type, "float") == 0)
        return true;

    return false;
}