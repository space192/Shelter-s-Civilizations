#include "../prototypes.h"
void dessinerMechant(t_listeMechant* horde, BITMAP* buffer, int screenx, int screeny, t_sequence lesSeq[NB_SEQ])
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
