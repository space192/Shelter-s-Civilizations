#include "../../prototypes.h"

void afficherBatiment(t_listeBR *liste,BITMAP* page,BITMAP* batiments[3],BITMAP* beacon[2],t_batimentP* batimentP,int *condition,int *conditionHDV,int deplAffX, int deplAffY)
{//affiche les batiments de productions et l'hotel de ville
    BITMAP* antenne=create_bitmap(54,50);


    t_maillonBR *actuel;
    actuel = liste->premier;

    blit(beacon[1], antenne,batimentP->imageX,batimentP->imageY,0,0,54, 50);

    // Le code ci dessous permet de gerer l'animation de l'antenne sur l'hotel de ville
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




    while(actuel !=NULL)
    {
        if(actuel->type<4)
        {
            draw_sprite(page,batiments[((actuel->type) -1)+(actuel->niveau*3)],actuel->x-deplAffX,actuel->y-deplAffY);
        }
        actuel = actuel->suivant;
    }


    if(*conditionHDV==1)
    {
        draw_sprite(page,beacon[0],batimentP->x-deplAffX+12,batimentP->y-deplAffY+13);
        draw_sprite(page,antenne,batimentP->x-deplAffX+33,batimentP->y-deplAffY-15);
    }

    destroy_bitmap(antenne);

    free(actuel);

}

void afficherMine(t_listeMine *listeMine,BITMAP* page,BITMAP *IMGMine[2],BITMAP* explosion,int deplAffX,int deplAffY)//Affiche les mines et permet de gérer l'animation de l'explosion des mines
{
    t_maillonMine *actuel2;
    BITMAP* petiteExplosion=create_bitmap(112,94);

    if(listeMine->premier!=NULL)
    {
        actuel2 = listeMine->premier;
        while(actuel2!=NULL)
        {
            if(actuel2->etat==0)
            {
                draw_sprite(page,IMGMine[actuel2->type],actuel2->x-deplAffX,actuel2->y-deplAffY);
            }
            else if((actuel2->etat>0)&&(actuel2->etat<672))
            {
                blit(explosion, petiteExplosion,actuel2->etat,0,0,0,112, 94);

            }
            else if((actuel2->etat>=672)&&(actuel2->etat<1344))
            {
                blit(explosion, petiteExplosion,actuel2->etat-672,94,0,0,112, 94);

            }
            else if((actuel2->etat>=1344)&&(actuel2->etat<2016))
            {
                blit(explosion, petiteExplosion,actuel2->etat-1344,188,0,0,112, 94);

            }
            else if((actuel2->etat>=2016)&&(actuel2->etat<2688))
            {
                blit(explosion, petiteExplosion,actuel2->etat-2016,282,0,0,112, 94);

            }
            else if((actuel2->etat>=2688)&&(actuel2->etat<3360))
            {
                blit(explosion, petiteExplosion,actuel2->etat-2688,376,0,0,112, 94);

            }
            else if((actuel2->etat>=3360)&&(actuel2->etat<4032))
            {
                blit(explosion, petiteExplosion,actuel2->etat-3360,470,0,0,112, 94);

            }
            else if((actuel2->etat>=4032)&&(actuel2->etat<4704))
            {
                blit(explosion, petiteExplosion,actuel2->etat-4032,564,0,0,112, 94);

            }
            else if((actuel2->etat>=4704)&&(actuel2->etat<5376))
            {
                blit(explosion, petiteExplosion,actuel2->etat-4704,658,0,0,112, 94);

            }
            else if((actuel2->etat>=5376)&&(actuel2->etat<6048))
            {
                blit(explosion, petiteExplosion,actuel2->etat-5376,752,0,0,112, 94);

            }
            if(actuel2->etat!=0)
            {
                draw_sprite(page,petiteExplosion,actuel2->x-deplAffX-25,actuel2->y-deplAffY-50);
                actuel2->etat+=112;
            }


            actuel2=actuel2->suivant;
        }
    }

    destroy_bitmap(petiteExplosion);
    free(actuel2);

}

