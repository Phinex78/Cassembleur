/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Read a file with open
*/

#include "lib/header.h"

void read_file (char *path_to_file, Stack *stack)
{
    char *line = malloc (4096 + 1);
    int k = 0;
    char t = 0;
    int line_number = 0;
    int fd = open (path_to_file, O_RDONLY);
    if (fd == -1)
        write (STDERR, ERR_OPEN, my_strlen (ERR_OPEN));
    for (int i = 0; i < 4097; i++) {
        read (fd, &t, 1);
        line[k++] = t;
        if (t == '\n') {
            line_number++;
            line[k] = '\0';
            parse_line (line, stack, line_number);
            for (int j = 0; j < k; j++)
                line[j] = '\0';
            k = 0;
        }
    }
    free (line);
}
