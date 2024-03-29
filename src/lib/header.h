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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define INSTRUCTIONS_WITH_VALUE_SIZE 2
#define INSTRUCTIONS_WITH_VALUE                                                \
    (const char * [2])                                                         \
    {                                                                          \
        "assert", "push"                                                       \
    }
#define INSTRUCTIONS_SIZE 9
#define INSTRUCTIONS                                                           \
    (const char * [9])                                                         \
    {                                                                          \
        "pop", "add", "mul", "sub", "div", "mod", "dump", "print", "exit"      \
    }
#define TYPES_SIZE 5
#define TYPES                                                                  \
    (const char * [5])                                                         \
    {                                                                          \
        "int8", "int16", "int32", "float", "double"                            \
    }
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
    "The format to launch the Abstractvm isn't correct: ./abstractvm path/to/program.avm.\n"
#define ERR_OPEN "Erreur de lecture du fichier.\n"
#define ERR_NO_ALLOC "Probleme allocation dynamique.\n"
#define BAD_INSTRUCTION "Erreur instruction invalide. "
#define BAD_TYPE "Erreur type invalide. "
#define BAD_VALUE "Erreur valeur invalide. "
#define LINE "Ligne: "
#define BAD_TOP_TYPE "Le type en haut de la pile n'est pas un int8. \n"
#define TOP_INT8_ASCII "La valeur ASCII du int8 en haut de la pile est: "
#define ASSERT_OK "La valeur en haut de pile est égale à la valeur de assert.\n"
#define ASSERT_KO "La valeur haut de pile n'est pas égale à la valeur assert.\n"
#define NOTHING_TO_SHOW "La pile est vide.\n"

typedef enum { false, true } Bool;

typedef struct Element Element;
typedef struct Stack Stack;

struct Element {
    char *instruction;
    char *type;
    char *value;
    Element *next;
};

struct Stack {
    Element *first;
};

typedef struct path_to_file_s {
    char *path_to_file;
} path_to_file_t;

void read_file (char *path_to_file, Stack *stack);
int my_strcmp (const char *s1, const char *s2);
char *my_strcpy (char *dest, const char *src);
int my_strlen (const char *str);
void my_putnbr (const int n);
void my_putchar (const char c);
char *my_itoa (int integer);
char *my_dtoa (double num);
double my_atod (char *str);
Stack *new_stack (void);
char *cast_to_int (char *value);
void push_value_stack (Stack *stack, char *instruction, char *type,
                       char *value);
char *pop_element (Stack *stack);
void dump_stack (Stack *stack);
void add_stack (Stack *stack);
void sub_stack (Stack *stack);
void mul_stack (Stack *stack);
void div_stack (Stack *stack);
void mod_stack (Stack *stack);
Bool is_char_condition_true (char c);
Bool is_valid_type (char *type);
Bool is_valid_value (char *type, char *valueStr);
Bool is_valid_instruction (char *instruction);
Bool is_valid_instruction_with_value (char *instruction);
Bool is_valid_int8 (double value);
Bool is_valid_int16 (double value);
Bool is_valid_int32 (double value);
int type_number (char *type);
void assert_value (Stack *stack, char *value);
void manage_instruction (Stack *stack, char *instruction);
void manage_math_operations (Stack *stack, char *instruction);
void print_top_value (Stack *stack);
void parse_line (char *line, Stack *stack, int line_number);
char *get_instruction (char *line, int line_number);
char *get_type (char *line, int line_number);
char *get_value (char *type, char *line, int line_number);
char *valid_type (char *type, char *valueStr, int line_number);
void print_error (char *error, int line_number);
char *add (char *value1, char *value2);
char *sub (char *value1, char *value2);
char *divi (char *value1, char *value2);
char *mod (char *value1, char *value2);
char *mul (char *value1, char *value2);

#endif
