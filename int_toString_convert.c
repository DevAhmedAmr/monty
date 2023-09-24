#include "stdlib.h"
int number_len(int num);
int _pow(int x, int y);
/**
 * int_toString - function convert int to a string
 *
 * @num: number to be converted
 *
 * Return: pointer to a string that contain the number or
 * NULL on failure
 */
char *int_toString(int num)
{
	char *str = malloc(100 * sizeof(char));
	int i, j = 0;

	if (str == NULL)
		return (NULL);

	if (num < 0)
	{
		num = -(num);
		str[0] = '-';
		j = 1;
	}

	for (i = number_len(num) - 1; i >= 0; i--, j++)
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
	return (str);
}
/**
 * _pow - Calculates the value of x raised to the power of y
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
/**
 * number_len - function that calculate length of a number
 *
 * @num: number to calculate its length
 *
 * Return: length of the number
 */
int number_len(int num)
{
	int num_cpy = num;
	int number_len = 0;

	while (num_cpy > 0)
	{
		number_len++;
		num_cpy /= 10;
	}
	return (number_len);
}
