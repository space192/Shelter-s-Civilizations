#include "socket.h"
#include <winsock2.h>
#include <stdio.h>
typedef int socklen_t;
#include <errno.h>
#define PORT 23


void connexionReseau(int menu, char nom[100], int score)
{
#if defined (WIN32)
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2,2), &WSAData);
#endif
    SOCKET connection;
    SOCKADDR_IN connectParam;
    t_joueurClassement joueur;
    //strcpy(joueur.prenom, nom);
    //joueur.score = score;
    int i;
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
            for(i=0; i < 20; i++)
            {
                printf("nom:%s et score:%d\n", tab[i].prenom, tab[i].score);
            }
        }
        else if(menu ==2)
        {
            send(connection, (char*)&joueur, sizeof(t_joueurClassement), 0);
            recv(connection, (char*)&classement, sizeof(int), 0);
        }
    }
    closesocket(connection);
    #if defined (WIN32)
            WSACleanup();
    #endif
}
