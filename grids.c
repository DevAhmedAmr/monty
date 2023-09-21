#include "monty.h"
#include <string.h>

int free_grid(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return 1;

	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return 0;
}
int double_arr_len(char **arr)
{
	int i = 0;
	while (arr[i] != NULL)
		i++;
	return i;
}

void print_grid(char **input_toList)
{
	int i;
	printf("{");
	for (i = 0; input_toList[i] != NULL; i++)
	{
		printf("%s", input_toList[i]);

		if (input_toList[i + 1] != NULL)
		{
			printf(", ");
		}
	}
	puts("}");
}
