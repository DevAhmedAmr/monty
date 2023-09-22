#include <stdio.h>
#include "monty.h"
int delete_last_node(stack_t **h, int *n);
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

void rotr(stack_t **h, unsigned int line_number)
{
	int tmp;

	UNUSED(line_number);

	if (!h || !(*h) || !((*h)->next))
		return;
	delete_last_node(h, &tmp);
	push(h, tmp);
}
int delete_last_node(stack_t **h, int *n)
{
	stack_t *curr = *h;
	int i;

	for (; curr; curr = curr->next, i++)
	{
		stack_t *tmp = *h;
		if (curr != NULL && (curr->next == NULL))
		{
			tmp = curr;
			*n = curr->n;
			curr->prev->next = NULL;
			free(tmp);
			return (1);
		}
	}
	return 0;
}