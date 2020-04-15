#include "shellhead.h"
/**
 * envbuilt - function to print the enviroment var
 * Return: nothing
 */
void envbuilt(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
}
/**
 * pathrunner - finds and runs the command given by the user
 * @cmdpath: command to be found.
 * Return: 0 in success
 */
int pathrunner(char **cmdpath)
{
	char *defpath;
	int status;

	if (strcmp("env", cmdpath[0]) == 0 || strcmp("printenv", cmdpath[0]) == 0)
		envbuilt();
	if (strcmp("exit", cmdpath[0]) == 0)
	{
		free(cmdpath[0]);
		free(cmdpath);
		exit(EXIT_SUCCESS);
	}
	defpath = pathfinder(cmdpath[0]);
	if (defpath == NULL)
	{
		perror("Command not found, type again...");
		return (0);
	}
	else
	{
		cmdpath[0] = defpath;
		status = execve(cmdpath[0], cmdpath, NULL);
		if (status == -1)
		{
			free(defpath);
			perror("$ Error in execution");
			return (0); /*exit(EXIT_FAILURE);*/
		}
		free(defpath);
		return (0); /*exit(EXIT_SUCCESS);*/
	}
}
