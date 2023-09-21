#include "monty.h"
char **string_toList(char *input)
{
	char **input_splitted = malloc(250 * sizeof(char *));
	char *tmp = strtok(input, " \n");
	int i;

	if (input_splitted == NULL)
		return NULL;

	for (i = 0; tmp != NULL; i++)
	{
		int len = strlen(tmp);

		input_splitted[i] = malloc(sizeof(char) * (len) + 1);

		if (input_splitted[i] == NULL)
			return NULL;

		strcpy(input_splitted[i], tmp);
		tmp = strtok(NULL, "  \n");
	}

	input_splitted[i] = NULL;
	return input_splitted;
}
