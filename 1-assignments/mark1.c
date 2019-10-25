#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

    int flag = 0;
    void my_handler(int signum)
    {
        flag = 1;
        //printf("\a");
        //system("ffplay 2.mp3 -nodisp -autoexit -loop 4");
        system("ffplay 2.mp3 -nodisp -loop 15 -autoexit -nostats -hide_banner -loglevel quiet &");
        //system("vlc 2.mp3 -nodisp -autoexit");
        printf("\n");
    }
    
      int main(int argc, char *argv[])
       {
            struct tm tm = {0};
            struct tm *temp;
            char buf[55], buff[55];
            time_t seconds;

            memset(&tm, 0, sizeof(struct tm));
            //system time
            time_t x = time(&seconds);
            //printf("%ld\n",x);
            temp = localtime(&seconds);
            if(strlen(argv[1]) != 19)
            {
                tm.tm_mon = temp->tm_mon;
                tm.tm_year = temp->tm_year;
                tm.tm_mday = temp->tm_mday;
                strptime(argv[1], "%H:%M:%S", &tm);    
            }
            else
            {
                strptime(argv[1], "%d-%m-%Y %H:%M:%S", &tm);
            }
            

            //input time
            
            strftime(buf, sizeof(buf), "%d %b %Y %H:%M:%S", &tm);
            time_t var1 = mktime(&tm);
            //time_t y = time(&var1);
            printf("%ld\n",var1);
            
            
            strftime(buff, sizeof(buff), "%d %b %Y %H:%M:%S %p", temp);
            //strftime(buff, sizeof(buff), "%d %b %Y %I:%M %p", temp);
            time_t var2 = mktime(temp);
            printf("%ld\n",var2);
            time_t remaining = var1 - var2;
            printf("remaining seconds %ld\n", remaining);

            signal(SIGALRM, my_handler);
            alarm(remaining);
           //strftime(buf, sizeof(buf), "%T %D", &tm);
           //time_t sec = mktime(&tm);
           //printf("%s\n",ctime(&sec));

           puts(buf);
           puts(buff);
           int count = 0;
           int resp = 0;
           while(1)
           {
               printf("ALARM IS RUNNING... %d\n",count++);
               sleep(1);
               if(flag == 1)
               {
                   printf("\n\n\t\t\t\tALARM GONE OFF\n\t\t\t\tCHOOSE AN OPTION\n\n");
                   printf("\t\t\t1.SNOOZE\t\t2.EXIT\n");
                   scanf("%d", &resp);
                   if(resp == 1)
                   {
                       system("killall ffplay");
                       printf("SNOOZING FOR 5 SECONDS\n");
                       flag = 0;
                       alarm(5);
                       signal(SIGALRM, my_handler);
                   }
                   else if(resp == 2)
                   {
                       system("killall ffplay");
                       break;
                   }
                   
               }
           }
           exit(EXIT_SUCCESS);
       }
