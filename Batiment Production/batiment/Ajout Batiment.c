#include "../../prototypes.h"

void construireNouveauBatiment(t_listeBR *liste,t_listedef *liste2,t_listeEDD *liste3,BITMAP *page,BITMAP *menuC,BITMAP *construc,int *condition,int *i,int *typeDeBatiment,int *niveaubatiment,int* agrandissement,t_joueur* joueur,int deplAffX,int deplAffY,t_borne *borne,int *PDV,int voice[4])
{
    int x;
    int y;
   //Gestion du menu de s�lection des actions
    if(*condition==1)
    {
        afficherInfo(page);
    }

    if((mouse_b & 1)&&(*condition==1)&&(*i>=50)&&(mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=712))
    {
        //play_sample(selectSound, 200,128, 1000,0);
        voice_start(voice[0]);
    }

    if(((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=462))&&(*i>=50))&&(*condition==1))
    {
        (*condition) =2;
        *i=0;
    }
    else if(((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524))&&(*i>=50))&&(*condition==1))
    {
        (*condition) =7;
        *i=0;
    }
    else if(((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586))&&(*i>=50))&&(*condition==1))
    {
        (*condition) =3;
        *i=0;
    }
    else if(((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648))&&(*i>=50))&&(*condition==1))
    {
        (*condition) =4;
        *i=0;
    }
    else if(((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710))&&(*i>=50))&&(*condition==1))
    {
        (*condition) =5;
        *i=0;
    }
    else if(((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772))&&(*i>=50))&&(*condition==1))
    {
        (*condition) =8;
        *i=0;
    }
    else if(((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=774)&&(mouse_x <=834))&&(*i>=50))&&(*condition==1))
    {
        (*condition) =6;
        *i=0;
    }


    if(*condition==1)
    {
        draw_sprite(page,construc,400,16);
    }
    else if(*condition==2)//Menu de s�lection des batiments
    {
        draw_sprite(page,menuC,400,16);
        afficherInfoBatimentBR(page);
        if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=462))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=1;
            *niveaubatiment=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=3;
            *niveaubatiment=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=2;
            *niveaubatiment=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=1;
            *niveaubatiment=1;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=3;
            *niveaubatiment=1;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=2;
            *niveaubatiment=1;
        }
        if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=774)&&(mouse_x <=834))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=1;
            *niveaubatiment=2;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=836)&&(mouse_x <=896))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=3;
            *niveaubatiment=2;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=898)&&(mouse_x <=958))&&(*i>=50))
        {
            *condition=21;
            *i=0;
            *typeDeBatiment=2;
            *niveaubatiment=2;
        }
        else if((mouse_b & 1)&&(*i>=50))
        {
            *condition=1;
            *i=0;
        }
    }
    else if(*condition ==21)
    {
        afficherEmplacementDisponible(liste,page,*niveaubatiment,deplAffX,deplAffY,*borne);

        if((mouse_b & 1)&&(((mouse_x<borne->xDeb-deplAffX)||(mouse_x>(borne->xFin +60)-deplAffX)||(mouse_y<borne->yDeb-deplAffY)||(mouse_y>borne->yFin-deplAffY))&&(*i>=50)))
        {
            *condition=1;
            *i=0;
        }
        else if((mouse_b & 1)&&(((mouse_x>borne->xDeb-deplAffX)||(mouse_x<(borne->xFin +60)-deplAffX)||(mouse_y>borne->yDeb-deplAffY)||(mouse_y<borne->yFin-deplAffY))&&(*i>=50)))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;
            definirCoordonnees(&x,&y,*borne,*niveaubatiment);

            if((testSiBatimentPresent(liste,x,y,*niveaubatiment)==1)&&(testSiArgentSuffisant(joueur,*niveaubatiment,*typeDeBatiment,0,voice)==1))
            {
                //play_sample(newBSound, 200,128, 1000,0);
                voice_start(voice[1]);
                ajouterBatiment(liste,*typeDeBatiment,*niveaubatiment,joueur,x,y);
            }

            *condition = 1;

            *i=0;
        }
    }
    else if(*condition ==4)
    {
        draw_sprite(page,construc,400,16);
        rect(page,588,18,588+60,18+60,makecol(0,255,0));

        if((mouse_b & 1)&&(((mouse_x>(borne->xFin +60)-deplAffX)&&(mouse_x<(borne->xFin +60+60)-deplAffX)&&(mouse_y>borne->yDeb-deplAffY)&&(mouse_y<borne->yFin-deplAffY))&&(*i>=50)))
        {


            if(testSiArgentSuffisant(joueur,0,0,5,voice)==1)//Permet la renovation du mur contre de la pierre
            {
                if(*agrandissement==0)
                {
                    if(*PDV<=8000)
                    {
                        (*PDV)+=2000;
                    }
                    else
                    {
                        (*PDV)=10000;
                    }
                }
                else if(*agrandissement==1)
                {
                    if(*PDV<=18000)
                    {
                        (*PDV)+=2000;
                    }
                    else
                    {
                        (*PDV)=20000;
                    }
                }
                else if(*agrandissement==1)
                {
                    if(*PDV<=28000)
                    {
                        (*PDV)+=2000;
                    }
                    else
                    {
                        (*PDV)=30000;
                    }
                }

            }


            *condition = 1;

            *i=0;
        }

        if((mouse_b & 1)&&(((mouse_x<borne->xDeb-deplAffX)||(mouse_x>(borne->xFin +60)-deplAffX)||(mouse_y<borne->yDeb-deplAffY)||(mouse_y>borne->yFin-deplAffY))&&(*i>=50)))
        {
            *condition=1;
            *i=0;
        }
        else if((mouse_b & 1)&&(((mouse_x>borne->xDeb-deplAffX)||(mouse_x<(borne->xFin +60)-deplAffX)||(mouse_y>borne->yDeb-deplAffY)||(mouse_y<borne->yFin-deplAffY))&&(*i>=50)))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;
            definirCoordonnees(&x,&y,*borne,1);

            if((testSiBatimentPresentA(liste,x,y)==1))//Test pour voir si il y a la place n�cessaire pour afficher le batiment
            {
                if(testSiArgentSuffisant(joueur,0,1,0,voice)==1)
                {
                    ameliorerBatiment(liste,x,y);
                }

            }


            *condition = 1;

            *i=0;
        }

    }
    else if(*condition == 5)
    {
        draw_sprite(page,construc,400,16);
        rect(page,650,18,650+60,18+60,makecol(255,0,0));
        if((mouse_b & 1)&&(((mouse_x<borne->xDeb-deplAffX)||(mouse_x>(borne->xFin +60)-deplAffX)||(mouse_y<borne->yDeb-deplAffY)||(mouse_y>borne->yFin-deplAffY))&&(*i>=50)))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;
            definirCoordonnees(&x,&y,*borne,3);

            supprimerBatimentD(liste2,liste3,x,y);//Supprimmer des batiments de D�fense

            *condition=1;
            *i=0;
        }
        else if((mouse_b & 1)&&(((mouse_x>borne->xDeb-deplAffX)||(mouse_x<(borne->xFin +60)-deplAffX)||(mouse_y>borne->yDeb-deplAffY)||(mouse_y<borne->yFin-deplAffY))&&(*i>=50)))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;
            definirCoordonnees(&x,&y,*borne,1);

            supprimerBatiment(liste,x,y);//Supprimer des batiments de ressources

            *condition = 1;

            *i=0;
        }
    }
    else if(*condition == 6)
    {
        if((*agrandissement<2)&&(testSiArgentSuffisant(joueur,0,0,3,voice)))
        {
            *agrandissement+=1;
            ajusterBase(borne,*agrandissement,PDV);
        }

        *condition = 1;
        *i=0;
    }

    (*i)++;
}

