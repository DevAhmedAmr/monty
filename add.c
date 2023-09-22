#include "monty.h"
void add_error(unsigned int line_number);
/**
 * add - function that adds adds the top two elements of the stack.
 * @stack: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
		add_error(line_number);

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * add_error - function that prints an err
 * if an error happen while running add_error
 *
 * @line_number: line number of the opCode that is being executed
 *
 */
void add_error(unsigned int line_number)
{
	fprintf(stderr, "L%i: can't add, stack too short\n", line_number);

	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
