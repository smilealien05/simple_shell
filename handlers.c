#include "shell.h"

/**
 * handl_bfct - function handlers
 * @cmd: command
 * @argv: argument parameter
 * @st: status
 * @idx: index of cmd
 * Return: void
 */
void handl_bfct(char **cmd, char **argv, int *st, int idx)
{
int i;

if (_strcmp(cmd[0], "env") == 0)
{
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freestrarray(cmd);
(*st) = 0;
return;
}
else if (_strcmp(cmd[0], "exit") == 0)
{
exitshs(cmd, argv, st, idx);
}
}
/**
 * exitshs - exit built-in function
 * @cmd: command
 * @argv: argument parameter
 * @st: status
 * @idx: index of cmd
 * Return: void
 */

void exitshs(char **cmd, char **argv, int *st, int idx)
{
int exitval = (*st);
char *i, msg[] = ": exit: Illegal number: ";

if (cmd[1])
{
if (is_positive_nmbr(cmd[1]))
{
exitval = _atoi(cmd[1]);
}
else
{
i = _itoa(idx);
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, i, _strlen(i));
write(STDERR_FILENO, msg, _strlen(msg));
write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
write(STDERR_FILENO, "\n", 1);
free(i);
freestrarray(cmd);
(*st) = 2;
return;
}
}
freestrarray(cmd);
exit(exitval);
}
