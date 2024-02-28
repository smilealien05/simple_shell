#include "shell.h"
/**
 * _execute - function to excute the command
 * @cmd: command parameter
 * @argv: argument parameter
 * @idx: index of command
 * Return: status (int)
 */

int _execute(char **cmd, char **argv, int idx)
{
char *allcmd;
pid_t child;
int stt;

allcmd = _getpath(cmd[0]);
if (!allcmd)
{
_printerr(argv[0], cmd[0], idx);
freestrarray(cmd);
return (127);
}

child = fork();

if (child == 0)
{
if (execve(allcmd, cmd, environ) == -1)
{
freestrarray(cmd);
free(allcmd), allcmd = NULL;
}
}
else
{
waitpid(child, &stt, 0);
freestrarray(cmd);
free(allcmd), allcmd = NULL;
}
return (WEXITSTATUS(stt));
}
