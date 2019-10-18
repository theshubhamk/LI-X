#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct
{
    int num1, num2;
    int result;
}sumdata_t;

void *sum_func(void *param)
{
    int *ptr = malloc(sizeof(int));

    sumdata_t *info = param;
    *ptr = info->num1 + info->num2; // info->num1 is accessing the member called num1 of the struct so (info->num1) is a number.
    return ptr;
    // we are returning address here.
}

int main()
{
    pthread_t tid1; //thread ID
    //struct kum data; ==  sumdata_t data;
    sumdata_t data;
    data.num2 = 10, data.num1 = 5;
    int *sum = NULL;

    //create thread 1 . thread 1 will execute sum_func . Argc is &data
    pthread_create(&tid1, NULL, sum_func, &data);

    //wait for the thread 1 to complete using pthread_join
    pthread_join(tid1,(void **) &sum);

    //print the result
    printf("Sum = %d\n", *sum);

    //free ptr
    free(sum);
    sum = NULL;

    return 0;
}