void ajouterDefense(BITMAP* page,BITMAP *menuD,t_joueur* joueur,t_listeEDD *listeEDD,t_listedef *listedef,t_listeMine *listeMine,int *condition,int *typeDeBatiment,int *i,int deplAffX, int deplAffY,int voice[4])
{
    int x,y;
    if(*condition==7)
    {
        draw_sprite(page,menuD,400,16);
        afficherInfoBatimentD(page);
        //Permet de s�lectionner quelle type de d�fense l'on va poser
        if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=462))&&(*i>=50))
        {
            *condition=71;
            *typeDeBatiment = 1;
            *i=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524))&&(*i>=50))
        {
            *condition=71;
            *typeDeBatiment = 2;
            *i=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586))&&(*i>=50))
        {
            *condition=71;
            *typeDeBatiment = 3;
            *i=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648))&&(*i>=50))
        {
            *condition=71;
            *typeDeBatiment = 4;
            *i=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710))&&(*i>=50))
        {
            *condition=71;
            *typeDeBatiment = 5;
            *i=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772))&&(*i>=50))
        {
            *condition=71;
            *typeDeBatiment = 6;
            *i=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=774)&&(mouse_x <=834))&&(*i>=50))
        {
            *condition=72;
            *typeDeBatiment = 0;
            *i=0;
        }
        else if((mouse_b & 1)&&((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=836)&&(mouse_x <=896))&&(*i>=50))
        {
            *condition=72;
            *typeDeBatiment = 1;
            *i=0;
        }
        else if((mouse_b & 1)&&(*i>=50))
        {
            *condition=1;
            *i=0;
        }
    }
    if(*condition ==71)
    {
        afficherDefenseDisponible(listeEDD,page,typeDeBatiment,deplAffX,deplAffY);
        if((mouse_b & 1)&&(*i>=50))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;

            if(*typeDeBatiment<4)
            {
                ajusterDefense(&x,&y);
            }
            else if(*typeDeBatiment>=4)
            {
                ajusterFondation(&x,&y);
            }

            if((testDefensePresente(listeEDD,x,y,*typeDeBatiment)==1)&&(testSiArgentSuffisant(joueur,0,*typeDeBatiment,1,voice)==1))
            {
                voice_start(voice[1]);
                nouvelleDefense(listeEDD,listedef,x,y,*typeDeBatiment);

            }
            *condition = 1;
            *i=0;
        }
    }
    if(*condition==72)
    {
        if((mouse_b & 1)&&(*i>=50))
        {
            x = mouse_x+deplAffX;
            y = mouse_y+deplAffY;


            ajusterDefense(&x,&y);

            if(testSiArgentSuffisant(joueur,0,*typeDeBatiment,4,voice)==1&&(testMinePresente(listeMine,x,y))==1)
            {
                voice_start(voice[1]);
                nouvelleMine(listeMine,x,y,*typeDeBatiment);
            }


            *condition = 1;
            *i=0;
        }
    }
}

