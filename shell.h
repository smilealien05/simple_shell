#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

#define DLM " \t\n"
extern char **environ;

void handl_bfct(char **cmd, char **argv, int *st, int idx);
void exitshs(char **cmd, char **argv, int *st, int idx);



char *rline(void);
char **tokenizer(char *ln);
void freestrarray(char **strarr);
char *_getenv(char *str);
char *_getpath(char *cmd);

int _execute(char **cmd, char **argv, int idx);

char *_strdup(const char *str);
int _strcmp(char *str, char *strr);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *strr, char *str);

void revtostr(char *str, int i);
char *_itoa(int n);
void _printerr(char *nm, char *cmd, int indx);
int is_positive_nmbr(char *str);
int isbuilt(char *cmd);

int _atoi(char *str);


#endif
