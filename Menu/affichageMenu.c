#include "../prototypes.h"
#include "../Online/socket.h"

void affichageBoutton(BITMAP *image,BITMAP *buffer,int etat, int x, int y, float zoom) //gestion des differents bouton des menu
{
    BITMAP *temp = NULL;
    if(etat < 4)
    {
        temp = create_bitmap(image->w, (image->h)/3);
    }
    else
    {
        temp = create_bitmap(image->w, (image->h)/2);
    }
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
        break;
    }
    case 4:
    {
        posy=0;
        break;
    }
    case 5:
    {
        posy = image->h/2;
        break;
    }
    }
    blit(image, temp, posx, posy, 0,0,temp->w, temp->h);
    stretch_blit(temp, buffer, 0,0,temp->w, temp->h, x,y, temp->w*zoom, temp->h*zoom);
    destroy_bitmap(temp);
}

void affichageCheck(BITMAP *image, BITMAP *buffer, int etat, int x, int y) //gestion de l'afficgage du bouton tuto
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


void MenuPrincipale(BITMAP *buffer, BITMAP *image[37], int *scene, int *compteur, int sauvegarde) //gestion des boutons du menu principale redirection autre programme
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
    else if(sauvegarde >= 1 && mouse_x >= 390 && mouse_y>=480 && mouse_x <=890 && mouse_y <=530)
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
                connexionReseau(1, NULL, 0);
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
    if((mouse_x>= 390 && mouse_y>=640)&&(mouse_x <=890 && mouse_y <= 690)) //wiki
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                *scene = 7;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
        }
        affichageBoutton(image[19], buffer, 3, 390, 640, 2.5);
    }
    else
    {
        affichageBoutton(image[19],buffer,2,390,640, 2.5);
    }
    if((mouse_x>= 390 && mouse_y>=720)&&(mouse_x <=890 && mouse_y <= 770)) //exit
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
        affichageBoutton(image[3], buffer, 3, 390, 720, 2.5);
    }
    else
    {
        affichageBoutton(image[3],buffer,2,390,720, 2.5);
    }
}


