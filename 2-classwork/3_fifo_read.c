#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

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
    int pp;
    read(fifo_fd, &pp, sizeof(pp));
    printf("%d\n", pp);
    read(fifo_fd, &pp, sizeof(pp));
    printf("%d\n", pp);
    //write(fifo_fd, &pp, sizeof(pp));
    //write(fifo_fd, &pp, sizeof(pp));

    return 0;
}