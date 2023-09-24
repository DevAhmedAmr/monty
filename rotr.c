#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "monty.h"
char *int_toString(int num);
int _pow(int x, int y);
int delete_last_node(stack_t **h, int *n);
/**
 * rotr - prints the string starting at the top of the stack,
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
	char *str_tmp;

	UNUSED(line_number);

	if (!h || !(*h) || !((*h)->next))
		return;

	delete_last_node(h, &tmp);

	str_tmp = int_toString(tmp);

	add_at_beginning_stack_t(h, tmp);

	free(str_tmp);
}
/**
 * delete_last_node  - function that delete the last node
 *
 *
 * @param
 * @h: a node to the head of the linked list
 * @n: variable to save the value on the node
 *
 * Return: 1 of success and 1 on fails
 *
 */
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
	return (0);
}
