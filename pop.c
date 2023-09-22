#include "monty.h"

void pop_error(unsigned int line_number);
/**
 * pop - function that delete the first node in an array
 * @h: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */
void pop(stack_t **h, unsigned int line_number)
{
	if (*h == NULL)
	{
		pop_error(line_number);
	}
	delete_node_stack_t_at_index(h, 0);
}
/**
 * pop_error - function that print an error message on failure of pop
 * @line_number: line number of the opCode that is being executed
 *
 */
void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);

	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
