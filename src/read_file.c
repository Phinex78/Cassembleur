/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** Read a file with open
*/

#include "lib/header.h"

void read_file (char *path_to_file)
{
    char buffer[1024 + 1];
    int bytes_read = 0;
    printf ("%s", buffer);
    printf ("%i", bytes_read);
    int k = 0;
    int fd;
    fd = open (path_to_file, O_RDONLY);
    if (fd == -1) {
        printf ("%s", "Erreur de lecture du fichier");
    }
    for (int i = 0; i < 1025; i++) {
        char t = 0;
        bytes_read = read (fd, &t, 1);
        buffer[k++] = t;
        printf ("%c", t);
    }
}