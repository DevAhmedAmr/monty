#include "monty.h"
void pchar_error(unsigned int line_number, char *err_msg);
/**
 * pchar - The opcode pint prints the value at the top of the stack
 * @h: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */
void pchar(stack_t **h, unsigned int line_number)
{

	if (*h == NULL)
		pchar_error(line_number, "can't pchar, stack empty");

	if ((*h)->n >= 0 && (*h)->n <= 127)
	{
		printf("%c\n", (*h)->n);
		return;
	}
	pchar_error(line_number, "can't pchar, value out of range");
}
/**
 * pchar_error - function that print err for pint function
 * @line_number: line number of the opCode that is being executed
 * @err_msg: err message to be printed
 *
 */
void pchar_error(unsigned int line_number, char *err_msg)
{
	fprintf(stderr, "L%i: %s\n", line_number, err_msg);

	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
