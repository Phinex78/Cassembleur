/*
** ETNA PROJECT, 2019
** instruction_utilities
** File description:
** This file contain 5 utilities to manage instructions
*/
#include "lib/header.h"

void manage_instruction (Stack *stack, char *instruction)
{
    if (my_strcmp (instruction, "dump") == 0) {
        dump_stack (stack);
    } else if (my_strcmp (instruction, "print") == 0) {
        print_top_value (stack);
    } else if (my_strcmp (instruction, "pop") == 0) {
        print_top_value (stack);
    }
}

void print_top_value (Stack *stack)
{
    Element *element = stack->first;
    if (my_strcmp (element->value, "int8") == 1) {
        write (STDOUT, BAD_PRINT_TYPE, my_strlen (BAD_PRINT_TYPE));
    } else {
    }
}
