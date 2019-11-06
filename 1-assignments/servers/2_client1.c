/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t020.c
 *   Title          : IPC mechanism - Usage of TCP socket - Client 
 *   Description    : Sockets offer interfaces with TCP/IP stack inside Linux 
 *                    Kernel, using which remote connections can be established
 *                    over a network. This program demonstrates various steps
 *                    to establish successful three-way handshake as a client. 
 *
 *----------------------------------------------------------------------------*/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <arpa/inet.h>

#define SERVER_IP_ADDRESS 	"127.0.0.1"
#define SERVER_PORT       	8080
#define CLIENT_BUFF_SIZE	20
#define SERVER_BUFF	10

int main()
{
    int sock_fd,c_size, i;
    char client_buff[CLIENT_BUFF_SIZE];
    char serv_buffer[SERVER_BUFF];
    struct sockaddr_in serv_addr; 

    // Create a client socket 
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error: Could not create socket\n");
        return 1;
    } 

    // Binding with client socket is optional here

    // Populate it with server's address details 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT); 
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);

    //Get the message from client
    printf("Enter the message you want to sent to server:\n");
    gets(client_buff);
    char input[20];
    strcpy(input, client_buff);
    //Loop to check for operator
    for(i = 0; i < strlen(input); i++)
    {
        if(!(isdigit(input[i])))
        {
            break;
        }
        
    }
    if(connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) != 0)
    {
        perror("connect");
        printf("Error connecting to server\n");
        close(sock_fd);
        exit(1);
    }
    else
	printf("Connection successful\n");

   //Send the message to server 
    printf("%c\n",client_buff[i]);
    c_size = send(sock_fd, &client_buff[i], 1, 0);

    if(c_size > 0)
	    printf("Message sent to server successsfully, please check\n");
    else
	    printf("Error: Message send\n");
    
    recv(sock_fd, (void *) serv_buffer,SERVER_BUFF,0);
    printf("Receved port %s\n", serv_buffer);
    close(sock_fd);


/////////////////////////////////////////////////////////////////////////////////////////

    /* Create a client socket */
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error: Could not create socket\n");
        return 1;
    } 

    /* Binding with client socket is optional here */

    /* Populate it with server's address details */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons((uint16_t)(atoi(serv_buffer))); 
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);

    /* Get the message from client */
    //printf("Enter the message you want to sent to server:\n");
    //gets(client_buff);

    if(connect(sock_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) != 0)
    {
        perror("connect");
        printf("Error connecting to server\n");
        close(sock_fd);
        exit(1);
    }
    else
	    printf("Connection successful\n");

    /* Send the message to server */
    //printf("%c\n",client_buff[1]);
    c_size = send(sock_fd, client_buff, strlen(client_buff) + 1, 0);

    if(c_size > 0)
	    printf("Message sent to server successsfully, please check\n");
    else
	    printf("Error: Message send\n");
    
    recv(sock_fd, (void *) serv_buffer,SERVER_BUFF,0);
    printf("Receved data %s\n", serv_buffer);
    close(sock_fd);


}
