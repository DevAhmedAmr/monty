#include "lists.h"
stack_t *_add_head(stack_t **head, int n);
/**
 * add_stack_t_end - a  function that adds a new node at
 * the end of a stack_t list.
 *
 * @param
 * @head: the head of linked list that wanted an element to be added in
 * @n: element to be added in the linked list
 *
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *add_stack_t_end(stack_t **head, const int n)
{
	stack_t *curr = *head;
	stack_t *new_Node;
	stack_t *last_node;

	if (head == NULL)
		return (NULL);

	if (*head == NULL)
		return (_add_head(head, n));

	while (curr != NULL)
	{
		if (curr->next == NULL)
			last_node = curr;
		curr = curr->next;
	}

	new_Node = malloc(sizeof(stack_t) * 1);

	if (new_Node == NULL)
		return (NULL);

	new_Node->n = n;
	new_Node->next = NULL;
	new_Node->prev = last_node;
	last_node->next = new_Node;
	return (new_Node);
}

/**
 * _add_head - a  function that adds a new node
 * as the new head for a linked list
 *
 * @param
 * @head: a null pointer to an empty list
 * @n: element to be added in the linked list as the new head
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *_add_head(stack_t **head, int n)
{
	stack_t *curr = malloc(sizeof(stack_t) * 1);

	if (curr == NULL)
		return (NULL);

	curr->n = n;
	curr->next = NULL;
	curr->prev = NULL;
	*head = curr;
	return (curr);
}
