#include "monty.h"
void pint(stack_t **h, unsigned int line_number)
{
	UNUSED(line_number);

	printf("%i\n", (*h)->n);
}
