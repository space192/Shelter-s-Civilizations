#include "../prototypes.h"

void affichageBoutton(BITMAP *image,BITMAP *buffer,int etat, int x, int y, float zoom)
{
    BITMAP *temp = create_bitmap(image->w, (image->h)/3);
    //printf("tx: %d et ty %d\n", temp->w, temp->h);
    int posx=0,posy=0;
    switch(etat)
    {
    case 1: //bouton desactivé
        {
            posy = 0;
            break;
        }
    case 2: //bouton actié
        {
            posy =image->h/3;
            break;
        }
    case 3: //sur le bouton
        {
            posy =2*(image->h/3);
        }
    }
    blit(image, temp, posx, posy, 0,0,temp->w, temp->h);
    stretch_blit(temp, buffer, 0,0,temp->w, temp->h, x,y, temp->w*zoom, temp->h*zoom);
    destroy_bitmap(temp);
}

void affichageCheck(BITMAP *image, BITMAP *buffer, int etat, int x, int y)
{
    BITMAP *temp = create_bitmap(image->w, (image->h)/2);
    int posy=0;
    if(etat == 1)
    {
        posy = 20;
    }
    else
    {
        posy=0;
    }
    blit(image, temp, 0, posy, 0,0,temp->w, temp->h);
    stretch_blit(temp, buffer, 0,0,temp->w, temp->h, x, y, temp->w*2, temp->h*2);
    destroy_bitmap(temp);
}


void MenuPrincipale(BITMAP *buffer, BITMAP *image[12], int *scene, int *compteur, int sauvegarde)
{
    if((mouse_x>= 390 && mouse_y>=400)&&(mouse_x <=890 && mouse_y <= 450)) //nouvelle Partie
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 17)
            {
                *scene = 2;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
        }
        affichageBoutton(image[0], buffer, 3, 390,400, 2.5);
    }
    else
    {
        affichageBoutton(image[0], buffer, 2, 390,400, 2.5);
    }
    if(sauvegarde == 0)                                                 //chargement Partie
    {
        affichageBoutton(image[1], buffer, 1, 390,480, 2.5);
    }
    else if(sauvegarde == 1 && mouse_x >= 390 && mouse_y>=480 && mouse_x <=890 && mouse_y <=530)
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                *scene = 3;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
        }
        affichageBoutton(image[1], buffer, 3, 390, 480, 2.5);
    }
    else
    {
        affichageBoutton(image[1], buffer,2, 390,480, 2.5);
    }
    if((mouse_x>= 390 && mouse_y>=560)&&(mouse_x <=890 && mouse_y <= 610)) //Score en ligne
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                *scene = 4;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
        }
        affichageBoutton(image[2], buffer, 3, 390, 560, 2.5);
    }
    else
    {
        affichageBoutton(image[2],buffer,2,390,560, 2.5);
    }
    if((mouse_x>= 390 && mouse_y>=640)&&(mouse_x <=890 && mouse_y <= 690)) //exit
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                *scene = 5;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
        }
        affichageBoutton(image[3], buffer, 3, 390, 640, 2.5);
    }
    else
    {
        affichageBoutton(image[3],buffer,2,390,640, 2.5);
    }
}



void NouvellePartie(BITMAP *buffer, BITMAP *image[12], int *scene, int *compteur, int sauvegarde, int *tuto, int *ecrire, char *chaine, int *pos)
{
    masked_stretch_blit(image[10], buffer, 0,0,image[10]->w, image[10]->h, 390,400, image[10]->w*2, image[10]->h*2);
    if(mouse_x>=800 && mouse_y >=535 && mouse_x<=840 && mouse_y <=575)
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 20)
            {
                if(*tuto == 1)
                {
                    *tuto = 0;
                }
                else if(*tuto == 0)
                {
                    *tuto = 1;
                }
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
    }
    affichageCheck(image[11], buffer, *tuto, 800, 535);
    if(mouse_x >= 415 && mouse_y >= 460 && mouse_x <=850 && mouse_y <=500)
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 20)
            {
                *ecrire = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur +1;
            }
            rest(4);
        }
    }
    else
    {
        if(mouse_b & 1)
        {
            if(*compteur >=20)
            {
                *ecrire = 0;
                *compteur =0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
    }
    if(*ecrire == 1)
    {
        toucheClavier(chaine, buffer, pos);
    }
    else if(*ecrire == 0)
    {
        //BITMAP *temp =create_bitmap(435, 17);
        //rectfill(temp,0,0,435,17,makecol(0,0,0));
        textout_ex(buffer, font, chaine, 420, 474, makecol(255,255,255), -1);
        //stretch_blit(temp, buffer, 0,0,temp->w,temp->h, 416, 462, temp->w, temp->h*2);
        //destroy_bitmap(temp);
    }
    if(mouse_x >= 420 && mouse_y >= 690 && mouse_x <=620 && mouse_y <=710)
    {
        if(mouse_b & 1)
        {
            if(*compteur >=20)
            {
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur +1;
            }
            rest(4);
        }
        affichageBoutton(image[9], buffer, 3, 420, 690, 2.0);
    }
    else
    {
        affichageBoutton(image[9], buffer, 2, 420, 690, 2.0);
    }
    if(mouse_x >= 660 && mouse_y >= 690 && mouse_x <=860 && mouse_y <=710)
    {
        if(mouse_b & 1)
        {
            if(*compteur >=20)
            {
                dechargementImage(image);
                jeu(0);
                chargementImageMenu(image);
                rest(100);
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur +1;
            }
            rest(4);
        }
        affichageBoutton(image[8], buffer, 3, 660, 690, 2.0);
    }
    else
    {
        affichageBoutton(image[8], buffer, 2, 660, 690, 2.0);
    }
}


void ChargerUnePartie(BITMAP *buffer, BITMAP *image[12], int *scene, int *compteur, int *sauvegarde)
{
    if((mouse_x>= 390 && mouse_y>=400)&&(mouse_x <=890 && mouse_y <= 450)) //niveau 1
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 17)
            {
                //lance le jeux avec la sauvegarde du niveau 1
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
        affichageBoutton(image[4], buffer, 3, 390,400, 2.5);
    }
    else
    {
        affichageBoutton(image[4], buffer, 2, 390,400, 2.5);
    }
    if(mouse_x >= 390 && mouse_y>=480 && mouse_x <=890 && mouse_y <=530) //niveau 2
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                //lancement du jeu avec la sauvegarde du niveau 2
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
        affichageBoutton(image[5], buffer, 3, 390, 480, 2.5);
    }
    else
    {
        affichageBoutton(image[5], buffer,2, 390,480, 2.5);
    }
    if((mouse_x>= 390 && mouse_y>=560)&&(mouse_x <=890 && mouse_y <= 610)) //Niveau 3
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                //lancement du jeu avec la sauvegarde du niveau 3
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
        affichageBoutton(image[6], buffer, 3, 390, 560, 2.5);
    }
    else
    {
        affichageBoutton(image[6],buffer,2,390,560, 2.5);
    }
    if((mouse_x>= 390 && mouse_y>=640)&&(mouse_x <=890 && mouse_y <= 690)) //endless mode
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                dechargementImage(image);
                jeu(4);
                chargementImageMenu(image);
                rest(100);
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
        affichageBoutton(image[7], buffer, 3, 390, 640, 2.5);
    }
    else
    {
        affichageBoutton(image[7],buffer,2,390,640, 2.5);
    }
}
