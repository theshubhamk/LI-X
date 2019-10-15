#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    int retval;
   // char *buff = (char *) malloc(sizeof(char) * 100);
    char *buff = (char *) calloc(100, sizeof(char));
    if(argc == 1)
    {
        printf("Enter the valid number of arguments\n");
        exit(0);
    }

	int fd1 = open(argv[1], O_RDWR | O_EXCL );
    int fd2;
    //if(argv[2] == '\0')
    {
        fd2 = open(argv[2], O_RDWR | O_EXCL );
        if(fd2 == -1)
        {
            fd2 = open(argv[2], O_RDWR | O_CREAT );
            perror("r1");
        }
    }
    while((retval) != 0)
    {
        //retval = read(fd1, buff, INT_MAX);
       // read(fd1, buff, INT_MAX);
        retval = write(fd2, buff, read(fd1, buff, INT_MAX));
    }

    

    




    close(fd1);
    close(fd2);
	return 0;
}
