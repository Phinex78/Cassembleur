/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** This is the main header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define MIN_INT8 -128
#define MAX_INT8 127
#define MIN_INT16 -32768
#define MAX_INT16 32767
#define MIN_INT32 -2147483648
#define MAX_INT32 2147483647
#define ERR_FORMAT                                                             \
    "The format to launch the Abstractvm isn't correct: ./abstractvm path/to/program.avm"

typedef enum { false, true } Bool;

typedef struct Element {
    int value;
    struct Element *next;
} Element, *Stack;

typedef struct path_to_file_s {
    char *path_to_file;
} path_to_file_t;

void read_file (char *path_to_file);
int my_strcmp (const char *s1, const char *s2);
char *my_strcpy (char *dest, const char *src);
int my_strlen (const char *str);
void my_putnbr (const int n);
void my_putchar (const char c);
Stack new_stack (void);
Stack push_stack (Stack stack, int value);
Stack pop_stack (Stack stack);
void dump_stack (Stack stack);
Bool is_empty_stack (Stack stack);
char *is_valid_type (char *type);
Bool is_valid_value (char *type, double value);
Bool is_valid_instruction1 (char *instruction);
Bool is_valid_instruction2 (char *instruction);
Bool is_valid_int8 (double value);
Bool is_valid_int16 (double value);
Bool is_valid_int32 (double value);
char *get_instruction (char *line);
char *get_type (char *line);
double get_value (char *line);
double my_atod (char *str);
#endif
