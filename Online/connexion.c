#include "socket.h"
#include <winsock2.h>
#include <stdio.h>
typedef int socklen_t;
#include <errno.h>
#define PORT 23


void connexionReseau(int menu, char nom[100], int score)
{
    SOCKET connection;              //declaration variable reseau
    SOCKADDR_IN connectParam;
    t_joueurClassement joueur;
    if(menu == 2)                   //test pour les choix des action a effectuer plus tard dans le programme
    {
        strcpy(joueur.prenom, nom);
        joueur.score = score;
    }
    connection=socket(AF_INET, SOCK_STREAM, 0);
    connectParam.sin_family = AF_INET;              //gestion des parametre de connection (AF_INET = IPV4)
    connectParam.sin_port = htons(PORT);            //gestion du port utilisé(port 23 TELNET)
    connectParam.sin_addr.s_addr = inet_addr("176.185.237.183"); //ip du serveur où sont stocké les scores des joueurs
    if(connect(connection, (SOCKADDR*)&connectParam, sizeof(connectParam))==-1) //connexion au serveur
    {

    }
    else
    {
        send(connection, (char*)&menu, sizeof(int), 0); //envoie de l'intention du client
        if(menu == 1)
        {
            recv(connection, (char*)tab, 20*sizeof(t_joueurClassement), 0); //si menu == 1 recevoir le classement du leaderboard sur le jeu
        }
        else if(menu == 2)
        {
            send(connection, (char*)&joueur, sizeof(t_joueurClassement), 0); //si menu == 2 envoie des informations du joueur au server
            recv(connection, (char*)&classement, sizeof(int), 0);            //reception du classemenent du joueur afin de savoir si il a battu son score
        }
        else if(menu == 3)
        {
            recv(connection, (char*)&online, sizeof(int), 0);               //reception du nombre de joueur connecté au server
        }
    }
    closesocket(connection);                                                //fermeture du socket avec le server
}


void lancer_Reseau()
{
#if defined (WIN32)
    WSADATA WSAData;                                                        //ouverture des socket sur windows
    WSAStartup(MAKEWORD(2,2), &WSAData);
#endif
}

void fermer_reseau()
{
#if defined (WIN32)
    WSACleanup();                                                   //fermeture des socket sur windows
#endif
}
