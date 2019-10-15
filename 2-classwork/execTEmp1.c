#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
   int num;
   char strng[10];

   printf("before exec my ID is %d\n", getpid());
   printf("My parent process's ID is %d\n", getppid());

   printf("Enter a number\n");
   scanf("%d", &num);
   /* Converting ineger to string */
   sprintf(strng, "%d", num);
   printf("exec starts\n");
   /* Replace <PATH> by current path in which ex2 is there */
   execl("/home/shubham/Documents/LI-X/2-classwork/ex2      ", "ex2", strng, (char *)0);
   printf("this won't be printed\n");
   return 0;
}