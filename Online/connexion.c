#include "socket.h"
#include <winsock2.h>
#include <stdio.h>
typedef int socklen_t;
#include <errno.h>
#define PORT 23


void connexionReseau(int menu, char nom[100], int score)
{
    SOCKET connection;
    SOCKADDR_IN connectParam;
    t_joueurClassement joueur;
    if(menu == 2)
    {
        strcpy(joueur.prenom, nom);
        joueur.score = score;
    }
    if((connection=socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        printf("error socket failed()");
    }
    connectParam.sin_family = AF_INET;
    connectParam.sin_port = htons(PORT);
    connectParam.sin_addr.s_addr = inet_addr("176.185.237.183");
    if(connect(connection, (SOCKADDR*)&connectParam, sizeof(connectParam))==-1)
    {
        printf("error connection failed");
    }
    else
    {
        send(connection, (char*)&menu, sizeof(int), 0);
        if(menu == 1)
        {
            recv(connection, (char*)tab, 20*sizeof(t_joueurClassement), 0);
        }
        else if(menu == 2)
        {
            send(connection, (char*)&joueur, sizeof(t_joueurClassement), 0);
            recv(connection, (char*)&classement, sizeof(int), 0);
        }
        else if(menu == 3)
        {
            recv(connection, (char*)&online, sizeof(int), 0);
        }
    }
    closesocket(connection);
}


void lancer_Reseau()
{
    #if defined (WIN32)
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,2), &WSAData);
#endif
}

void fermer_reseau()
{
    #if defined (WIN32)
            WSACleanup();
    #endif
}
