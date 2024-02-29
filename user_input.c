#include "shell.h"
/*
*end of file function specified
*execute and exit if successful
*/
void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
	if (feof(stdin))
	{
	optimus_print("\n");
	exit(EXIT_SUCCESS);
		} else
		{
		optimus_print("Error while reading input.\n");
		exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
