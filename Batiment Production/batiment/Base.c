#include "../../prototypes.h"


void ajouterFondation(BITMAP* page,BITMAP *construc,t_listeEDD *liste,int *condition,t_listeBR *listeBR,int *xp,int *yp,int *i,int *niveaubatiment,t_borne *borne,int deplAffX, int deplAffY,int *numeroEDD,t_joueur* joueur,SAMPLE *buzzer)
{
    t_maillonBR *actuel=(t_maillonBR*) malloc(sizeof(t_maillonBR));

    int x,y;
    if(*condition==3)
    {
        draw_sprite(page,construc,400,16);
        rect(page,526,18,526+60,18+60,makecol(0,255,0));
        if((mouse_b & 1)&&(*i>=300))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;
            ajusterFondation(&x,&y);

            if(testSiArgentSuffisant(joueur,0,0,2,buzzer)==1)
            {
                nouvelleFondation(liste,x,y,numeroEDD);
            }


            *condition = 1;
            *i=0;

        }
    }
    else if(*condition == 8)
    {
        draw_sprite(page,construc,400,16);
        rect(page,712,18,712+60,18+60,makecol(255,0,0));
        if((mouse_b & 1)&&(((mouse_x<borne->xDeb-deplAffX)||(mouse_x>(borne->xFin +60)-deplAffX)||(mouse_y<borne->yDeb-deplAffY)||(mouse_y>borne->yFin-deplAffY))&&(*i>=150)))
        {
            *condition=1;
            *i=0;
        }
        else if((mouse_b & 1)&&(((mouse_x>borne->xDeb-deplAffX)||(mouse_x<(borne->xFin +60)-deplAffX)||(mouse_y>borne->yDeb-deplAffY)||(mouse_y<borne->yFin-deplAffY))&&(*i>=150)))
        {
            *condition=81;
            *xp = mouse_x+deplAffX;
            *yp = mouse_y+deplAffY;
            definirCoordonnees(xp,yp,*borne,1);
            determinerBatiment(listeBR,xp,yp,niveaubatiment);
            *i=0;
        }
    }
    else if(*condition == 81)
    {
        if(*niveaubatiment==2)
        {
            rect(page,*xp-deplAffX,*yp-deplAffY,*xp+120-deplAffX,*yp+120-deplAffY,makecol(0,255,0));
        }
        else if(*niveaubatiment<2)
        {
            rect(page,*xp-deplAffX,*yp-deplAffY,*xp+60-deplAffX,*yp+60-deplAffY,makecol(0,255,0));
        }

        if((mouse_b & 1)&&(((mouse_x<borne->xDeb-deplAffX)||(mouse_x>(borne->xFin +60)-deplAffX)||(mouse_y<borne->yDeb-deplAffY)||(mouse_y>borne->yFin-deplAffY))&&(*i>=150)))
        {
            *condition=1;
            *i=0;
        }
        else if((mouse_b & 1)&&(((mouse_x>borne->xDeb-deplAffX)||(mouse_x<(borne->xFin +60)-deplAffX)||(mouse_y>borne->yDeb-deplAffY)||(mouse_y<borne->yFin-deplAffY))&&(*i>=150)))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;
            definirCoordonnees(&x,&y,*borne,*niveaubatiment);

            if(testSiBatimentPresent(listeBR,x,y,*niveaubatiment)==1)
            {
                actuel=listeBR->premier;
                while(actuel!=NULL)
                {
                    if((actuel->x==*xp)&&(actuel->y==*yp))
                    {
                        actuel->x=x;
                        actuel->y=y;
                    }
                    actuel=actuel->suivant;
                }
            }
            *condition=1;
        }
    }

    free(actuel);
}

void nouvelleFondation(t_listeEDD *liste,int x, int y,int *numeroEDD)
{
    t_maillonEDD *maillon=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon2=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon3=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon4=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));

    if(maillon==NULL||maillon2==NULL||maillon3==NULL||maillon4==NULL)
    {
        printf("erreur d'allocation dynamique 12\n");
        exit(EXIT_FAILURE);
    }

    (*numeroEDD)++;

    maillon->x=x;
    maillon->y=y;
    maillon->afficherFondation=1;
    maillon->emplacementDisponible=1;
    maillon->numeroEDD=(*numeroEDD);

    (*numeroEDD)++;


    maillon2->x=x+60;
    maillon2->y=y;
    maillon2->afficherFondation=0;
    maillon2->emplacementDisponible=1;
    maillon2->numeroEDD=(*numeroEDD);

    (*numeroEDD)++;

    maillon3->x=x;
    maillon3->y=y+60;
    maillon3->afficherFondation=0;
    maillon3->emplacementDisponible=1;
    maillon3->numeroEDD=(*numeroEDD);

    (*numeroEDD)++;

    maillon4->x=x+60;
    maillon4->y=y+60;
    maillon4->afficherFondation=0;
    maillon4->emplacementDisponible=1;
    maillon4->numeroEDD=(*numeroEDD);



    maillon4->suivant=liste->premier;
    maillon3->suivant=maillon4;
    maillon2->suivant=maillon3;
    maillon->suivant=maillon2;
    liste->premier=maillon;

}

void ajusterFondation(int*x,int*y)
{
    int i,j;
    for(i=0; i<=*x; i+=120)
    {
        for(j=70; j<=*y; j+=120)
        {
            if((*x>=i)&&(*x<i+120)&&(*y>=j)&&(*y<j+120))
            {
                *x = i;
                *y = j;
            }
        }
    }
}

void ajusterBase(t_borne *borne, int agrandissement)
{
    if(agrandissement == 0)
    {
        borne->xDeb = 40;
        borne->yDeb = 1630;
        borne->xFin = 340;
        borne->yFin = 1870;
    }
    else if(agrandissement == 1)
    {
        borne->xDeb = 40;
        borne->yDeb = 1630;
        borne->xFin = 340;
        borne->yFin = 2110;
    }
    else if(agrandissement == 2)
    {
        borne->xDeb = 40;
        borne->yDeb = 1390;
        borne->xFin = 340;
        borne->yFin = 2110;
    }
}

void afficherBase(BITMAP* page,BITMAP* fond,BITMAP* base[3],BITMAP* fondation,t_listeEDD *liste,int agrandissement, int deplAffX, int deplAffY)
{
    t_maillonEDD *actuel;
    actuel=liste->premier;


    blit(fond,page,0+deplAffX,0+deplAffY,0,0,SCREEN_W,SCREEN_H);
    if(agrandissement==0)
    {
        draw_sprite(page,base[agrandissement],0-deplAffX,1575-deplAffY);
    }
    else if(agrandissement == 1)
    {
        draw_sprite(page,base[agrandissement],0-deplAffX,1578-deplAffY);
    }
    else if(agrandissement==2)
    {
        draw_sprite(page,base[agrandissement],0-deplAffX,1338-deplAffY);
    }


    while(actuel!=NULL)
    {
        if(actuel->afficherFondation==1)
        {
            draw_sprite(page,fondation,actuel->x-deplAffX,actuel->y-deplAffY);
            actuel=actuel->suivant;
        }
        else
        {
            actuel=actuel->suivant;
        }
    }
    free(actuel);
}

