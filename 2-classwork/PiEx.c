#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <limits.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd[2];
    pipe(fd);
    int x = fork();
    
    if(x == 0)
    {
    if(x == 0)
        close(fd[0]);
        int fd1 = open("t.txt", O_RDWR | O_CREAT | O_APPEND , 00777);
        fd1 = dup2(fd[1],1);
        
        printf("shubham\n");
        write(fd1,"ks\n",5);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0],0);
        char s[10];
        scanf("%s",s);
        printf("rx is : %s\n",s);
        close(fd[0]);
        wait(NULL);
    }
    
}