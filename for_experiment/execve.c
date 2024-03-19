#include <unistd.h>
#include <stdio.h>
 
int main()
{
	char *args[3];
 
	args[0] = "cat";
	args[1] = "execve.c";
	args[2] = NULL;
	execve("/bin/cat", args, NULL);
	printf("This line will not be executed.\n");
 
	return (0);
}
