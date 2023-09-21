#include <stdio.h>
#include "monty.h"
/**
 * stack_t - function that returns the number of elements
 * in a linked dlistint_t list.
 *
 * @param
 * @h: a node to the head of the linked list
 *
 * Return: the length of the linked list
 *
 */

size_t stack_t_len(const stack_t *h)
{
	const stack_t *curr = h;
	size_t n = 0;

	while (curr != NULL)
	{
		curr = curr->next;
		n++;
	}
	return (n);
}
