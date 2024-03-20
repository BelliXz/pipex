#include <unistd.h>
#include <stdio.h>
 
int main()
{
	char *args[3];
	int		i;
 
	args[0] = "/bin/ls";
	args[1] = "-l";
	args[2] = NULL;
	i = execve(args[0], args, NULL);
	printf("i = %d\n",i);
	printf("This line will not be executed.\n");
 
	return (0);
}
