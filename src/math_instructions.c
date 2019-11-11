/*
** ETNA PROJECT, 2019
** math_instruction
** File description:
** This file contain 5 fonction to make math instrucitons
*/
#include "lib/header.h"

void add_stack (Stack *stack)
{
    Element *element1 = stack->first;
    char *element1_type = element1->type;
    int type1 = type_number (element1_type);
    char *value1 = pop_element (stack);

    Element *element2 = stack->first;
    char *element2_type = element2->type;
    int type2 = type_number (element2_type);
    char *value2 = pop_element (stack);

    char *result = add (value1, value2);

    if (type1 < 4 && type2 < 4)
        result = cast_to_int (result);

    if (type1 >= type2) {
        push_value_stack (stack, "push", element1_type, result);
    } else {
        push_value_stack (stack, "push", element2_type, result);
    }
}

void sub_stack (Stack *stack)
{
    Element *element1 = stack->first;
    char *element1_type = element1->type;
    int type1 = type_number (element1_type);
    char *value1 = pop_element (stack);

    Element *element2 = stack->first;
    char *element2_type = element2->type;
    int type2 = type_number (element2_type);
    char *value2 = pop_element (stack);

    char *result = sub (value1, value2);
    if (type1 < 4 && type2 < 4)
        result = cast_to_int (result);
    if (type1 >= type2) {
        push_value_stack (stack, "push", element1_type, result);
    } else {
        push_value_stack (stack, "push", element2_type, result);
    }
}
void mul_stack (Stack *stack)
{
    Element *element1 = stack->first;
    char *element1_type = element1->type;
    int type1 = type_number (element1_type);
    char *value1 = pop_element (stack);

    Element *element2 = stack->first;
    char *element2_type = element2->type;
    int type2 = type_number (element2_type);
    char *value2 = pop_element (stack);

    char *result = mul (value1, value2);

    if (type1 < 4 && type2 < 4)
        result = cast_to_int (result);
    if (type1 >= type2) {
        push_value_stack (stack, "push", element1_type, result);
    } else {
        push_value_stack (stack, "push", element2_type, result);
    }
}

void div_stack (Stack *stack)
{
    Element *element1 = stack->first;
    char *element1_type = element1->type;
    int type1 = type_number (element1_type);
    char *value1 = pop_element (stack);

    Element *element2 = stack->first;
    char *element2_type = element2->type;
    int type2 = type_number (element2_type);
    char *value2 = pop_element (stack);

    char *result = divi (value1, value2);

    if (type1 < 4 && type2 < 4)
        result = cast_to_int (result);
    if (type1 >= type2) {
        push_value_stack (stack, "push", element1_type, result);
    } else {
        push_value_stack (stack, "push", element2_type, result);
    }
}

void mod_stack (Stack *stack)
{
    Element *element1 = stack->first;
    char *element1_type = element1->type;
    int type1 = type_number (element1_type);
    char *value1 = pop_element (stack);

    Element *element2 = stack->first;
    char *element2_type = element2->type;
    int type2 = type_number (element2_type);
    char *value2 = pop_element (stack);

    char *result = mod (value1, value2);

    if (type1 < 4 && type2 < 4)
        result = cast_to_int (result);
    if (type1 >= type2) {
        push_value_stack (stack, "push", element1_type, result);
    } else {
        push_value_stack (stack, "push", element2_type, result);
    }
}