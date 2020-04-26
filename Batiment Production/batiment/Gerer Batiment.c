#include "../../prototypes.h"

void afficherBatiment(t_listeBR *liste,BITMAP* page,BITMAP* batiments[3],BITMAP* beacon[2],t_batimentP* batimentP,int *condition,int deplAffX, int deplAffY)
{
    BITMAP* antenne=create_bitmap(54,50);

    blit(beacon[1], antenne,batimentP->imageX,batimentP->imageY,0,0,54, 50);


    if((*condition<80)&&((*condition)%10==0))
    {

        batimentP->imageX=54 + batimentP->imageX;
    }
    else if(*condition==80)
    {

        batimentP->imageY+=50;
        batimentP->imageX= 0;
    }
    else if((*condition<160)&&((*condition)%10==0))
    {

        batimentP->imageX+=54;
    }
    else if(*condition==160)
    {

        batimentP->imageY+=50;
        batimentP->imageX= 0;
    }
    else if((*condition<240)&&((*condition)%10==0))
    {

        batimentP->imageX+=54;
    }
    else if(*condition==240)
    {

        batimentP->imageY+=50;
        batimentP->imageX= 0;
    }
    else if((*condition<320)&&((*condition)%10==0))
    {

        batimentP->imageX+=54;
    }
    else if(*condition==320)
    {
        (*condition)=0;
        batimentP->imageY=0;
        batimentP->imageX=0;
    }
    (*condition)++;



    t_maillonBR *actuel=(t_maillonBR*) malloc(sizeof(t_maillonBR));
    if(actuel==NULL)
    {
        printf("erreur d'allocation dynamique 9\n");
        exit(EXIT_FAILURE);
    }
    actuel = liste->premier;
    while(actuel !=NULL)
    {
        draw_sprite(page,batiments[((actuel->type) -1)+(actuel->niveau*3)],actuel->x-deplAffX,actuel->y-deplAffY);
        actuel = actuel->suivant;
    }

    draw_sprite(page,beacon[0],batimentP->x-deplAffX+12,batimentP->y-deplAffY+13);
    draw_sprite(page,antenne,batimentP->x-deplAffX+33,batimentP->y-deplAffY-15);
    destroy_bitmap(antenne);
    free(actuel);
}

void testRecolter(t_listeBR *liste,t_joueur *joueur,int *i,int deplAffX,int deplAffY)
{
    t_maillonBR *actuel;
    actuel = liste->premier;

    while(actuel!=NULL)
    {
        if ((mouse_b & 1)&&((mouse_y+deplAffY >=actuel->y)&&(mouse_y+deplAffY <=actuel->y+60)&&(mouse_x+deplAffX >=actuel->x)&&(mouse_x+deplAffX <=actuel->x+60))&&(actuel->tic==actuel->ticMax))
        {
            actuel->tic = 0;
            if((actuel->type==1)&&(*i>=50))
            {
                if(actuel->niveau==0)
                {
                    joueur->or +=15;
                    *i=0;
                }
                else if(actuel->niveau==1)
                {
                    joueur->or +=40;
                    *i=0;
                }
                else if(actuel->niveau==2)
                {
                    joueur->or +=80;
                    *i=0;
                }

            }
            else if((actuel->type==2)&&(*i>=50))
            {
                if(actuel->niveau==0)
                {
                    joueur->pierre+=40;
                    *i=0;
                }
                else if(actuel->niveau==1)
                {
                    joueur->pierre+=80;
                    *i=0;
                }
                else if(actuel->niveau==2)
                {
                    joueur->pierre+=160;
                    *i=0;
                }

            }
            else if((actuel->type==3)&&(*i>=50))
            {
                if(actuel->niveau==0)
                {
                    joueur->metal+=30;
                    *i=0;
                }
                else if(actuel->niveau==1)
                {
                    joueur->metal+=70;
                    *i=0;
                }
                else if(actuel->niveau==2)
                {
                    joueur->metal+=150;
                    *i=0;
                }
            }
        }
        actuel=actuel->suivant;
    }
    (*i)++;

    free(actuel);
}

void incrementerTic(t_listeBR* liste,BITMAP *page, float *angle, float *couleurR,int deplAffX,int deplAffY)
{


    t_maillonBR *actuel;

    if(*angle<28)
    {
        (*couleurR)+=0.200;
        (*angle)+=0.025;
    }

    if(*angle>=28)
    {
        (*angle)=0;
        (*couleurR)=21;
    }


    actuel = liste->premier;

    while(actuel!=NULL)
    {
        if(actuel->tic<actuel->ticMax)
        {
            actuel->tic++;
        }
        else if(actuel->tic==actuel->ticMax)
        {
            if(actuel->niveau<2)
            {
                printf("pute");
                circle(page,actuel->x+30-deplAffX,actuel->y+30-deplAffY,(*angle),makecol(255,(*couleurR),(*couleurR)));
            }
            else if(actuel->niveau==2)
            {
                circle(page,actuel->x+60-deplAffX,actuel->y+60-deplAffY,(*angle)*2,makecol(255,(*couleurR),(*couleurR)));
            }
        }
        actuel=actuel->suivant;
    }
    free(actuel);
}

