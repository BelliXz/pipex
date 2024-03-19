#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("I am the child process.\n");
		sleep(5);
        printf("I wake up!\n");
        printf("Wait a sec\n");
        sleep(1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("I am the parent process.\n");
		wait(NULL);
		printf("Child process terminated after woke up a sec.\n");
	}
 
	return (EXIT_SUCCESS);
}