#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    printf("before execl\n");
    printf("My PID = %d", getpid());
    execl("/bin/ls", "ls", NULL);
    for(int i = 0; i < 50; i--)
    {
        printf("continue..");
    }
}