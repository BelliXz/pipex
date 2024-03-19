#include <stdio.h>
#include <string.h>
#include <errno.h>

int main () {
   FILE *fp;
   char *test;
   /* now let's try to open same file */
   fp = fopen("test.txt", "r");
   if( fp == NULL ) {
    test = strerror(errno);
    printf("%s\n", strerror(errno));
    //   perror("Error");
      return(-1);
   }
    fclose(fp);
      
   return(0);
}