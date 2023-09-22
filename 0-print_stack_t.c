#include <stdio.h>
#include "monty.h"
/**
 * print_stack_t - function that prints a element of n of a linked list
 *
 * @param
 * @h: a node to the head of the linked list
 *
 * Return: the length of the linked list
 *
 */

size_t print_stack_t(const stack_t *h)
{
	const stack_t *curr = h;
	size_t n = 0;

	while (curr != NULL)
	{
		printf("%i\n", curr->n);
		curr = curr->next;
		n++;
	}
	return (n);
}
