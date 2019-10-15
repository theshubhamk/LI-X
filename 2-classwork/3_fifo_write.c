#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fifo_fd;

    mknod("FIFO", 0777 | S_IFIFO, 0);

    fifo_fd = open("FIFO", O_WRONLY);
    if(fifo_fd == -1)
    {
        perror("open");
        return 1;
    }
    int pp = 100;
    write(fifo_fd, &pp, sizeof(pp));
    pp = 500;
    write(fifo_fd, &pp, sizeof(pp));

    return 0;
}