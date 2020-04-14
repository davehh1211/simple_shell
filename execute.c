#include "shellhead.h"
/**
 * execute - executes the arguments given by the user
 * @arguments: the arguments
 * Return: 0 in success
 */
int execute(char **arguments)
{
	pid_t pid;

	if (*arguments == NULL)
	{
		return (1);
	}
	pid = fork(); /* We will start a Child process with Fork */
	if (pid == 0) /*Child process*/
	{
		if (_strchr(arguments[0], '/') != NULL)
		{
			if (execve(arguments[0], arguments, environ) == -1)
			{
				perror("$ Execution error");
				/*exit(EXIT_FAILURE);*/
				return (0);
			}
		}
		else
		{
			return (pathrunner(arguments));
		}
	}
	else if (pid == -1) /*to check error forking*/
	{
		perror("$ No child process was created");
		return (1);
	}
	/*Parent process*/
	else
	{
		wait(NULL); /*Make the parent wait for any signal from the child*/
	}
	return (0);
}
