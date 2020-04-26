#include "../prototypes.h"

t_listedef *initialisationDef()
{
    t_listedef *liste = malloc(sizeof(t_listedef));
    if(liste == NULL)
    {
        allegro_message("erreur d'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    liste->premier = NULL;
    return liste;
}

void ajoutDef(t_listedef *liste, int type, int x, int y)
{
    t_defense *defense = malloc(sizeof(t_defense));
    if(liste == NULL || defense == NULL)
    {
        allegro_message("erreur d'allocation dynamique liste chainée");
        exit(EXIT_FAILURE);
    }
    else
    {
        defense->liste = malloc(sizeof(t_listeBalle));
        if(defense->liste == NULL)
        {
            allegro_message("erreur d'allocatin dynamique liste chainée");
            exit(EXIT_FAILURE);
        }
        else
        {
            defense->liste->premier = NULL;
        }
        defense->suivant = liste->premier;
        liste->premier = defense;
        defense->type = type;
        defense->x = x;
        defense->y = y;
        defense->valeurCanon = 0;
        defense->angle = 64;
        switch(type)
        {
        case 1:
            {
                defense->radius = 100;
                defense->cadenceMax = 60;
                defense->degat = 20;
                break;
            }
        case 2:
            {
                defense->radius = 140;
                defense->cadenceMax = 40;
                defense->degat = 14;
                break;
            }
        case 3:
            {
                defense->radius = 120;
                defense->cadenceMax = 20;
                defense->degat = 3;
                break;
            }
        case 4:
            {
                defense->radius = 200;
                defense->cadenceMax = 102;
                defense->degat = 60;
                break;
            }
        case 5:
            {
                defense->radius = 240;
                defense->cadenceMax = 30;
                defense->degat = 30;
                break;
            }
        case 6:
            {
                defense->radius = 220;
                defense->cadenceMax = 10;
                defense->degat = 9;
                break;
            }
        }
    }
}

void ajoutBalle(t_listeBalle *defense)
{
    if(defense == NULL)
    {
        allegro_message("erreur la liste defense n'existe pas:/");
        exit(EXIT_FAILURE);
    }
    else
    {
        t_balle *balle = malloc(sizeof(t_balle));
        if(balle == NULL)
        {
            allegro_message("erreur d'allocation dynamique");
            exit(EXIT_FAILURE);
        }
        else
        {
            balle->pass = 0;
            balle->suivant = defense->premier;
            defense->premier = balle;
        }
    }
}

