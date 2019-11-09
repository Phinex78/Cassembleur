/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Utilities to parse intructions
*/

#include "lib/header.h"

Bool is_valid_line ()
{
    return false;
}

Bool is_valid_instruction_with_value (char *instruction)
{
    if (my_strcmp (instruction, "push") == 0) {
        return true;
    } else if (my_strcmp (instruction, "assert") == 0) {
        return true;
    }
    return false;
}

Bool is_valid_instruction1 (char *instruction)
{
    if (my_strcmp (instruction, "pop") == 0) {
        return true;
    } else if (my_strcmp (instruction, "add") == 0) {
        return true;
    } else if (my_strcmp (instruction, "sub") == 0) {
        return true;
    } else if (my_strcmp (instruction, "mul") == 0) {
        return true;
    } else if (my_strcmp (instruction, "div") == 0) {
        return true;
    } 
    return false;
}

Bool is_valid_instruction2(char *instruction)
{
    if (is_valid_instruction1(instruction) == true){
        return true;
    } else if ( my_strcmp (instruction, "mod") == 0) {
        return true;
    } else if (my_strcmp (instruction, "dump") == 0) {
        return true;
    } else if (my_strcmp (instruction, "print") == 0) {
        return true;
    } else if (my_strcmp (instruction, "exit") == 0) {
        return true;
    }
    return false;
}

char *is_valid_type(char *type){
     if (my_strcmp (type, "int8") == 0) {
        return "int8";
    } else if (my_strcmp (type, "int16") == 0) {
        return "int16";
    } else if (my_strcmp (type, "int32") == 0) {
        return "int32";
    } else if (my_strcmp (type, "float") == 0) {
        return "float";
    } else if (my_strcmp (type, "double") == 0) {
        return "double";
    } 
    return 0;
}

Bool is_valid_value (char *type, double value)
{
    if (my_strcmp( is_valid_type(type), "int8") == 0 && value >= MIN_INT8 && value <= MAX_INT8) {
        return true;
    } else if (my_strcmp( is_valid_type(type), "int16") == 0  && value >= MIN_INT16 &&
               value <= MAX_INT16) {
        return true;
    } else if (my_strcmp( is_valid_type(type), "int32") == 0  && value >= MIN_INT32 &&
               value <= MAX_INT32) {
        return true;
    } else if (my_strcmp( is_valid_type(type), "float") == 0 ) {
        return true;
    } else if (my_strcmp( is_valid_type(type), "double") == 0 ) {
        return true;
    }

    return false;
}