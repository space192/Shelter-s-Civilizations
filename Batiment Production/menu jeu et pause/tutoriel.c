#include "../../prototypes.h"

void tutoriel(BITMAP* page,int *tutoA,int angle,t_listeBR *liste1,t_joueur joueur,t_listeEDD *liste2,t_listedef *liste3)
{
    int condition=0;
    t_maillonBR *actuel;
    t_maillonEDD *actuel2;
    //actuel=liste1->premier;

    if((*tutoA)==1)
    {
    rectfill(page,290,840,990,965,makecol(255,255,255));
    rectfill(page,300,850,980,955,makecol(0,0,0));
    textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Bienvenu dans notre jeu Shelter's Civilizations realise dans le cadre de ECETowerDefense");
    textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Avant toute chose essayer de vous deplacer");
    textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Pour cela vous pouvez utiliser [z,q,s,d],ou les fleches directionnels");
    }
    if(((key[KEY_UP]||(key[KEY_W]))&&(*tutoA==1)))
    {
        (*tutoA)=2;
    }
    if(((key[KEY_DOWN]||(key[KEY_S]))&&(*tutoA==1)))
    {
        (*tutoA)=2;
    }
    if(((key[KEY_LEFT]||(key[KEY_A]))&&(*tutoA==1)))
    {
        (*tutoA)=2;
    }
    if(((key[KEY_RIGHT]||(key[KEY_D]))&&(*tutoA==1)))
    {
        (*tutoA)=2;
    }

    if((*tutoA)>=2&&(*tutoA)<2000)
    {
        rectfill(page,290,840,960,975,makecol(255,255,255));
        rectfill(page,300,850,950,965,makecol(0,0,0));
       textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Tres bien!");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Si vous regarder sur la partie gauche de la carte vous pourrez voir votre base.");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Votre objectif est de proteger les murailles de cette derniere.");
        textprintf_ex(page,font,305,900,makecol(255,255,255),-1,"Il faut eviter qu'une horde d'ennemi viennent detruire votre hotel de ville.");
        (*tutoA)++;
    }

    if((*tutoA)==2000)
    {
        rectfill(page,290,840,1060,975,makecol(255,255,255));
        rectfill(page,300,850,1050,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Comme vous pouvez le voir, il y a trois types de ressources differentes.");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Ces derniers permettront d’acheter des batiments, des fondations, agrandir votre base ect.");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Essayer donc de placer un batiment de ressource.");
        circle(page,432,47,angle,makecol(255,255,255));

        condition=0;

        actuel=(liste1->premier);
        while(actuel!=NULL)
        {
            condition++;
            actuel=actuel->suivant;
        }
        if(condition==5)
        {
            (*tutoA)++;
        }
    }
    if((*tutoA)==2001)
    {
        rectfill(page,290,840,980,975,makecol(255,255,255));
        rectfill(page,300,850,970,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Votre objectif maintenant est de recolter les ressources. ");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Lorsque vous pouvez observer un cercle grandir sur le batiment.");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Cela signifie que les ressources sont pretes à etre recoltees.");
        textprintf_ex(page,font,305,900,makecol(255,255,255),-1,"Dans ce cas la il suffit de cliquer sur le batiment et les ressources sont à vous !");
        textprintf_ex(page,font,305,915,makecol(255,255,255),-1,"Essayez !");

        if(joueur.metal>200)
        {
            (*tutoA)=2002;
        }

    }
    if((*tutoA)==2002)
    {
        rectfill(page,290,840,960,975,makecol(255,255,255));
        rectfill(page,300,850,950,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Maintenant, il va falloir trouver un moyen de se defendre face aux ennemis.");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Pour cela on va installer des defenses ! ");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Mais une defense ne peut pas etre installee directement sur la terre.");
        textprintf_ex(page,font,305,900,makecol(255,255,255),-1,"Il va falloir creer des fondations.");

        circle(page,556,47,angle,makecol(255,255,255));

        actuel2=liste2->premier;

        while(actuel2!=NULL)
        {
            if(actuel2->numeroEDD==12)
            {
                (*tutoA)=2003;
            }
            actuel2=actuel2->suivant;
        }
    }
    if((*tutoA)==2003)
    {
        rectfill(page,290,840,980,975,makecol(255,255,255));
        rectfill(page,300,850,970,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Une fois ces fondation crees, vous pouvez placer vos premieres defenses. ");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"En glissant votre souris sur le batiment qui vous interesse ,");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"vous pourrez avoir des informations plus precises sur sont utilite");
        textprintf_ex(page,font,305,900,makecol(255,255,255),-1,"Essayez de placer une petite defense sur le fondation que vous avez cree.");
        circle(page,494,47,angle,makecol(255,255,255));

        if(liste3->premier !=NULL)
        {
            (*tutoA)=2004;
        }
    }
    if((*tutoA>=2004)&&(*tutoA<4004))
    {
        rectfill(page,290,840,1050,975,makecol(255,255,255));
        rectfill(page,300,850,1040,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Bien, vous etes deja un pro !");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1," Vous pouvez noter la présence de 4 autres boutons.");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Il vous permettront respectivement, d’ameliorer, de supprimer, et de deplacer des batiments.");
        textprintf_ex(page,font,305,900,makecol(255,255,255),-1,"Le dernier permet d’agrandir  la base, mais attention, cela vous coutera cher !");
        (*tutoA)++;
    }
    if((*tutoA>=4004)&&(*tutoA<5004))
    {
        rectfill(page,290,840,960,975,makecol(255,255,255));
        rectfill(page,300,850,950,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Vous etes maintenant pret a jouer !");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Bonne partie et amusez vous bien !");
        (*tutoA)++;
    }

    if((*tutoA)==5004)
    {
        (*tutoA)=0;
    }

    actuel=NULL;
    actuel2=NULL;


    free(actuel);
    free(actuel2);
}


