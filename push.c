#include "monty.h"

int is_integer(char *str);
void push_usage_err(int line_number);
void stack_t_malloc_fail(stack_t *node);
/**
 * push - function that push number to stack arr
 * @stack: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */
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

	if (!vars_aircraft.is_queue)

		stack_t_malloc_fail(add_at_beginning_stack_t(stack, element));
	else
		stack_t_malloc_fail(add_stack_t_end(stack, element));
}

/**
 * set_queue - function  that sets the format of the data to a queue (FIFO).
 * @stack: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	vars_aircraft.is_queue = 1;
}

/**
 * set_stack - function  that  sets the format of the data to a stack (LIFO).
 * (This is the default behavior of the program.)
 * @stack: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	vars_aircraft.is_queue = 0;
}

/**
 * is_integer - function that checks if the str is a number or not
 * @str: str input to be confirmed
 * Return: 0 if not an integer , 1  if its
 */
int is_integer(char *str)
{
	size_t i;

	for (i = 0; i < strlen(str); i++)
	{
		int in_negative = i == 0 && str[i] == '-';

		if (in_negative)
			continue;

		if ((int)str[i] > 57 || (int)str[i] < 48)
			return (0);
	}

	return (1);
}
/**
 * unknown_instruction_err - function that print err message
 *
 * @line_number: line number of the opCode that is being executed
 * @optcode: input command
 *
 */
void unknown_instruction_err(int line_number, char *optcode)
{
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, optcode);

	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
/**
 * push_usage_err - function that print usage err message
 *
 * @line_number: line number of the opCode that is being executed
 */
void push_usage_err(int line_number)
{
	fprintf(stderr, "L%i: usage: push integer\n", line_number);
	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
/**
 * stack_t_malloc_fail - function that print usage err message
 *
 * @node: function to check if the malloc failed
 */
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
