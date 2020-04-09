#include "shellhead.h"

/**
 * main - Shell function
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL, **args = NULL;
	size_t n = 0, i = 0;
	ssize_t characters_read;
	pid_t pid;

	while (1)
	{
		/*Printing our prompt*/
		printf("$ ");

		/*Using getline() to get whatever the user typed*/
		characters_read = getline(&buffer, &n, stdin);
		/*Checking is we read the line right*/
		if (characters_read == -1)
		{
			free(buffer);
			perror("Error: Bad arguments in getline() function");
			exit(EXIT_FAILURE);
		}
		/* We will start a Child process with Fork */
		pid = fork();
		/*to check error forking*/
		if (pid == -1)
		{
			free(buffer);
			perror("Error: No child process was created");
			exit(0);
		}
		/*Child process*/
		else if (pid == 0)
		{
			args = malloc(sizeof(char *));
			if (!args)
			{
				free(args);
				continue;
			}
			*(args) = malloc(sizeof(char) * characters_read);
			if (!*args)
			{
				free(*args);
				free(args);
				continue;
			}
			if (*args[0] == 0x0)
			{
				free(*args);
				free(args);
				continue;
			}
			if (*args == NULL)
			{
				free(*args);
				free(args);
				continue;
			}
			args = _flags(buffer, characters_read);

			else
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror("Error: Execution error");
					exit(EXIT_FAILURE);
				}
				for(i = 0; args[i]; i++)
					free(args[0]);
				free(args);
				exit(0);
			}
		}
		/*Parent process*/
		else
		{
		/*Make the parent wait for any signal from the child*/
			wait(NULL);
		}
		free(buffer);
	}
	return(0);
}
