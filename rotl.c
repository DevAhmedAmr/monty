#include <stdio.h>
#include "monty.h"
/**
 * rotl  - prints the string starting at the top of the stack,
 *  followed by a new line.
 *
 * @param
 * @h: a node to the head of the linked list
 * @line_number: line number
 *
 * Return: the length of the linked list
 *
 */

void rotl(stack_t **h, unsigned int line_number)
{
	int tmp;

	if (!h || !(*h) || !((*h)->next))
		return;

	tmp = (*h)->n;

	pop(h, line_number);
	add_stack_t_end(h, tmp);
}
