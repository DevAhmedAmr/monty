#include "monty.h"
void pint_error(unsigned int line_number);
/**
 * pint - The opcode pint prints the value at the top of the stack
 * @h: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */
void pint(stack_t **h, unsigned int line_number)
{
	UNUSED(line_number);

	if (*h == NULL)
		pint_error(line_number);

	printf("%i\n", (*h)->n);
}
/**
 * pint_error - function that print err for pint function
 * @line_number: line number of the opCode that is being executed
 *
 */
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);

	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
