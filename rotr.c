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
char *int_toString(int num)
{
	char *str = malloc(100 * sizeof(char));
	int num_cpy = num, i, j = 0;
	int number_len = 0;

	if (num < 0)
	{
		num = -(num);
		num_cpy = num;
		str[0] = '-';
		j = 1;
	}

	while (num_cpy > 0)
	{
		number_len++;
		num_cpy /= 10;
	}

	for (i = number_len - 1; i >= 0; i--, j++)
	{

		int tmp2 = ((int)(num / _pow(10, i)) % 10);

		str[j] = tmp2 + 48;
		if (i == 0)
		{
			j++;
			break;
		}
	}
	str[j] = '\0';
	return str;
}
/**
 * _pow_recursion - Calculates the value of x raised to the power of y
 * then return it.
 *
 * @x: parm of The base value that wanted to be calcualted.
 * @y:parm of The exponent value that wanted to be raised.
 *
 * Return: The value of x raised to the power of y,
 * or -1 if y is negative.
 */
int _pow(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	if (y > 0 && y != 1)
		return (x * _pow(x, y - 1));
	return (x);
}
