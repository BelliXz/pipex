#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	int fd1;
    int fd2;
 
	fd1 = open("file/test.txt", O_RDWR | O_CREAT, 0644);
    fd2 = open("file/example.txt", O_RDWR | O_CREAT, 0644);

	// dup2(fd1, 1); //stdout
	dup2(fd2, 1);//stdout
	printf("Testdupin fd1\n");
	printf("STill reach?\n");
	// close(fd1);
    close(fd2);
	return (0);
}