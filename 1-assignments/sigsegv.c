#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_signal_handler(int signum)
{
    printf("got signal %d\n", signum);
}

int main(int argc, char *argv[])
{
    signal(SIGSEGV,my_signal_handler);
    char *arr[5];
    arr[6] = NULL;
    int count = 0;
    while(1)
    {
        count++;
        sleep(1);
        printf("run\n");
        if(count == 5)
        {
            printf("%s\n", arr[6]);
        }
    }
    return 0;
}
