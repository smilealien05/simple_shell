#include "shell.h"

/**
 * _atoi - function change ascii to int
 * @str: string
 * Return: a int we reversde
 */

int _atoi(char *str)
{
	int n = 0, i;

	for (i = 0; str[i]; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}
	return (n);
}
