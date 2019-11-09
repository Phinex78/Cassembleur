/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** main
*/

#include "lib/header.h"

// int main (int argc, char **argv)
int main ()
{
    // char err_format[] =
    //         "The format to launch the Abstractvm isn't correct: ./abstractvm path/to/program.avm";
    char *cmd;
    char *type;
    double value;
    // Bool check_value;
    char *str = "add int8(124)";
    // path_to_file_t file_to_read;
    // file_to_read.path_to_file = argv[1];

    // if (argc != 2) {
    //     write (STDERR, err_format, my_strlen (err_format));
    //     return (0);
    // }
    cmd =  get_instruction (str);
    type = get_type (str);
    value = get_value (str);

    // Bool inst;
    // inst =  is_valid_value (type, value);

    // read_file(file_to_read.path_to_file);

    printf("%f\n", value);
    printf("%s\n", type);
    printf("%s\n", cmd);
    // printf("%i\n", inst);
    printf("%c", '\n');
    // check_value = is_valid_value (type, value);

    // if (check_value == true) {
    //     printf ("%s", "OK LA VALEUR EST BONNE");
    // } else {
    //     printf ("%s", "ZEUBI");
    // }
}