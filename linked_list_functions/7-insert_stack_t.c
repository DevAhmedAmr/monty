#include "lists.h"
/**
 * insert_stack_t_at_index - function that inserts a new node
 * at a given position.
 *
 * @h: a pointer to the node
 * @idx: given index
 * @n: number to be add to the list
 *
 * Return: the address of the new node, or NULL if it failed
 */

stack_t *insert_stack_t_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *curr = *h;
	unsigned int i = 0;
	int insert_in_beginning = idx == 0;

	if (insert_in_beginning)
		return (add_stack_t(h, n));

	for (; curr; curr = curr->next, i++)
	{
		int insert_in_last = curr->next == NULL && i + 1 == idx;

		if (insert_in_last)
			return (add_stack_t_end(h, n));

		if (i == idx)
		{
			stack_t *newNode = malloc(sizeof(stack_t));

			newNode->n = n;
			newNode->next = curr;
			newNode->prev = curr->prev;

			curr->prev->next = newNode;
			curr->prev = newNode;
			return (newNode);
		}
	}
	return (NULL);
}