//gestion de la creation de nouvelle partie avec l'entrée du prenom, ainsi que la case permettant d'acceder au tutoriel
void NouvellePartie(BITMAP *buffer, BITMAP *image[37], int *scene, int *compteur, int sauvegarde, int *tuto, int *ecrire, char *chaine, int *pos, int *clic, int *score)
{
    masked_stretch_blit(image[10], buffer, 0,0,image[10]->w, image[10]->h, 390,400, image[10]->w*2, image[10]->h*2);
    if(mouse_x>=800 && mouse_y >=535 && mouse_x<=840 && mouse_y <=575)
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 17)
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
        toucheClavier(chaine, buffer, pos, clic);
    }
    else if(*ecrire == 0)
    {
        textout_ex(buffer, font, chaine, 420, 474, makecol(255,255,255), -1);
    }
    if(mouse_x >= 420 && mouse_y >= 690 && mouse_x <=620 && mouse_y <=710)
    {
        if(mouse_b & 1)
        {
            if(*compteur >=20)
            {
                *scene = 1;
                chaine[0] = '\0';
                *pos = 0;
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
                *score = jeu(0, *tuto, chaine);
                chargementImageMenu(image);
                rest(100);
                *scene = 6;
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

//gestion des differentes sauvegarde a partir des fichiers pour les 4 niveaux differents
void ChargerUnePartie(BITMAP *buffer, BITMAP *image[37], int *scene, int *compteur, int *sauvegarde, int *score, char chaine[100])
{
    recupererNom(chaine);
    if(*sauvegarde >= 1)
    {
        if((mouse_x>= 390 && mouse_y>=400)&&(mouse_x <=890 && mouse_y <= 450)) //niveau 1
        {
            if(mouse_b & 1)
            {
                if(*compteur >= 17)
                {
                    dechargementImage(image);
                    *score = jeu(1, 0, chaine);
                    chargementImageMenu(image);
                    rest(100);
                    *scene = 6;
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
    }
    else
    {
        affichageBoutton(image[4], buffer, 1, 390, 400, 2.5);
    }
    if(*sauvegarde >= 2)
    {
        if(mouse_x >= 390 && mouse_y>=480 && mouse_x <=890 && mouse_y <=530) //niveau 2
        {
            if(mouse_b & 1)
            {
                if(*compteur >=17)
                {
                    dechargementImage(image);
                    *score = jeu(2, 0, chaine);
                    chargementImageMenu(image);
                    rest(100);
                    *scene = 6;
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
    }
    else
    {
        affichageBoutton(image[5], buffer, 1, 390, 480, 2.5);
    }
    if(*sauvegarde >= 3)
    {
        if((mouse_x>= 390 && mouse_y>=560)&&(mouse_x <=890 && mouse_y <= 610)) //Niveau 3
        {
            if(mouse_b & 1)
            {
                if(*compteur >=17)
                {
                    dechargementImage(image);
                    *score = jeu(3, 0, chaine);
                    chargementImageMenu(image);
                    rest(100);
                    *scene = 6;
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
    }
    else
    {
        affichageBoutton(image[6], buffer, 1, 390, 560, 2.5);
    }
    if(*sauvegarde >= 4)
    {
        if((mouse_x>= 390 && mouse_y>=640)&&(mouse_x <=890 && mouse_y <= 690)) //endless mode
        {
            if(mouse_b & 1)
            {
                if(*compteur >=17)
                {
                    dechargementImage(image);
                    *score = jeu(4, 0, chaine);
                    chargementImageMenu(image);
                    rest(100);
                    *scene = 6;
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
    else
    {
        affichageBoutton(image[7], buffer, 1, 390, 640, 2.5);
    }
    if((mouse_x>=390 && mouse_y >=720) && (mouse_x <= 890 && mouse_y <=770))
    {
        if(mouse_b & 1)
        {
           if(*compteur >= 17)
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
        affichageBoutton(image[12], buffer, 3, 390, 720, 2.5);
    }
    else
    {
        affichageBoutton(image[12], buffer, 2, 390, 720, 2.5);
    }
}

//gestion de l'affichage du leaderboard du jeu grace a une requette au serveur
void leaderBoard(BITMAP *buffer, BITMAP *image[37], int *scene, int *compteur, t_classement *tableau, int *sourisY,int *y)
{
    BITMAP *temp = create_bitmap(402, 800);
    int i, ytemp = 0;
    for(i=0;i < 20 ; i++)
    {
        tableau[i].x =0;
        tableau[i].y =ytemp;
        ytemp+=40;
        strcpy(tableau[i].chaine, tab[i].prenom);
        tableau[i].score = tab[i].score;
        stretch_blit(image[14], temp, 0,0,image[14]->w, image[14]->h, tableau[i].x, tableau[i].y, image[14]->w*2.01, image[14]->h*2);
        textprintf_ex(temp, font, tableau[i].x+15, tableau[i].y+20, makecol(255,255,255), -1, "#%d", i+1);
        textprintf_ex(temp, font, tableau[i].x+45,tableau[i].y+20, makecol(255,255,255), -1, "%s", tableau[i].chaine);
        textprintf_ex(temp, font, tableau[i].x+300, tableau[i].y+20, makecol(255,255,255), -1, "score:%d", tableau[i].score);
    }
    blit(temp, buffer, 0,*y,412, 355, 402, 340);
    masked_stretch_blit(image[13], buffer, 0,0,image[13]->w, image[13]->h, 390,300,2.5*image[13]->w, 3.025*image[13]->h);
    if(mouse_b & 1 && mouse_x > 828 && mouse_x < 858 && mouse_y >363 && mouse_y < 662)
    {
        *sourisY = mouse_y-10;
        *y = (mouse_y-354)*1.554-14;
        affichageBoutton(image[15], buffer, 5, 828, *sourisY, 2.5);
    }
    else
    {
        affichageBoutton(image[15], buffer, 4, 828, *sourisY, 2.5);
    }
    textprintf_ex(buffer, font, 0,10,makecol(255,255,255), -1, "%d", *y);
    if((mouse_x>=390 && mouse_y >=950) && (mouse_x <= 890 && mouse_y <=1000))
    {
        if(mouse_b & 1)
        {
           if(*compteur >= 17)
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
        affichageBoutton(image[12], buffer, 3, 390, 950, 2.5);
    }
    else
    {
        affichageBoutton(image[12], buffer, 2, 390, 950, 2.5);
    }
    destroy_bitmap(temp);
}


//gestion de l'entre deux niveau
void passageNiveau(BITMAP *buffer,BITMAP *image[3], int *niveau, int *jeuActif, int *compteur)
{
    if((mouse_x>= 390 && mouse_y>=400)&&(mouse_x <=890 && mouse_y <= 450)) //nouvelle Partie
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 17)
            {
                (*niveau)++;
                *jeuActif = 4;
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
    if(mouse_x >= 390 && mouse_y>=480 && mouse_x <=890 && mouse_y <=530) //quitter et sauvegarder
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                *jeuActif = 2;
                (*niveau)++;
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
    if((mouse_x>= 390 && mouse_y>=560)&&(mouse_x <=890 && mouse_y <= 610)) //Quitter sans sauvegarder
    {
        if(mouse_b & 1)
        {
            if(*compteur >=17)
            {
                *jeuActif = 3;
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
}

//permet de demander a l'utilisateur si il veut envoyer son score au serveur
void envoieScoreServeur(BITMAP *buffer, BITMAP *image[37], int *scene, int *compteur, char chaine[100], int score)
{
    masked_stretch_blit(image[16], buffer, 0,0,image[16]->w, image[16]->h , 340,300,image[16]->w*4, image[16]->h*4);
    textprintf_ex(buffer, font,465,340,makecol(255,255,255), -1, "voulez-vous envoyez le score au serveur %s?", chaine);
    if((mouse_x>= 380 && mouse_y>=455)&&(mouse_x <=620 && mouse_y <= 480)) //non
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 17)
            {
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
        affichageBoutton(image[18], buffer, 3, 380,455, 1.2);
    }
    else
    {
        affichageBoutton(image[18], buffer, 2, 380,455, 1.2);
    }
    if((mouse_x>= 645 && mouse_y>=455)&&(mouse_x <=885 && mouse_y <= 480)) //oui
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 17)
            {
                connexionReseau(2, chaine, score);
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
        affichageBoutton(image[17], buffer, 3, 645,455, 1.2);
    }
    else
    {
        affichageBoutton(image[17], buffer, 2, 645,455, 1.2);
    }
}
//affichage du wiki du jeu
void wiki(BITMAP *buffer, BITMAP *image[37], int *scene, int *compteur, int *article)
{
    if((mouse_b & 1)&&(mouse_x>= 380 && mouse_y>=130)&&(mouse_x <=475 && mouse_y <= 235)) //home WIKI
    {
        *article = 36;
    }
    else if((mouse_b & 1)&&(mouse_x>= 400 && mouse_y>=275)&&(mouse_x <=447 && mouse_y <= 283)) //mine d'or
    {
        *article = 24;
    }
    else if((mouse_b & 1)&&(mouse_x>= 403 && mouse_y>=291)&&(mouse_x <=445 && mouse_y <= 300)) //carriere
    {
        *article = 25;
    }
    else if((mouse_b & 1)&&(mouse_x>= 400 && mouse_y>=307)&&(mouse_x <=450 && mouse_y <= 315)) //fonderie
    {
        *article = 26;
    }
    else if((mouse_b & 1)&&(mouse_x>= 407 && mouse_y>=336)&&(mouse_x <=445 && mouse_y <= 345)) //bertha
    {
        *article = 27;
    }
    else if((mouse_b & 1)&&(mouse_x>= 395 && mouse_y>=352)&&(mouse_x <=455 && mouse_y <= 361)) //laserinator
    {
        *article = 28;
    }
    else if((mouse_b & 1)&&(mouse_x>= 392 && mouse_y>=368)&&(mouse_x <=457 && mouse_y <= 378)) //terminator
    {
        *article = 29;
    }
    else if((mouse_b & 1)&&(mouse_x>= 398 && mouse_y>=383)&&(mouse_x <=450 && mouse_y <= 392)) //les Mines
    {
        *article = 30;
    }
    else if((mouse_b & 1)&&(mouse_x>= 398 && mouse_y>=414)&&(mouse_x <=450 && mouse_y <= 423)) //RadCafard
    {
        *article = 31;
    }
    else if((mouse_b & 1)&&(mouse_x>= 379 && mouse_y>=430)&&(mouse_x <=470 && mouse_y <= 440)) //infected centipede
    {
        *article = 32;
    }
    else if((mouse_b & 1)&&(mouse_x>= 392 && mouse_y>=447)&&(mouse_x <=454 && mouse_y <= 456)) //les Runners
    {
        *article = 33;
    }
    else if((mouse_b & 1)&&(mouse_x>= 389 && mouse_y>=480)&&(mouse_x <=460 && mouse_y <= 490)) //Hotel de ville
    {
        *article = 34;
    }
    else if((mouse_b & 1)&&(mouse_x>= 410 && mouse_y>=497)&&(mouse_x <=439 && mouse_y <= 507)) //Base
    {
        *article = 35;
    }
    blit(image[*article], buffer, 0,0,494, 208, SCREEN_W, SCREEN_H);
    masked_stretch_blit(image[20], buffer, 0,0,image[20]->w, image[20]->h, 350,100,3*image[20]->w, 6*image[20]->h);
    masked_blit(image[23], buffer, 0,0,365, 250, SCREEN_W, SCREEN_H);
    masked_stretch_blit(image[21], buffer, 0,0,image[21]->w, image[21]->h, 365,125,image[21]->w/10, image[21]->h/10);
    if((mouse_x>= 376 && mouse_y>=840)&&(mouse_x <=408 && mouse_y <= 872)) //bouton retour
    {
        if(mouse_b & 1)
        {
            if(*compteur >= 10)
            {
                *scene = 1;
                *compteur = 0;
            }
            else
            {
                *compteur = *compteur+1;
            }
            rest(4);
        }
        masked_blit(image[22], buffer, 0,0, 376, 840, SCREEN_W, SCREEN_H);
    }
    else
    {
        masked_blit(image[22], buffer, 0,0, 375, 840, SCREEN_W, SCREEN_H);
    }
}


