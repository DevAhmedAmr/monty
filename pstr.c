#include <stdio.h>
#include "monty.h"
/**
 * pstr  - prints the string starting at the top of the stack,
 *  followed by a new line.
 *
 * @param
 * @h: a node to the head of the linked list
 * @line_number: line number
 *
 * Return: the length of the linked list
 *
 */

void pstr(stack_t **h, unsigned int line_number)
{
	const stack_t *curr = *h;
	size_t n = 0;

	UNUSED(line_number);

	while (curr != NULL)
	{
		if (curr->n == 0 || curr->n < 0 || curr->n > 127)
		{
			return;
		}

		printf("%c", curr->n);
		curr = curr->next;
		n++;
	}
}
