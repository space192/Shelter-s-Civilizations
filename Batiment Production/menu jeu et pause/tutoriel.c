#include "../../prototypes.h"

void tutoriel(BITMAP* page,int *tutoA,int angle,t_listeBR *liste1,t_joueur joueur,t_listeEDD *liste2,t_listedef *liste3)
{
    int condition=0;
    t_maillonBR *actuel;
    t_maillonEDD *actuel2;
    //actuel=liste1->premier;

    if((*tutoA)==1)
    {
    rectfill(page,290,840,930,965,makecol(255,255,255));
    rectfill(page,300,850,920,955,makecol(0,0,0));
    textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Bienvenu dans notre jeu *nomDuJeu* realise dans le cadre de ECETowerDefense");
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

    if((*tutoA)>=2&&(*tutoA)<1000)
    {
        rectfill(page,290,840,960,975,makecol(255,255,255));
        rectfill(page,300,850,950,965,makecol(0,0,0));
       textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Tres bien!");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Si vous regarder sur la partie gauche de la carte vous pourrez voir votre base.");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Votre objectif est de proteger les murailles de cette derniere.");
        textprintf_ex(page,font,305,900,makecol(255,255,255),-1,"Il faut eviter qu'une horde d'ennemi viennent detruire votre hotel de ville.");
        (*tutoA)++;
    }

    if((*tutoA)==1000)
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
    if((*tutoA)==1001)
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
            (*tutoA)=1002;
        }

    }
    if((*tutoA)==1002)
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
                (*tutoA)=1003;
            }
            actuel2=actuel2->suivant;
        }
    }
    if((*tutoA)==1003)
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
            (*tutoA)=1004;
        }
    }
    if((*tutoA>=1004)&&(*tutoA<2004))
    {
        rectfill(page,290,840,1050,975,makecol(255,255,255));
        rectfill(page,300,850,1040,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Bien, vous etes deja un pro !");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1," Vous pouvez noter la présence de 4 autres boutons.");
        textprintf_ex(page,font,305,885,makecol(255,255,255),-1,"Il vous permettront respectivement, d’ameliorer, de supprimer, et de deplacer des batiments.");
        textprintf_ex(page,font,305,900,makecol(255,255,255),-1,"Le dernier permet d’agrandir  la base, mais attention, cela vous coutera cher !");
        (*tutoA)++;
    }
    if((*tutoA>=2004)&&(*tutoA<3004))
    {
        rectfill(page,290,840,960,975,makecol(255,255,255));
        rectfill(page,300,850,950,965,makecol(0,0,0));
        textprintf_ex(page,font,305,855,makecol(255,255,255),-1,"Vous etes maintenant pret a jouer !");
        textprintf_ex(page,font,305,870,makecol(255,255,255),-1,"Bonne partie et amusez vous bien !");
        (*tutoA)++;
    }

    if((*tutoA)==3004)
    {
        (*tutoA)=0;
    }

    actuel=NULL;
    actuel2=NULL;


    free(actuel);
    free(actuel2);
}
