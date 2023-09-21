#include "monty.h"
void pint(stack_t **h, unsigned int line_number)
{
	UNUSED(line_number);

	printf("%i\n", (*h)->n);
}

int pint_error(int line_number)
{
	fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
