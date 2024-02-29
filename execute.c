#include "shell.h"

/*
* void execute_command(const char *command) {
*    pid_t child_pid = fork(); //create a child process
*     if (child_pid == -1) {
*         perror("fork");
*         exit(EXIT_FAILURE);
*     } else if (child_pid == 0) {
*         // Child process
*         execlp(command, command, (char *)NULL);
*        perror("execlp");
*         exit(EXIT_FAILURE);
*     } else {
*         // Parent process
*         wait(NULL);
*     }
*/ }


#include "shell.h"


void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
	optimus_print("Error forking process.\n");
	exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
	/*
	 * Child process
	 * Parse the command and its arguments
	 *Maximum 128 arguments (adjust as needed)
	 */
		char *args[128];
		int arg_count = 0;

		char *token = strtok((char *)command, " ");
		while (token != NULL)

		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execvp(args[0], args);

	optimus_print("Error executing command.\n");
	exit(EXIT_FAILURE);
		} else
		{
	 /*
	* Parent process
	*/
		wait(NULL);
	}
}
