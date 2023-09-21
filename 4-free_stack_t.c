#include "monty.h"
/**
 * free_stack_t-  function that frees a stack_t list.
 * @head: a pointer to the first node to be deleted
 */

void free_stack_t(stack_t *head)
{
	stack_t *curr = head;

	while (curr)
	{
		stack_t *next = curr->next;

		free(curr);
		curr = next;
	}
}
