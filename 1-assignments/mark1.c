#define _XOPEN_SOURCE
       #include <stdio.h>
       #include <stdlib.h>
       #include <string.h>
       #include <time.h>

    
      int main(int argc, char *argv[])
       {
           struct tm tm;
           char buf[255];

           memset(&tm, 0, sizeof(struct tm));
           strptime(argv[1], "%Y-%m-%d %l:%M:%S %p %c", &tm);
           strftime(buf, sizeof(buf), "%d %b %Y %I:%M:%S %p", &tm);
           //time_t sec = mktime(&tm);
           //printf("%s\n",ctime(&sec));
           puts(buf);
           exit(EXIT_SUCCESS);
       }