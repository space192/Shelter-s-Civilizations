#include "../prototypes.h"

void dessinerMechant(t_listeMechant* horde, BITMAP* buffer, int screenx, int screeny, BITMAP* lesSeq[NB_SEQM])
{
    t_ennemi* elemA = NULL; //element actuel permettant de parcourir la liste

    elemA = horde->premier;

    while(elemA != NULL)
    {

        imageAfficheMechant(elemA, lesSeq);
        //printf("TEST 2 : type %d, imgx %d, imgy %d\n", elemA->type, elemA->imgX, elemA->imgY);

        if(elemA->type == 0)
        {
                BITMAP* temp1 = create_bitmap(54, 42);

            if(elemA->depx == 0)
            {
            stretch_blit(lesSeq[elemA->type], temp1, 0, 632, 202, 158, 0, 0, 54, 42);
            masked_blit(temp1, buffer, 0, 0, elemA->x - screenx - elemA->tx, elemA->y - screeny - elemA->ty, temp1->w, temp1->h);
             }
            else
            {
            stretch_blit(lesSeq[elemA->type], temp1, elemA->imgX, elemA->imgY, 202, 158, 0, 0, 54, 42);
            masked_blit(temp1, buffer, 0, 0, elemA->x - screenx - elemA->tx, elemA->y - screeny - elemA->ty, temp1->w, temp1->h);
            }
                destroy_bitmap(temp1);

        }
        else if (elemA->type == 1)
        {
                BITMAP* temp2 = create_bitmap(54, 47);

            if(elemA->depx == 0)
            {
            stretch_blit(lesSeq[elemA->type], temp2, 0, 880, 248, 220, 0, 0, 54, 47);
            masked_blit(temp2, buffer, 0, 0, elemA->x - screenx - elemA->tx, elemA->y - screeny - elemA->ty, temp2->w, temp2->h);
             }
            else
            {
            stretch_blit(lesSeq[elemA->type], temp2, elemA->imgX, elemA->imgY, 248, 220, 0, 0, 54, 47);
            masked_blit(temp2, buffer, 0, 0, elemA->x - screenx - elemA->tx, elemA->y - screeny - elemA->ty, temp2->w, temp2->h);
            }
                destroy_bitmap(temp2);
        }
        else if (elemA->type == 2)
        {
                BITMAP* temp3 = create_bitmap(48, 68);

            if(elemA->depx == 0)
            {
            blit(lesSeq[elemA->type], temp3, 48*7, 136, 0, 0, 48, 68);
            masked_blit(temp3, buffer, 0, 0, elemA->x - screenx - elemA->tx, elemA->y - screeny - elemA->ty, temp3->w, temp3->h);
             }
            else
            {
            blit(lesSeq[elemA->type], temp3, elemA->imgX, elemA->imgY, 0, 0, 48, 68);
            masked_blit(temp3, buffer, 0, 0, elemA->x - screenx - elemA->tx, elemA->y - screeny - elemA->ty, temp3->w, temp3->h);
            }
                destroy_bitmap(temp3);
        }
        else if(elemA->type == 3)
        {
                BITMAP* temp4 = create_bitmap(108, 94);

            if(elemA->depx == 0)
            {
            stretch_blit(lesSeq[1], temp4, 0, 632, 248, 220, 0, 0, 108, 94);
            masked_blit(temp4, buffer, 0, 0, elemA->x - screenx - 60, elemA->y - screeny - 60, temp4->w, temp4->h);
             }
            else
            {
            stretch_blit(lesSeq[1], temp4, elemA->imgX, elemA->imgY, 248, 220, 0, 0, 108, 94);
            masked_blit(temp4, buffer, 0, 0, elemA->x - screenx - 60, elemA->y - screeny - 60, temp4->w, temp4->h);
            }
                destroy_bitmap(temp4);
        }
        else if (elemA->type == 4)
        {
                BITMAP* temp5 = create_bitmap(96, 136);

            if(elemA->depx == 0)
            {
            stretch_blit(lesSeq[2], temp5, 48*7, 136, 48, 68, 0, 0, 96, 136);
            masked_blit(temp5, buffer, 0, 0, elemA->x - screenx - 60, elemA->y - screeny - 60, temp5->w, temp5->h);
             }
            else
            {
            stretch_blit(lesSeq[2], temp5, elemA->imgX, elemA->imgY, 48, 68, 0, 0, 96, 136);
            masked_blit(temp5, buffer, 0, 0, elemA->x - screenx - 60, elemA->y - screeny - 60 , temp5->w, temp5->h);
            }
                destroy_bitmap(temp5);
        }

        //masked_blit(temp, buffer, 0, 0, elemA->x - screenx, elemA->y - screeny, temp->w, temp->h);

        //rectfill(buffer, elemA->x - screenx, elemA->y - screeny, elemA->x + elemA->tx - screenx, elemA->y + elemA->ty - screeny, makecol(255,0,0));

        elemA = elemA->suivant;
    }
    elemA = NULL;
    free(elemA);
}

