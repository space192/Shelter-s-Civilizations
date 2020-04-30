#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <math.h>
#include <string.h>

typedef struct Joueur
{
    int or;
    int metal;
    int pierre;
} t_joueur;

typedef struct BatimentP
{
    int x;
    int y;
    int imageX;
    int imageY;
} t_batimentP;

typedef struct borneCoordonnees
{
    int xDeb;
    int xFin;
    int yDeb;
    int yFin;
} t_borne;

typedef struct MAILLONBR t_maillonBR;
struct MAILLONBR
{
    int tic;
    int ticMax;
    int type;
    int niveau;
    int x, y;
    t_maillonBR *suivant;
};

typedef struct MAILLONEDD t_maillonEDD;
struct MAILLONEDD
{
    int emplacementDisponible;
    int afficherFondation;
    int x;
    int y;
    int numeroEDD;
    t_maillonEDD *suivant;
};

typedef struct ListeBR
{
    t_maillonBR *premier;
} t_listeBR;

typedef struct ListeEDD
{
    t_maillonEDD *premier;
} t_listeEDD;

typedef struct balle t_balle;
struct balle
{
    int x;
    int y;
    int tx;
    int ty;
    int dx;
    int dy;
    int degat;
    int angle;
    int millieuAvantX;
    int millieuAvantY;
    int pass; //pass du calcul de l'angle pour la balle
    t_balle *suivant;
};

typedef struct listeBalle
{
    t_balle *premier;
}t_listeBalle;

typedef struct defense t_defense;
struct defense
{
    int x;
    int y;
    int radius;
    int degat;
    int POL; //point of life
    int centre;
    int test;
    int angle;
    int type;
    int valeurCanon; //timer pour la creation d'une nouvelle balle
    int cadenceMax; //valeur max du timer pour la candence de tir
    int target; //numero de l'ennmeie visé par la tourelle
    t_defense *suivant;
    t_listeBalle *liste;
};

typedef struct listedef
{
    t_defense *premier;
}t_listedef;

typedef struct ennemi t_ennemi;
struct ennemi
{
    int x, y;
    int depx, depy;
    int tx, ty;
    int centre;
    int numero;
    int type; //c'est le type de l'ennemi

    int cmptDx, tmpDx;
    int cmptDy, tmpDy;

    int imgA; //c'est l'image actuelle dans la séquence
    int imgX, imgY;
    int cmptImg, tmpImg; //c'est le compteur pour gérer la vitesse de l'animation

    int pvM; //point de vie

    int degatsM; //different degat en fonction du type d'ennemi
    int cmptDeg, tmpDeg; //different

    int angle;

    t_ennemi *suivant;
};

typedef struct listeMechant
{
    int nbElement; //nb de mechant qui sont sur le jeu
    int cmptG, tmpG; //compteur de generation des mechant

    int nbVague;
    int vagueM; //numero de la vague

    int typeMechant[3];
    int pvM[3];
    int degatsM[3]; //different degat en fonction du type d'ennemi
    int tmpDegat[3]; //differentes vitesse d'attaques des ennemis en fonction de leur type

    int nbAfaire; //c'est le nombre de mechant qui doivent etre créer dans la vagque
    int nbFait; //C'est le nombre de mechant qui ont été créer
    int vagueFinis; //0 = NON, 1 = OUI
    int cmptV, tmpV; //compteur de temps entre les vagues

    int listeActua; //booleen qui permet de savoir si la liste est actualise quand on change de niveau

    t_ennemi *premier;

}t_listeMechant;

typedef struct classement
{
    int x;
    int y;
    int score;
    char chaine[100];
}t_classement;

#define NB_SEQM 3

#define NB_MECHANT 10
#define NB_MECHANT_MAX 50 //nombre de mechant simultanement sur la map

#define VITESSE 2
#define ESP_X 30
#define ESP_Y 30

#endif // STRUCTURES_H_INCLUDED