void testRecolter(t_listeBR *liste,t_joueur *joueur,int *i,int deplAffX,int deplAffY)//Permet de recolter les ressources lorsque l'on clique sur le batiment
{
    t_maillonBR *actuel;
    actuel = liste->premier;

    while(actuel!=NULL)
    {
        if ((mouse_b & 1)&&((mouse_y+deplAffY >=actuel->y)&&(mouse_y+deplAffY <=actuel->y+60)&&(mouse_x+deplAffX >=actuel->x)&&(mouse_x+deplAffX <=actuel->x+60))&&(actuel->tic==actuel->ticMax))
        {
            actuel->tic = 0;
            if(actuel->type==1)//&&(*i>=50))
            {
                if(actuel->niveau==0)
                {
                    joueur->or +=30;
                    *i=0;
                }
                else if(actuel->niveau==1)
                {
                    joueur->or +=65;
                    *i=0;
                }
                else if(actuel->niveau==2)
                {
                    joueur->or +=140;
                    *i=0;
                }

            }
            else if(actuel->type==2)
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
            else if(actuel->type==3)
            {
                if(actuel->niveau==0)
                {
                    joueur->metal+=35;
                    *i=0;
                }
                else if(actuel->niveau==1)
                {
                    joueur->metal+=80;
                    *i=0;
                }
                else if(actuel->niveau==2)
                {
                    joueur->metal+=170;
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
    //Chaque Batiments a un certains nombres de tics, sir le nombre de tics est maximum alors on pourra récolter des ressources
    //On peut recolter les ressources quand le nombre de tics est maximum

    t_maillonBR *actuel;

    //le code suivant gère l 'animation qui montre que l'on peut recolter des ressources
    if(*angle<28)
    {
        (*couleurR)+=0.400;
        (*angle)+=0.050;
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
        else if((actuel->tic==actuel->ticMax)&&(actuel->type!=4))
        {
            if(actuel->niveau<2)
            {
                circle(page,actuel->x+30-deplAffX,actuel->y+30-deplAffY,(*angle),makecol(255,(*couleurR),(*couleurR)));
            }
            else if(actuel->niveau==2)
            {
                if(actuel->type!=4)
                {
                    circle(page,actuel->x+60-deplAffX,actuel->y+60-deplAffY,(*angle)*2,makecol(255,(*couleurR),(*couleurR)));
                }
            }
        }
        actuel=actuel->suivant;
    }
    actuel = NULL;
    free(actuel);
}

void gererMine(t_listeMine *liste, t_listeMechant *horde)//inflige des degats aux ennemis lorsqu'ils passent sur une mine et la detruit par la suite
{
    t_ennemi *mechant;
    t_maillonMine *actuel;
    t_maillonMine *actuel2;
    t_maillonMine *precedent;
    int condition=0;



    if(liste->premier!=NULL)
    {
        actuel2 = liste->premier;


        if(actuel2->etat ==6048)
        {
            liste->premier=actuel2->suivant;
            condition=1;

        }
        else
        {
            precedent=liste->premier;
            actuel2=actuel2->suivant;
        }
        if(condition!=1)
        {
            while(actuel2!=NULL)
            {
                if(actuel2->etat==6048)
                {
                    precedent->suivant=actuel2->suivant;
                }
                actuel2=actuel2->suivant;
                precedent=precedent->suivant;
            }
        }
    }
    if(liste->premier!=NULL)
    {
        actuel=liste->premier;
        while(actuel!=NULL)
        {
            if(horde->premier!=NULL)
            {
                mechant=horde->premier;
                while(mechant!=NULL)
                {
                    if((mechant->x>actuel->x)&&(mechant->x<actuel->x+60)&&(mechant->y>actuel->y)&&(mechant->y<actuel->y+60))
                    {
                        if(actuel->type==0)
                        {
                            mechant->pvM-=30;
                        }
                        else if(actuel->type==1)
                        {
                            mechant->pvM-=60;

                        }
                        if(actuel->etat==0)
                        {
                            actuel->etat+=112;
                        }

                    }
                    mechant=mechant->suivant;
                }
            }
            actuel=actuel->suivant;
        }
    }

    actuel=NULL;
    actuel2=NULL;
    precedent=NULL;

    free(actuel);
    free(actuel2);
    free(precedent);

}
