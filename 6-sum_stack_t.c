#include "monty.h"
/**
 * sum_stack_t - function that returns the sum of all
 * the data (n) of a stack_t linked list.
 * @param
 * @head: a node to a linked list
 *
 * Return: the sum of all the data (n) of a stack_t linked list.
 *
 */
int sum_stack_t(stack_t *head)
{
	int sum = 0;
	stack_t *curr = head;

	while (curr)
	{
		sum += curr->n;

		curr = curr->next;
	}
	return (sum);
}
