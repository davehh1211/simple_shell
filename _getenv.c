#include "shellhead.h"
/**
 * _getenv - get the enviroment variable from environ
 * @name: the name of the env var
 * Return: the pointer of the var.
 */
char *_getenv(const char *name)
{
	char *tok, *s;
	int i = 0;
	char *tmpenv;
	const char *delim = "=";

	i = 0;
	while (environ[i])
	{
		/* avoids the environ var */
		tmpenv = _strdup(environ[i]);
		/* parse the full path */
		tok = _strtok(tmpenv, delim);
		if (strcmp(name, tok) == 0)
		{
			tok = _strtok(NULL, delim);
			/* avoid valgrind error */
			s = _strdup(tok);
			/*free(tmpenv);*/
			return (s);
		}
		free(tmpenv);
		i++;
	}
	return (NULL);
}
