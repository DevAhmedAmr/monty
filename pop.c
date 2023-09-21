#include "monty.h"
/**
 * pint - The opcode pint prints the value at the top of the stack
 * @stack: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */
void pop_error(unsigned int line_number);

void pop(stack_t **h, unsigned int line_number)
{
	if (*h == NULL)
	{
		pop_error(line_number);
	}
	delete_node_stack_t_at_index(h, 0);
}

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
