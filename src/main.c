/*
** ETNA PROJECT, 2019
** AbstractVM
** File description:
** main
*/
#include "lib/header.h"

int main ()
{
    // char *value1= "1";
    // char *value2 = "4";

    // char *result = add(value1, value2);
    // printf("r : %s", result);

    char buffer[33];

	double value[] = { 11184810.3465, -25, 64, 127 };
	double type[]  = { 16, 32, 8, };


for (int i = 0; i < 4; i++)
	{
		printf("%s\n",
			itoamoi((int)value[i], buffer, (int)type[i]));
	}

	return 0;
}