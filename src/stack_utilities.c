/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Those are doing basic actions on stack
*/

#include "lib/header.h"

Stack new_stack (void)
{
    return NULL;
}

Bool is_empty_stack (Stack stack)
{
    if (stack == NULL)
        return true;
    return false;
}

Stack push_stack (Stack stack, int x)
{
    Element *element;

    char no_alloc[]="Probleme allocation dynamique.\n";
    element = malloc (sizeof (*element));

    if (element == NULL) {
        write (STDOUT, no_alloc, my_strlen (no_alloc));
        exit (EXIT_FAILURE);
    }

    element->value = x;
    element->next = stack;

    return element;
}

Stack pop_stack (Stack stack)
{
    Element *element;

    if (is_empty_stack (stack))
        return new_stack ();

    element = stack->next;
    free (stack);

    return element;
}

void dump_stack (Stack stack)
{
    char nothing_to_show[]="Rien a afficher, la Pile est vide.\n";
    if (is_empty_stack (stack)) {
        write (STDOUT, nothing_to_show, my_strlen (nothing_to_show));
        return;
    }

    while (!is_empty_stack (stack)) {
        stack = stack->next;
    }
}