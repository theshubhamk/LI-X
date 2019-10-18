#include <stdio.h>
#include <pthread.h>

typedef struct kum
{
    int num1, num2;
    int result;
}sumdata_t;

void *sum_func(void *param)
{
    sumdata_t *info = param;
    info->result = info->num1 + info->num2;

    return NULL;// since the return is void *
}

int main()
{
    pthread_t tid1; //thread ID
    //struct kum data; ==  sumdata_t data;
    sumdata_t data;
    data.num2 = 10, data.num1 = 5;

    //create thread 1 . thread 1 will execute sum_func . Argc is &data
    pthread_create(&tid1, NULL, sum_func, &data);

    //wait for the thread 1 to complete using pthread_join
    pthread_join(tid1, NULL);

    //print the result
    printf("Sum = %d\n", data.result);

    return 0;
}