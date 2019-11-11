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
        pop_element (stack);
    } else if (my_strcmp (instruction, "exit") == 0) {
        exit (0);
    } else {
        manage_math_operations (stack, instruction);
    }
}

void manage_math_operations (Stack *stack, char *instruction)
{
    if (my_strcmp (instruction, "add") == 0) {
        add_stack (stack);
    } else if (my_strcmp (instruction, "sub") == 0) {
        sub_stack (stack);
    } else if (my_strcmp (instruction, "mul") == 0) {
        mul_stack (stack);
    } else if (my_strcmp (instruction, "div") == 0) {
        div_stack (stack);
    } else if (my_strcmp (instruction, "mod") == 0) {
        mod_stack (stack);
    }
}

void print_top_value (Stack *stack)
{
    Element *element = stack->first;
    char *value = element->value;
    char result = 0;
    int tab_size = my_strlen (value);
    if (my_strcmp (element->type, "int8") == 0) {
        write (STDOUT, TOP_INT8_ASCII, my_strlen (TOP_INT8_ASCII));
        for (int i = 0; i < tab_size; i++) {
            my_putnbr (result + value[i]);
            write (STDOUT, " ", 1);
        }
        write (STDOUT, "\n", 1);
    } else {
        write (STDOUT, BAD_TOP_TYPE, my_strlen (BAD_TOP_TYPE));
    }
}
