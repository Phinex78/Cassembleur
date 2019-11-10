/*
** ETNA PROJECT, 2019
** parse
** File description:
** parse
*/

#include "lib/header.h"

char *get_instruction (char *line, int line_number)
{
    int i = 0;
    int k = 0;
    char *instruction = malloc (sizeof (char *) * (my_strlen (line) + 1));

    while (is_char_condition_true (line[i])) {
        instruction[k++] = line[i];
        i++;
    }

    if (is_valid_instruction (instruction)) {
        return instruction;
    } else {
        print_error (BAD_INSTRUCTION, line_number);
        return BAD_INSTRUCTION;
    }
    free (instruction);
};

char *get_type (char *line)
{
    int i = 0;
    int k = 0;
    int posSpace = 0;
    char *type = malloc (sizeof (char *) * (my_strlen (line) + 1));

    while (line[i] != '(') {
        if (posSpace == 0 && line[i] == '\0')
            return "No type";
        if (line[i] == ' ') {
            posSpace = i;
            for (int j = posSpace + 1; line[j] != '(' && line[j] != ' '; j++) {
                type[k++] = line[j];
            }
        }
        i++;
    }
    return is_valid_type (type) ? type : BAD_TYPE;
    free (type);
}

char *get_value (char *line)
{
    int i = 0;
    int k = 0;
    char *valueStr = malloc (sizeof (char *) * (my_strlen (line) + 1));
    int posOpenTheEyes = 0;
    while (line[i] != ')') {
        if (line[i] == '\0' && posOpenTheEyes == 0)
            return "No value";
        if (line[i] == '(') {
            posOpenTheEyes = i;
            for (int j = posOpenTheEyes + 1; line[j] != ')'; j++) {
                valueStr[k++] = line[j];
            }
        }
        i++;
    }
    return valueStr;
    free (valueStr);
}

void parse_line (char *line, Stack *stack, int line_number)
{
    if (!is_char_condition_true (line[0]))
        return;
    char *instruction = get_instruction (line, line_number);
    if (is_valid_instruction_with_value (instruction)) {
        char *type = get_type (line);
        char *value = get_value (line);
        if (is_valid_value (type, value)) {
            if (my_strcmp (instruction, "assert") == 0)
                assert_value (stack, value);
            else
                push_value (stack, instruction, type, value);
        } else {
            print_error (BAD_VALUE, line_number);
        }
    } else {
        manage_instruction (stack, instruction);
    }
}