#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>
#include <sys/stat.h>
#include <string.h>

//int fstat(int fd, struct stat *statbuf);
int file_op(int *fd1, int *fd2, char *argv[]);

int main(int argc, char *argv[])
{
    int retval;
    struct stat *statbuf;
   // char *buff = (char *) malloc(sizeof(char) * 100);
    char *buff = (char *) calloc(100, sizeof(char));
    if(argc == 1)
    {
        printf("Insufficient arguments\nUsage:- ./my_copy [option] <source file> <destination file>\n");
        exit(0);
    }
    
	int *fd1 = malloc(sizeof(int) * 100);// = open(argv[1], O_RDWR | O_EXCL );
    int *fd2 = malloc(sizeof(int) * 100);
    if(strcmp(argv[1],"-p") != 0)
    {
        printf("fs");
        *fd1 = open(argv[1], O_RDWR | O_EXCL );
        *fd2 = open(argv[2], O_RDWR | O_EXCL );
        file_op(fd1, fd2, argv);
    }
    else
    {
        *fd1 = open(argv[2], O_RDWR | O_EXCL );
        *fd2 = open(argv[3], O_RDWR | O_EXCL );
        printf("s");
        //exit(1);    
    }
    while((retval) != 0)
    {
        //retval = read(fd1, buff, INT_MAX);
       // read(fd1, buff, INT_MAX);
        retval = write(*fd2, buff, read(*fd1, buff, INT_MAX));
    }

    

    




    close(*fd1);
    close(*fd2);
	return 0;
}


int file_op(int *fd1, int *fd2, char *argv[])
{
    if(*fd2 == -1)
    {
        *fd2 = open(argv[2], O_RDWR | O_CREAT );
        perror("r1");
    }
    else
    {
        printf("file already present\nDo you want to overwrite? (Y/N)\n");
        char k = getchar();
        if(k == 'Y' | k == 'y')
        {
            *fd2 = open(argv[2], O_RDWR | O_CREAT );
        }
        else
        {
            printf("Not overwritten");
            exit(1);
        }
            
    }
    return 0;      
}