#ifndef shell_lib_h
#define shell_lib_h
char *_getline();
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
/*char **_strtok(char *line, char *delim);*/
long _strtok(char ***arr, char *line, char *delim);
char *_strcat(char *s1, char *s2);
int run_commands(char ***, long, char ***);
int run(char **cmd, char ***);
void free_array(char ***arr, int size);
int append_path(char ***, long);
int array_copy(char ***dest, char ***src, long size, int start, int end);
void _print_env(char ***);
int _set_env(char *, char ***);
int _set_env(char *var, char ***);
int _unset_env(char *var, char ***);
int _puts(int, char *);
int _putchar(int, char);
void print_commands(char **clist, long csize);

#endif
