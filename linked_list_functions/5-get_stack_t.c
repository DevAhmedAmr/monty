#include "lists.h"
/**
 * get_stack_t_at_index - function that returns the nth  node
 * of a stack_t linked list.
 *
 * @param
 * @head: a ptr to the first node in the double linked list
 * @index: the index of the node that we want
 * Return: the nth  node of a stack_t linked list
 *
 */
stack_t *get_stack_t_at_index(stack_t *head, unsigned int index)
{
	stack_t *curr = head;
	size_t n = 0;

	while (curr != NULL)
	{
		if (n == index)
			return (curr);

		curr = curr->next;
		n++;
	}

	return (NULL);
}
