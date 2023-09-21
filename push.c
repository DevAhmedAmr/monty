#include "monty.h"

int is_integer(char *str);
int push_usage_err(int line_number);
int unknown_instruction_err(int line_number, char *optcode);
void stack_t_malloc_fail(stack_t *node);
void push(stack_t **stack, unsigned int line_number)
{
	int is_arr_empty = double_arr_len(vars_aircraft.input_splitted) < 2;
	int element;

	if (is_arr_empty == 1)
		push_usage_err(line_number);

	if (is_integer(vars_aircraft.input_splitted[1]) == 1)
		element = atoi(vars_aircraft.input_splitted[1]);
	else
		push_usage_err(line_number);

	stack_t_malloc_fail(add_at_beginning_stack_t(stack, element));
}

int is_integer(char *str)
{
	size_t i;

	for (i = 0; i < strlen(str); i++)
	{
		if ((int)str[i] > 57 || (int)str[i] < 48)
			return 0;
	}

	return 1;
}

int unknown_instruction_err(int line_number, char *optcode)
{
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, optcode);

	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}

int push_usage_err(int line_number)
{
	fprintf(stderr, "L%i: usage: push integer\n", line_number);
	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}

void stack_t_malloc_fail(stack_t *node)
{
	if (node == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		free(vars_aircraft.stack);
		free(vars_aircraft.input);
		free_grid(vars_aircraft.input_splitted);
		fclose(vars_aircraft.file);
		exit(EXIT_FAILURE);
	}
}