void ajouterBatiment(t_listeBR *liste, int typeDeBatiment,int niveauBatiment,t_joueur* joueur, int x, int y)
{
    t_maillonBR *actuel=(t_maillonBR*) malloc(sizeof(t_maillonBR));
    if(actuel==NULL)
    {
        printf("erreur d'allocation dynamique 6\n");
        exit(EXIT_FAILURE);
    }

    actuel->x = x;
    actuel->y = y;
    actuel->niveau = niveauBatiment;

    if(typeDeBatiment == 1)
    {
        actuel->type= 1;
        actuel->tic=0;

        if(niveauBatiment==0)
        {
            actuel->ticMax=2000;
        }
        else if(niveauBatiment==1)
        {
            actuel->ticMax=2000;
        }
        else if(niveauBatiment==2)
        {
            actuel->ticMax=2000;
        }

    }
    else if(typeDeBatiment == 2)
    {
        actuel->type= 2;
        actuel->tic=0;

        if(niveauBatiment==0)
        {
            actuel->ticMax=4500;
        }
        else if(niveauBatiment==1)
        {
            actuel->ticMax=4500;
        }
        else if(niveauBatiment==2)
        {
            actuel->ticMax=4500;
        }

    }
    else if(typeDeBatiment == 3)
    {
        actuel->type= 3;
        actuel->tic=0;

        if(niveauBatiment==0)
        {
            actuel->ticMax=9500;
        }
        if(niveauBatiment==1)
        {
            actuel->ticMax=9500;
        }
        if(niveauBatiment==2)
        {
            actuel->ticMax=9500;
        }

    }
    actuel->suivant = liste->premier;
    liste->premier = actuel;
}

void afficherDefenseDisponible(t_listeEDD *listeEDD,BITMAP* page,int *typeDeBatiment,int deplAffX,int deplAffY)//Affiiche les emplacements de defenses disponibles grace � une liste chain�e � part enti�re
{
    int condition=0;
    int etape=0;
    t_maillonEDD *actuel;

    actuel = listeEDD->premier;

    if(*typeDeBatiment<4)
    {
        while(actuel!=NULL)
        {
            if(actuel->emplacementDisponible==0)
            {
                circlefill(page,(actuel->x-deplAffX)+30,(actuel->y-deplAffY)+30,25,makecol(255,0,0));
            }
            else if(actuel->emplacementDisponible==1)
            {
                circlefill(page,(actuel->x-deplAffX)+30,(actuel->y-deplAffY)+30,25,makecol(0,255,0));
            }
            actuel=actuel->suivant;
        }
    }
    else if(*typeDeBatiment>=4)
    {
        while(actuel!=NULL)
        {
            if(actuel->emplacementDisponible==1)
            {
                condition++;
                etape++;
            }
            else if(actuel->emplacementDisponible!=1)
            {
                etape++;
            }

            if((etape==4)&&(condition==4))
            {
                circlefill(page,(actuel->x-deplAffX),(actuel->y-deplAffY),50,makecol(0,255,0));
                condition=0;
                etape=0;
            }
            else if((etape==4)&&(condition!=4))
            {
                circlefill(page,(actuel->x-deplAffX),(actuel->y-deplAffY),50,makecol(255,0,0));
                condition=0;
                etape=0;
            }
            actuel=actuel->suivant;

        }
    }
    free(actuel);
}


