#include "shell.h"

/**
 * _printerr - function handlers
 * @nm: name
 * @cmd: command
 * @indx: index of cmd
 * Return: void
 */

void _printerr(char *nm, char *cmd, int indx)
{
char *i, msg[] = ": not found\n";

i = _itoa(indx);

write(STDERR_FILENO, nm, _strlen(nm));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, i, _strlen(i));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, msg, _strlen(msg));

free(i);
}

/**
 * isbuilt - check is a built in function
 * @cmd: command
 * Return: (1) if  true value
 */

int isbuilt(char *cmd)
{
	char *bfct[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; bfct[i]; i++)
	{
		if (_strcmp(cmd, bfct[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _itoa - function change int to ascii
 * @n: int what we want to change
 * Return: a memory of char
 */

char *_itoa(int n)
{
char b[20];
int a = 0;

if (n == 0)
{
b[a] = '0';
a++;
}
else
{
while (n > 0)
{
b[a] = (n % 10) + '0';
n /= 10;
a++;
}
}
b[a] = '\0';
revtostr(b, a);
return (_strdup(b));
}

/**
 * revtostr - function that reverse a str
 * @str: string
 * @i: taille of string
 * Return: void
 */

void revtostr(char *str, int i)
{
char t;
int start = 0;
int end = i - 1;

while (start < end)
{
t = str[start];
str[start] = str[end];
str[end] = t;
start++;
end--;
}
}

/**
 * is_positive_nmbr - function check if positive
 * @str: string
 * Return: 0 if true
 */

int is_positive_nmbr(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		return (0);
	}
	return (1);
}
