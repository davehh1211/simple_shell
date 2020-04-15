#include "shellhead.h"
/**
 * controlc - handle to avoid exitting with ctrl+c
 * @s: signal to be evaluated.
 * Return: nothing.
 */
void controlc(int s)
{
	s *= 1;
	write(1, "\n$ ", 3);
}
/**
 * main - main function of
 * program simple_shell
 * Return: on succes return 0.
 */
int main(void)
{
	char *lineptr = NULL, **args;
	int status = 0;

	while (status == 0)
	{
		/*prints prompt*/
		signal(SIGINT, controlc);
		write(STDOUT_FILENO, "$ ", 2);

		lineptr = _getline();
		if (lineptr == 0)
		{
			free(lineptr);
			continue;
		}
		args = tokenizer(lineptr, TOK_DELIMITER);
		status = execute(args);
		free(args);
		free(lineptr);
	}
	return (0);
}