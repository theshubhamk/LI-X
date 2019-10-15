#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    int num;

    printf("After exec my process ID is %d\n", getpid());
    printf("My parent process's ID is %d\n", getppid());

    num = atoi(argv[1]);
    printf("Numner recieved %d\n", num);
    printf("\nexec ends\n");
    return 0;
    
}