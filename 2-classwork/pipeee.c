#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pipe(fd);
   int pid = fork();

    if(pid)
    {
        close(fd[0]);
        write(fd[1], "hello\n", 6);
        //sleep(3);
        close(fd[1]);
    }
    else
    {
        char buff[6];
        read(fd[0], buff, 6);
        printf("the buff is %s", buff);
    }
    return 0;
}