/*
void dessinerMechant(t_listeMechant* horde, BITMAP* buffer, int screenx, int screeny, BITMAP* lesSeq[NB_SEQM])
{
    t_ennemi* elemA = NULL; //element actuel permettant de parcourir la liste

    elemA = horde->premier;

    while(elemA != NULL)
    {
        elemA->cmptImg++; //on incrémente le compteur d'img
        if(elemA->cmptImg >= elemA->tmpImg)
        {
            elemA->imgA++; //si le compteur a atteint le nombre demandé passe à l'img suivante dans la séquence

            if(elemA->imgA >= lesSeq[elemA->angle].nbImg)
                elemA->imgA = 0;
        }

            if(elemA->type == 0) //on dessine l'ennemi 1
            {
                //if(elemA->depx !=0) //si le mechant est bloqué
                  //  draw_sprite(buffer, lesSeq[elemA->angle].img[elemA->imgA], elemA->x - screenx, elemA->y - screeny);
                //else
                //    draw_sprite(buffer, lesSeq[2].img[0], elemA->x - screenx, elemA->y - screeny);
                rectfill(buffer, elemA->x - screenx, elemA->y - screeny, elemA->x + elemA->tx - screenx, elemA->y + elemA->ty - screeny, makecol(0,255,0));
            }
            else if(elemA->type == 1) //on dessine l'ennemi 2
            {
                //if(elemA->depx !=0) //si le mechant est bloqué
                  //  draw_sprite(buffer, lesSeq[4 + elemA->angle].img[elemA->imgA], elemA->x - screenx, elemA->y - screeny);
                //else
                  //  draw_sprite(buffer, lesSeq[4+ 2].img[0], elemA->x - screenx, elemA->y - screeny);
                rectfill(buffer, elemA->x - screenx, elemA->y - screeny, elemA->x + elemA->tx - screenx, elemA->y + elemA->ty - screeny, makecol(255,0,0));
            }
        elemA = elemA->suivant;
    }
}
*/


void positionEcran(int* screenx, int* screeny, BITMAP* decor)
{
    // si la souris touche un bord alors on deplace le champ de vision
    if (mouse_x <= 10)
        *screenx-=20;
    if (mouse_x >= SCREEN_W-20)
        *screenx+=20;
    if (mouse_y <= 20 )
        *screeny-=20;
    if (mouse_y >= SCREEN_H-20  )
        *screeny+=20;

    // GESTION DU SCROLLING AU CLAVIER (Touches de direction)
    if (key[KEY_RIGHT])
        *screenx+=20;
    if (key[KEY_LEFT] )
        *screenx-=20;
    if (key[KEY_DOWN] )
        *screeny+=20;
    if (key[KEY_UP]   )
        *screeny-=20;

    // Bloquer le scrolling si il est ammené trop loin !
    if ( *screenx < 0 )
        *screenx=0;
    if ( *screenx > decor->w - SCREEN_W )
        *screenx = decor->w - SCREEN_W;
    if ( *screeny < 0 )
        *screeny=0;
    if ( *screeny > decor->h - SCREEN_H )
        *screeny = decor->h - SCREEN_H;
}
