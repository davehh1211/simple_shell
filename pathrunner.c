#include "shellhead.h"
/**
 * pathrunner - finds and runs the command given by the user
 * @arguments: command to be found.
 * Return: 0 in success
 */
int pathrunner(char **arguments)
{
	char *defpath;
	int status;

	defpath = pathfinder(arguments[0]);
	if (defpath == NULL)
	{
		perror("Command not found, type again...");
		return (0);
	}
	else
	{
		arguments[0] = defpath;
		status = execve(arguments[0], arguments, NULL);
		if (status == -1)
		{
			free(defpath);
			perror("$ Error in execution");
			return (0);
			/*exit(EXIT_FAILURE);*/
		}
		free(defpath);
		/*exit(EXIT_SUCCESS);*/
		return (0);
	}
}
/**
 * _strchr - Write a function that locates a character in a string
 * @s: the pointer to show
 * @c: the char to locate
 * Return: character compared
 */
char *_strchr(char *s, int c)
{
	unsigned int i = 0;
	const char *sign;

	sign = s;
	for (i = 0; *sign != '\0'; i++)
	{
		if (*sign == c)
		{
			return ((char *)sign);
		}
	}
	if (*sign == c)
	{
		return ((char *)sign);
	}
	else
	{
		return ('\0');
	}
}
