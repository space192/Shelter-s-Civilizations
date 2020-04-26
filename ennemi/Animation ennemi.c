#include "../prototypes.h"

void chargerSequence(t_sequence *sqc)
{
    int i = 0, ix = 0, iy = 0;
    int sx, sy; //position dans le fichier source de la sequence
    BITMAP* annim;
    //on charge le fichier avec l'annimation
    annim = load_bitmap(sqc->nomFichier, NULL);

    if(annim == NULL)
    {
        allegro_message("Impossible de charger %s", sqc->nomFichier);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    sqc->img = (BITMAP**)malloc(sizeof(BITMAP*)); //alloue un espace memoire pour tout le tableau

    for(i = 0; i<sqc->nbImg; i++)
    {
        sx = ix*sqc->tx;
        sy = iy*sqc->ty;

        sqc->img[i]=create_bitmap(sqc->tx,sqc->ty); //alloue un espace memoire pour cahque img de la sequence
        blit(annim, sqc->img[i], sx, sy, 0, 0, sqc->tx, sqc->ty); //on colle chaque img de la sequence dans le tableau

        ix++;
        if(ix >= sqc->nbCol)
        {
            ix = 0;
            iy++;
        }
    }
    destroy_bitmap(annim); //on libère l'espace memoire de la bitmap
}

void initSeq(t_sequence tableauSeq[NB_SEQ])
{
    int i = 0;
    for (i = 0; i<NB_SEQ; i++)
    {
        //printf("charger seq %d\n", i);
        chargerSequence(&tableauSeq[i]); //on charge toutes les séquences 1 par 1
    }
}
