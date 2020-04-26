#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#include "logg.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <math.h>
#include "Police/allegttf.h"
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
    int POL;
    int centre;
    int numero;
    int type;
    int cmptDx, tmpDx;
    int cmptDy, tmpDy;
    int imgA;
    int cmptImg, tmpImg;
    int angle;
    t_ennemi *suivant;
};
typedef struct listeMechant
{
    int nbElement;
    int cmpt, tmp;
    t_ennemi *premier;
}t_listeMechant;

typedef struct Bouton
{
    int x;
    int y;
    int tx;
    int ty;
}t_bouton;

typedef struct sequence
{
    char* nomFichier;
    int nbImg;
    int tx, ty;
    int nbCol;
    BITMAP** img;

} t_sequence;

#define NB_SEQ 8

#define NB_MECHANT 10
#define VITESSE 2
#define ESP_X 10
#define ESP_Y 10
#endif // STRUCTURES_H_INCLUDED




