#include "shell.h"

/**
 * rline - function readline
 * Return: a string to line
 */

char *rline(void)
{
char *ln = NULL;
size_t len = 0;
int n;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
n = getline(&ln, &len, stdin);
if (n == -1)
{
free(ln);
return (NULL);
}
return (ln);
}

/**
 * tokenizer - toknizer
 * @ln: line what we wan toknize
 * Return: char
 */

char **tokenizer(char *ln)
{
char *tkn = NULL;
char *tmp = NULL;
char **cmd = NULL;
int cpt = 0, i = 0;

if (ln == NULL)
return (NULL);
tmp = _strdup(ln);
tkn = strtok(tmp, DLM);
if (tkn == NULL)
{
free(ln), ln = NULL;
free(tmp), tmp = NULL;
return (NULL);
}
while (tkn)
{
cpt++;
tkn = strtok(NULL, DLM);
}
free(tmp), tmp = NULL;
cmd = malloc(sizeof(char *) * (cpt + 1));
if (!cmd)
{
free(ln), ln = NULL;
return (NULL);
}
tkn = strtok(ln, DLM);
while (tkn)
{
cmd[i] = _strdup(tkn);
tkn = strtok(NULL, DLM);
i++;
}
cmd[i] = NULL;
free(ln), ln = NULL;

return (cmd);
}

/**
 * freestrarray - free a array of string
 * @strarr: array of string
 * Return: void
 */

void freestrarray(char **strarr)
{
int i = 0;
if (!strarr)
return;
for (i = 0; strarr[i]; i++)
{
free(strarr[i]);
strarr[i] = NULL;
}
free(strarr), strarr = NULL;
}

/**
 * _getenv - get envirenment
 * @str: string
 * Return: string
 */

char *_getenv(char *str)
{
char *dup;
char *clee;
char *var;
int i = 0;

for (i = 0; environ[i]; i++)
{
dup = _strdup(environ[i]);
clee = strtok(dup, "=");

if (_strcmp(clee, str) == 0)
{
var = _strdup(strtok(NULL, "\n"));
free(dup);
return (var);
}
free(dup), dup = NULL;

}
return (NULL);
}
/**
 * _getpath - function to get PATH
 * @cmd: command
 * Return: string
 */

char *_getpath(char *cmd)
{
char *path, *verif;
char *allcmd;
struct stat stt;
int i;
for (i = 0; cmd[i]; i++)
{
if (cmd[i] == '/')
{
if (stat(cmd, &stt) == 0)
return (_strdup(cmd));
return (NULL);
}
}
path = _getenv("PATH");
if (!path)
return (NULL);
verif = strtok(path, ":");
while (verif)
{
allcmd = malloc(strlen(verif) + strlen(cmd) + 2);
if (allcmd)
{
_strcpy(allcmd, verif);
_strcat(allcmd, "/");
_strcat(allcmd, cmd);
if (stat(allcmd, &stt) == 0)
{
free(path), path = NULL;
return (allcmd);
}
free(allcmd);
}
verif = strtok(NULL, ":");
}
free(path);
return (NULL);
}
