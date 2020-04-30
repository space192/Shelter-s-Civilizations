#include "../prototypes.h"


void initSeqM(BITMAP* tableauSeq[NB_SEQM])
{
    int i = 0;
    char nomFichier[20];

    for (i = 0; i<NB_SEQM; i++)
    {
//        sprintf(nomFichier,"image/ennemi/Ennemi %d.bmp", i+1);
          sprintf(nomFichier,"Ennemi %d.bmp", i+1);

//        printf("nom fichier : %s\n", nomFichier);
        tableauSeq[i] = load_bitmap(nomFichier, NULL);
        if (!tableauSeq[i])
        {
            allegro_message("pas pu trouver %s", nomFichier);
            exit(EXIT_FAILURE);
        }
    }
}

void imageAfficheMechant(t_ennemi *elemA, BITMAP* seqMechant[NB_SEQM])
{
    int imgx = 0, imgy = 0, imgCourrante = 0;
    //BITMAP* imgDecoup = NULL;

    elemA->cmptImg++; //on incrémente le compteur d'img
    if(elemA->cmptImg >= elemA->tmpImg)
    {
        elemA->imgA++; //si le compteur a atteint le nombre demandé passe à l'img suivante dans la séquence

        if(((elemA->type == 3)&&(elemA->imgA >= 30))||((elemA->type <3)&&(elemA->imgA >= 16)))
            elemA->imgA = 0;
    }

    //printf("mechant%d type%d imgA%d  imgx %d  imgy%d\n", elemA->nbE, elemA->type, elemA->imgA, elemA->imgX, elemA->imgY);

    imgCourrante = elemA->imgA;

    if(elemA->type == 2)
    {
        if(imgCourrante >= 30)
            imgCourrante = 0;

        imgx = imgCourrante*48;
        imgy = elemA->angle*68;
    }
    else if(elemA->type == 1)
    {
        if(imgCourrante >= 8) //si l'image courante est supérieure à 8, il faut aller a la ligne en dessous
        {
            imgCourrante = imgCourrante - 8;
            imgy = 1;
        }

        if(imgCourrante >= 16)
            imgCourrante = 0;

        imgx = imgCourrante*248;
        imgy = (imgy + 2*elemA->angle)*220;
    }
    else if(elemA->type == 0)
    {
        if(imgCourrante >= 8) //si l'image courante est supérieure à 8, il faut aller a la ligne en dessous
        {
            imgCourrante = imgCourrante - 8;
            imgy = 1;
        }

        if(imgCourrante >= 16)
            imgCourrante = 0;

        imgx = imgCourrante*202;
        imgy = (imgy + 2*elemA->angle)*158;
    }

    elemA->imgX = imgx;
    elemA->imgY = imgy;

}

/*
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

void initSeqM(t_sequence tableauSeq[NB_SEQ])
{
    int i = 0;
    for (i = 0; i<NB_SEQ; i++)
    {
        //printf("charger seq %d\n", i);
        chargerSequence(&tableauSeq[i]); //on charge toutes les séquences 1 par 1
    }
}
*/
