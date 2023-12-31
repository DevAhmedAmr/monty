#include "monty.h"
int is_len_bigger_than_2(stack_t *h);
void swap_error(unsigned int line_number);
/**
 * swap - function that swaps the top two elements of the stack.
 * @h: a node to the first element in the linked list (stack_t)
 * @line_number: line number of the opCode that is being executed
 *
 */
void swap(stack_t **h, unsigned int line_number)
{
	int tmp;
	stack_t *curr;
	/**/
	if (*h == NULL || (*h)->next == NULL)
	{
		/*printf("x = %i\n", x);*/
		/* printf("------ %i\n", curr->next->n);*/
		swap_error(line_number);
	}
	curr = *h;
	tmp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = tmp;
}
/**
 * swap_error - print a message error if swap fun failed
 * @line_number: line number of the opCode that is being executed
 */
void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);

	if (vars_aircraft.stack != NULL)
		free_stack_t(vars_aircraft.stack);

	free(vars_aircraft.input);
	free_grid(vars_aircraft.input_splitted);
	fclose(vars_aircraft.file);

	exit(EXIT_FAILURE);
}
/**
 * is_len_bigger_than_2 - function that swaps the top two
 * @h: a node to the first element in the linked list (stack_t)
 * Return: return
 */
int is_len_bigger_than_2(stack_t *h)
{
	int i = 0;
	stack_t *curr;

	if (h == NULL)
		return (0);

	curr = h;

	while (curr != NULL && i >= 2)
	{

		return (1);

		i++;

		curr = curr->next;
	}
	return (0);
}
