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
int online;
void connexionReseau(int menu, char nom[100], int score);
void lancer_Reseau();
void fermer_reseau();
void check_online();

#endif
