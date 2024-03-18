#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	int fd1;
    int fd2;
 
	fd1 = open("test.txt", O_RDWR | O_CREAT, 0644);
    fd2 = open("example.txt", O_RDWR);
    dup2(fd1, 0)
	if(dup2(fd2, 1))
    {
	    
    }
	close(fd1);
    close(fd2);
	return (0);
}