void animationFin(BITMAP*page,BITMAP*explosion,t_listeBR *liste,int *etat,int deplAffX, int deplAffY,int *jeuActif,int *conditionHDV,int *i,int *destructionM,t_borne borne)
{
    BITMAP* petiteExplosion=create_bitmap(112,94);
    t_maillonBR *actuel;

    if(*destructionM==0)
    {
        *destructionM=borne.yDeb;
    }
    if(*destructionM<borne.yFin)
    {
            if(*etat==0)
            {
                (*etat)+=112;
            }
            if((*etat>0)&&(*etat<672))
            {
                blit(explosion, petiteExplosion,*etat,0,0,0,112, 94);

            }
            else if((*etat>=672)&&(*etat<1344))
            {
                blit(explosion, petiteExplosion,*etat-672,94,0,0,112, 94);

            }
            else if((*etat>=1344)&&(*etat<2016))
            {
                blit(explosion, petiteExplosion,*etat-1344,188,0,0,112, 94);

            }
            else if((*etat>=2016)&&(*etat<2688))
            {
                blit(explosion, petiteExplosion,*etat-2016,282,0,0,112, 94);

            }
            else if((*etat>=2688)&&(*etat<3360))
            {
                blit(explosion, petiteExplosion,*etat-2688,376,0,0,112, 94);

            }
            else if((*etat>=3360)&&(*etat<4032))
            {
                blit(explosion, petiteExplosion,*etat-3360,470,0,0,112, 94);

            }
            else if((*etat>=4032)&&(*etat<4704))
            {
                blit(explosion, petiteExplosion,*etat-4032,564,0,0,112, 94);

            }
            else if((*etat>=4704)&&(*etat<5376))
            {
                blit(explosion, petiteExplosion,*etat-4704,658,0,0,112, 94);

            }
            else if((*etat>=5376)&&(*etat<6048))
            {
                blit(explosion, petiteExplosion,*etat-5376,752,0,0,112, 94);

            }
            if(*etat!=0)
            {
                draw_sprite(page,petiteExplosion,borne.xFin-deplAffX-25+40,*destructionM-deplAffY-50);
                (*etat)+=112;
            }

            if(*etat==6048)
            {
                (*destructionM)+=60;
                (*etat)=0;
               *i=0;
            }
    }










    if((liste->premier!=NULL&&*i>20)&&(*destructionM==borne.yFin))
    {
        //printf("je suis là");
        actuel = liste->premier;


            if(*etat==0)
            {
                (*etat)+=112;
            }
            if((*etat>0)&&(*etat<672))
            {
                blit(explosion, petiteExplosion,*etat,0,0,0,112, 94);

            }
            else if((*etat>=672)&&(*etat<1344))
            {
                blit(explosion, petiteExplosion,*etat-672,94,0,0,112, 94);

            }
            else if((*etat>=1344)&&(*etat<2016))
            {
                blit(explosion, petiteExplosion,*etat-1344,188,0,0,112, 94);

            }
            else if((*etat>=2016)&&(*etat<2688))
            {
                blit(explosion, petiteExplosion,*etat-2016,282,0,0,112, 94);

            }
            else if((*etat>=2688)&&(*etat<3360))
            {
                blit(explosion, petiteExplosion,*etat-2688,376,0,0,112, 94);

            }
            else if((*etat>=3360)&&(*etat<4032))
            {
                blit(explosion, petiteExplosion,*etat-3360,470,0,0,112, 94);

            }
            else if((*etat>=4032)&&(*etat<4704))
            {
                blit(explosion, petiteExplosion,*etat-4032,564,0,0,112, 94);

            }
            else if((*etat>=4704)&&(*etat<5376))
            {
                blit(explosion, petiteExplosion,*etat-4704,658,0,0,112, 94);

            }
            else if((*etat>=5376)&&(*etat<6048))
            {
                blit(explosion, petiteExplosion,*etat-5376,752,0,0,112, 94);

            }
            if((*etat!=0)&&(actuel->niveau<2))
            {
                draw_sprite(page,petiteExplosion,actuel->x-deplAffX-25,actuel->y-deplAffY-50);
                (*etat)+=112;
            }
            if((*etat!=0)&&(actuel->niveau==2))
            {
                draw_sprite(page,petiteExplosion,actuel->x-deplAffX-25+30,actuel->y-deplAffY-50+60);
                (*etat)+=112;
            }
            if(*etat==6048)
            {
                (*etat)=0;
                if(actuel->type<4)
                {
                    supprimerBatiment(liste,actuel->x,actuel->y);
                    *i=0;
                }
                else if(actuel->type==4)
                {
                    supprimerBatiment(liste,actuel->x,actuel->y);
                    supprimerBatiment(liste,actuel->x+60,actuel->y);
                    supprimerBatiment(liste,actuel->x,actuel->y+60);
                    supprimerBatiment(liste,actuel->x+60,actuel->y+60);
                    *conditionHDV=0;
                    *i=0;
                }

            }
    }
    else if(liste->premier==NULL)
    {
        if(*i>200)
        {
            *jeuActif=4;
        }

    }
    (*i)++;

    actuel=NULL;
    free(actuel);
    destroy_bitmap(petiteExplosion);
}
