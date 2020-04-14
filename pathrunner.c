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