void nouvelleDefense(t_listeEDD *listeEDD,t_listedef *listedef,int x, int y,int typeDeBatiment)//Initialise un nouveau maillon defense
{
    int i;
    t_maillonEDD *actuel;
    actuel = listeEDD->premier;

    while(actuel!=NULL)
    {
        if((actuel->x==x)&&(actuel->y==y))
        {
            actuel->emplacementDisponible = 0;
            if(typeDeBatiment<4)
            {

                ajoutDef(listedef,typeDeBatiment,x+25,y+25);
                actuel->emplacementDisponible = 0;
            }

            if(typeDeBatiment>=4)
            {
                ajoutDef(listedef,typeDeBatiment,x+50,y+50);
                for(i=0; i<4; i++)
                {
                    actuel->emplacementDisponible=0;
                    actuel=actuel->suivant;
                }
            }
        }
        if(actuel!=NULL)
        {
            actuel=actuel->suivant;
        }
    }
    actuel = NULL;
    free(actuel);
}

void nouvelleMine(t_listeMine *listeMine,int x, int y,int typeDeBatiment) //Initialise un nouveau maillon mine
{
    t_maillonMine *actuel = malloc(sizeof(t_maillonMine));

    if(actuel==NULL)
    {
        printf("erreur d'allocation dynamique 6\n");
        exit(EXIT_FAILURE);
    }

    actuel->x = x;
    actuel->y = y;
    actuel->type = typeDeBatiment;
    actuel->etat=0;

    actuel->suivant = listeMine->premier;
    listeMine->premier = actuel;


}



void afficherEmplacementDisponible(t_listeBR *liste,BITMAP* page,int niveau,int deplAffX,int deplAffY,t_borne borne)
{
    int x,y;
    int condition = 1;
    int condition2 =0;

    t_maillonBR *actuel;
    actuel = liste->premier;

    if(niveau<2)
    {
        for(x=borne.xDeb-deplAffX; x<=borne.xFin-deplAffX; x+=60)
        {
            for(y=borne.yDeb-deplAffY; y<borne.yFin-deplAffY; y+=60)
            {
                actuel = liste->premier;
                while((actuel!=NULL)&&(condition==1))
                {
                    if((x==actuel->x-deplAffX)&&(y==actuel->y-deplAffY)&&(actuel->niveau<2))
                    {
                        circlefill(page,x+30,y+30,25,makecol(255,0,0));
                        condition=0;
                    }
                    else
                    {
                        circlefill(page,x+30,y+30,25,makecol(0,255,0));
                    }
                    actuel=actuel->suivant;
                }
                condition=1;

            }
        }
        //condition==1;
        for(x=borne.xDeb-deplAffX; x<=borne.xFin-deplAffX; x+=120)
        {
            for(y=borne.yDeb-deplAffY; y<borne.yFin-deplAffY; y+=120)
            {
                actuel = liste->premier;
                while((actuel!=NULL)&&(condition==1))
                {
                    if((x==actuel->x-deplAffX)&&(y==actuel->y-deplAffY)&&(actuel->niveau==2))
                    {
                        circlefill(page,x+30,y+30,25,makecol(255,0,0));
                        circlefill(page,x+90,y+30,25,makecol(255,0,0));
                        circlefill(page,x+30,y+90,25,makecol(255,0,0));
                        circlefill(page,x+90,y+90,25,makecol(255,0,0));
                        condition=0;
                    }
                    actuel=actuel->suivant;
                }
                condition=1;

            }
        }
    }
    else if(niveau==2)
    {
        for(x=borne.xDeb-deplAffX; x<=borne.xFin-deplAffX; x+=120)
        {
            for(y=borne.yDeb-deplAffY; y<borne.yFin-deplAffY; y+=120)
            {
                actuel = liste->premier;
                while(actuel!=NULL)
                {
                    if((actuel->x>=x+deplAffX)&&(actuel->y>=y+deplAffY)&&(actuel->x<x+120+deplAffX)&&(actuel->y<y+120+deplAffY))
                    {
                        condition2=1;
                    }
                    actuel=actuel->suivant;
                }
                if(condition2==1)
                {
                    circlefill(page,x+60,y+60,50,makecol(255,0,0));
                }
                else if(condition2==0)
                {
                    circlefill(page,x+60,y+60,50,makecol(0,255,0));
                }
                condition2=0;
            }
        }
    }
    free(actuel);
}
