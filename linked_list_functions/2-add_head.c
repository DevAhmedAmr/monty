#include "lists.h"
/**
 * add_stack_t - a function that adds a new node
 * at the beginning of a dlistint_t list..
 *
 * @head: a  pointer to a linked list
 * @n: element to be added in the linked list at the beginning
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_head(stack_t **head, int n);

stack_t *add_stack_t(stack_t **head, const int n)
{
	stack_t *curr = *head;
	stack_t *new_Node;

	if (head == NULL)
		return (NULL);

	if (*head == NULL)
		return (add_head(head, n));

	new_Node = malloc(sizeof(stack_t) * 1);

	if (new_Node == NULL)
		return (NULL);

	curr->prev = new_Node;

	new_Node->next = curr;
	new_Node->prev = NULL;
	new_Node->n = n;

	*head = new_Node;

	return (*head);
}
/**
 * add_head - a  function that adds a new node
 * as the new head for a linked list
 *
 * @param
 * @head: a null pointer to an empty list
 * @n: element to be added in the linked list as the new head
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_head(stack_t **head, int n)
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
