#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * main - entry for an app that execute monty file input
 * from a file
 * @argc: number of cmd args
 * @argv: cmd args
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	int line_number = 1;

	vars_aircraft.stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	vars_aircraft.input = malloc(250 * sizeof(char));
	malloc_failur(vars_aircraft.input);

	vars_aircraft.file = fopen(argv[1], "r");

	if (vars_aircraft.file == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		free(vars_aircraft.input);
		exit(EXIT_FAILURE);
	}

	while (fgets(vars_aircraft.input, 250, vars_aircraft.file) != NULL)
	{
		vars_aircraft.input_splitted = string_toList(vars_aircraft.input);

		compare_fun(vars_aircraft.input_splitted, line_number,
					&(vars_aircraft.stack));
		free_grid(vars_aircraft.input_splitted);
		line_number++;
	}
	free_stack_t(vars_aircraft.stack);
	fclose(vars_aircraft.file);
	free(vars_aircraft.input);
	return (0);
}
/**
 * compare_fun - function that print execute the commands
 * @note
 * @input_splitted: input splitted  as 2d array
 * @line_number: number of the line
 * @stack: a node to linked list
 */
void compare_fun(char **input_splitted, const int line_number, stack_t **stack)
{
	instruction_t functions[] = {{"push", push},
								 {"pall", pall},
								 {"pint", pint},
								 {"pop", pop},
								 {"swap", swap},
								 {"add", add},
								 {"nop", nop},
								 {"sub", sub},
								 {"div", div}};
	int i;

	if (double_arr_len(input_splitted) == 0)
		return;

	for (i = 0; i < 9; i++)
	{

		if (strcmp(functions[i].opcode, input_splitted[0]) == 0)
		{
			functions[i].f(stack, line_number);
			return;
		}
	}
	if (input_splitted[0] != NULL)
	{
		unknown_instruction_err(line_number, input_splitted[0]);
	}
}
