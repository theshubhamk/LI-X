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

int main(int argc, char *argv[])
{
    int fd;// = malloc(sizeof(int) * 100);    
    fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND , 00777);
    perror("open:");
    
   // close (1);
    //dup(fd);
    dup2(fd, 1);
    
    printf("shubham\n");    
}