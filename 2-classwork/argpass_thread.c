#include <stdio.h>
#include <pthread.h>

typedef struct
{
    int num1, num2;
    int result;
}sumdata_t;

void *sum_func(void *param)
{
    int res;
    sumdata_t *info = param;
    info->result = info->num1 + info->num2;
    res = info->result;
    return (void *)(long)res;// we are returning result value here not address. 
    //(void *)  is used to match the function return type which is also (void *)
    //(long) is used if in case the result value exceeds int
}

int main()
{
    pthread_t tid1; //thread ID
    //struct kum data; ==  sumdata_t data;
    sumdata_t data;
    data.num2 = 10, data.num1 = 5;
    int sum;

    //create thread 1 . thread 1 will execute sum_func . Argc is &data
    pthread_create(&tid1, NULL, sum_func, &data);

    //wait for the thread 1 to complete using pthread_join
    pthread_join(tid1, (void **) &sum);

    //print the result
    printf("Sum = %d\n", sum);

    return 0;
}