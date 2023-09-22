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
	const stack_t *curr = *h;
	int tmp = curr->n;

	if (*h == NULL || h == NULL)
		return;

	pop(h, line_number);
	add_stack_t_end(h, tmp);
}