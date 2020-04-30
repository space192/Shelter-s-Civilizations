#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED


typedef struct joueurClassement t_joueurClassement;
struct joueurClassement
{
    char prenom[100];
    int score;
    t_joueurClassement *suivant;
};

int classement;
t_joueurClassement tab[20];
void connexionReseau(int menu, char nom[100], int score);

#endif
