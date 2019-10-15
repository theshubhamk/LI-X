#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fifo_fd;

    //mknod("FIFO", 0777 | S_IFIFO, 0);

    fifo_fd = open("FIFO", O_RDONLY);
    if(fifo_fd == -1)
    {
        perror("open");
        return 1;
    }
    char *pp = malloc(sizeof(char) * 100);
    read(fifo_fd, pp, sizeof(pp));
    int x = 4;
    while(x > -1)
    {
        printf("%c", pp[x]);
        x--;
    }
    //printf("%c\n", pp[0]);
    
    
    //write(fifo_fd, &pp, sizeof(pp));
    //write(fifo_fd, &pp, sizeof(pp));

    return 0;
}