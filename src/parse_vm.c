/*
** ETNA PROJECT, 2019
** parse
** File description:
** parse
*/

#include "lib/header.h"

char *get_instruction (char *line)
{
    Bool valid_instruction;
    char space = ' ';
    int i = 0;
    int k = 0;
    char *instruction;
    instruction = malloc (sizeof (char) * (my_strlen (line) + 1));

    while (line[i] != '\0' && line[i] != space && line[i] != '\n') {
        instruction[k++] = line[i];
        i++;
    }

    valid_instruction = is_valid_instruction2 (instruction);
    if (valid_instruction == true) {
        return instruction;
    }
    return "Error instruction parse";
};

char *get_type (char *line)
{
    char space = ' ';
    int i = 0;
    int k = 0;
    int posSpace = 0;
    char *type;
    type = malloc (sizeof (char) * (my_strlen (line) + 1));

    while (line[i] != '(') {
        if (line[i] == space) {
            posSpace = i;
            for (int j = posSpace + 1; line[j] != '(' && line[j] != space; j++) {
                type[k++] = line[j];
            }
        }
        i++;
    }
    return type;
    free(type);
}

double get_value (char *line)
{
    Bool valid_value;
    int i = 0;
    int k = 0;
    double value;
    char *valueStr;

    int posOpenTheEyes = 0;

    valueStr = malloc (sizeof (char) * (my_strlen (line) + 1));

    while (line[i] != ')') {
        if (line[i] == '(') {
            posOpenTheEyes = i;
            for (int j = posOpenTheEyes + 1; line[j] != ')'; j++) {
                valueStr[k++] = line[j];
            }
        }
        i++;
    }

    value = my_atod (valueStr);

    valid_value = is_valid_value (get_type(valueStr), value);
    if (valid_value == true) {
        return value;
    }
    printf("%s", "Error instruction parse");

    return value;

}