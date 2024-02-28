#include "shell.h"
/**
 * main - simple shell main function
 * @ac: count of arguments
 * @argv: arguments
 * Return: 0 while success
*/

int main(int ac, char **argv)
{
char *ln = NULL;
char **cmd = NULL;
int status = 0;
int idx = 0;
(void) ac;

while (1)
{
ln = rline();
if (ln == NULL)
{
if (isatty(STDIN_FILENO)) /*test if in terminale*/
write(STDIN_FILENO, "\n", 1);
return (status);
}
idx++;

cmd = tokenizer(ln);
if (!cmd)
continue;

if (isbuilt(cmd[0]))
handl_bfct(cmd, argv, &status, idx);
else
status = _execute(cmd, argv, idx);
}
}
