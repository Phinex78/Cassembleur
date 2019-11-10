/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Those are doing basic actions on stack
*/

#include "lib/header.h"

Stack *new_stack (void)
{
    Stack *stack = malloc (sizeof (*stack));
    Element *element = malloc (sizeof (*element));

    if (stack == NULL || element == NULL) {
        exit (EXIT_FAILURE);
    }

    element->instruction = NULL;
    element->type = NULL;
    element->value = NULL;
    element->next = NULL;
    stack->first = element;

    return stack;
}

void push_value (Stack *stack, char *instruction, char *type, char *value)
{
    Element *newElement = malloc (sizeof (*newElement));
    if (newElement == NULL) {
        write (1, ERR_NO_ALLOC, my_strlen (ERR_NO_ALLOC));
        exit (EXIT_FAILURE);
    }

    newElement->instruction = instruction;
    newElement->type = type;
    newElement->value = value;
    newElement->next = stack->first;
    stack->first = newElement;
}

char *pop_element (Stack *stack)
{
    Element *toDelete = stack->first;
    if (stack == NULL) {
        exit (EXIT_FAILURE);
    }

    char *value = 0;

    if (stack->first != NULL) {
        value = toDelete->value;
        stack->first = toDelete->next;
        free (toDelete);
    }

    return value;
}

void dump_stack (Stack *stack)
{
    Element *element = stack->first;

    if (stack == NULL) {
        write (STDOUT, NOTHING_TO_SHOW, my_strlen (NOTHING_TO_SHOW));
        exit (EXIT_FAILURE);
    }

    while (element->instruction != NULL) {
        write (1, "=======Element=======", my_strlen ("=======Element======="));
        write (1, "\n", 1);
        write (1, element->instruction, my_strlen (element->instruction));
        write (1, "\n", 1);
        write (1, element->type, my_strlen (element->type));
        write (1, "\n", 1);
        write (1, element->value, my_strlen (element->value));
        write (1, "\n", 1);
        element = element->next;
    }
}

void assert_value (Stack *stack, char *value)
{
    Element *element = stack->first;
    double assert_value_converted = my_atod (value);
    double element_value_converted = my_atod (element->value);
    if (assert_value_converted == element_value_converted) {
        write (STDOUT, ASSERT_OK, my_strlen (ASSERT_OK));
    } else {
        write (STDOUT, ASSERT_KO, my_strlen (ASSERT_KO));
    }
};