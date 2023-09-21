#include "monty.h"
/**
 * pall - function that adds adds the top two elements of the stack.
 *
 * @stack: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack_t(*stack);
}
