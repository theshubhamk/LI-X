#include <pthread.h>
#include <stdio.h>

void *print_x(void *data)
{
    while(1)
    {
        fputc('X', stderr);
        //fputc('X', stdout);
    }
}

void *print_o(void *data)
{
    while(1)
    {
        fputc('0', stderr);
        //fputc('0', stdout);
    }
}

int main()
{
    pthread_t tid1, tid2;

    //create thread1. thread 1 will execute print_x func
    pthread_create(&tid1, NULL, print_x, NULL);

    //create thread2. thread 2 will execute print_o func
    pthread_create(&tid2, NULL, print_o, NULL);

    //WAIT FOR THE thread 1 to compelete using pthread_join
    pthread_join(tid1, NULL);//blocking functn

    //WAIT FOR THE thread 2 to compelete using pthread_join
    pthread_join(tid2, NULL);

    //in above the first thread doesnt complete at all ever so 2nd pthread_join never executes and thus both pthread_join keeps on waiting


    //int c = 5;
    //while(c--);
    //while(1); // if we comment this out then main thread terminates the the whole process terminates i.e the other two threads will also terminate.
    // make sure the main thread does not teriminates.

    return 0;
}