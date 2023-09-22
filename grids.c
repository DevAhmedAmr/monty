#include "monty.h"
#include <string.h>
/**
 * free_grid - function that free grids (2d array).
 *
 * @arr: array to be freed
 *
 * Return: 0 on failure or 1 on success
 */
int free_grid(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return (1);

	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (0);
}
/**
 * double_arr_len - function that get len of grids (2d array).
 *
 * @arr: array to calculate its len
 *
 * Return: len of arr
 */
int double_arr_len(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;
	return (i);
}

/**
 * print_grid - function that print grids (2d array).
 *
 * @arr: array to be printed
 *
 */

void print_grid(char **arr)
{
	int i;

	printf("{");
	for (i = 0; arr[i] != NULL; i++)
	{
		printf("%s", arr[i]);

		if (arr[i + 1] != NULL)
		{
			printf(", ");
		}
	}
	puts("}");
}
