#include "shell.h"

/**
 * _strdup - deplucate a string
 * @str: The string we want to duplicate
 * Return: a pointer
 */
char *_strdup(const char *str)
{
char *pointer;
int ln = 0, i;

if (str == NULL)
return (NULL);
while (*str != '\0')
{
ln++;
str++;
}
str = str - ln;
pointer = malloc(sizeof(char) * (ln + 1));
if (pointer == NULL)
return (NULL);
for (i = 0; i <= ln; i++)
pointer[i] = str[i];
return (pointer);
}

/**
 * _strcmp - compare two string
 * @str: firdt string that we want to compare
 * @strr: second string that we want to compare
 * Return: 0 while true
 */

int _strcmp(char *str, char *strr)
{
int cmp;
while (*str && *strr && *str == *strr)
{
str++;
strr++;
}
cmp = (int)*str - (int)*strr;
return (cmp);
}

/**
 * _strlen - count a length of string
 * @str: String whose length we want to calculate
 * Return: 0 while true
 */

int _strlen(char *str)
{
int len = 0;

while (str[len])
{
len++;
}
return (len);
}

/**
 * _strcat - concatinate a string
 * @src: String source
 * @dest: String destination
 * Return: a pointer
 */

char *_strcat(char *dest, char *src)
{
char *p = dest;

while (*p)
p++;
while (*src)
{
*p = *src;
p++;
src++;
}
*p = '\0';
return (dest);
}

/**
 * _strcpy - capy a string
 * @str: String whose we want to copy
 * @strr: adresse when we want to paste
 * Return: 0 while true
 */

char *_strcpy(char *strr, char *str)
{
int i = 0;

while (str[i])
{
strr[i] = str[i];
i++;
}
strr[i] = '\0';
return (strr);
}
