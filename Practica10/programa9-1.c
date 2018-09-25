#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

#define MAX 1453

int puerto = 7200;


int main(void)
{
   int num[2];
   char newNum[MAX];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   unsigned char aux[4];
   int nBytes = 0;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);

   //printf("Size of puerto: \t %lu \n", sizeof(puerto));

   //printf("Before htons puerto: \t %x \n", puerto);
   
   // se asigna una direccion al socket del servidor
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);

   //printf("After htons puerto: \t %x \n", htons(puerto));

   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   printf("1\n");

   while(1) {
      printf("Esperando...\n");
      nBytes = recvfrom(s, (char *) num, MAX*sizeof(char), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      printf("Recibi %d\n", nBytes);
      //res = num[0] + num[1];
      res = 2;
      memcpy(aux, &msg_to_client_addr.sin_addr.s_addr, 4);
      printf("IP: %d.%d.%d.%d\n", aux[0], aux[1], aux[2], aux[3]);
      printf("Puerto: %d\n", ntohs(msg_to_client_addr.sin_port));
      
      // envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente 
      //sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}

