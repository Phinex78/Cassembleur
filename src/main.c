/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** main
*/
#include "lib/header.h"

int main (int argc, char **argv)
{
    path_to_file_t file_to_read;
    file_to_read.path_to_file = argv[1];
    if (argc != 2) {
        write (STDERR, ERR_FORMAT, my_strlen (ERR_FORMAT));
        return 0;
    }

    Stack *st = new_stack ();
    read_file (file_to_read.path_to_file, st);
    free (st);
    return (0);
}