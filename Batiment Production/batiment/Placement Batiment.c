#include "../../prototypes.h"


int testSiArgentSuffisant(t_joueur *joueur,int niveauBatiment,int typeDeBatiment,int typeDeTest,int voice[4])//test si l'argent est suffisant et si oui le déduit
{
    int resultat = 0;

    if(typeDeTest==0)
    {
        if(typeDeBatiment==1)
        {
            if(niveauBatiment==0)
            {
                if(joueur->or>=100)
                {
                    resultat=1;
                    joueur->or-=100;
                }

            }
            else if(niveauBatiment==1)
            {
                if(joueur->or>=200)
                {
                    resultat=1;
                    joueur->or-=200;
                }
            }
            else if(niveauBatiment==2)
            {
                if(joueur->or>=300)
                {
                    resultat=1;
                    joueur->or-=300;
                }
            }
        }
        else if(typeDeBatiment==2)
        {
            if(niveauBatiment==0)
            {
                if(joueur->or>=70)
                {
                    resultat=1;
                    joueur->or-=70;
                }
            }
            else if(niveauBatiment==1)
            {
                if(joueur->or>=140)
                {
                    resultat=1;
                    joueur->or-=140;
                }
            }
            else if(niveauBatiment==2)
            {
                if(joueur->or>=210)
                {
                    resultat=1;
                    joueur->or-=210;
                }
            }
        }
        else if(typeDeBatiment==3)
        {
            if(niveauBatiment==0)
            {
                if(joueur->or>=80)
                {
                    resultat=1;
                    joueur->or-=80;
                }
            }
            else if(niveauBatiment==1)
            {
                if(joueur->or>=160)
                {
                    resultat=1;
                    joueur->or-=160;
                }
            }
            else if(niveauBatiment==2)
            {
                if(joueur->or>=240)
                {
                    resultat=1;
                    joueur->or-=240;
                }
            }
        }
    }

    if(typeDeTest==1)
    {
        if(typeDeBatiment==1)
        {
            if(joueur->metal>=70)
            {
                resultat=1;
                joueur->metal-=70;
            }
        }
        else if(typeDeBatiment==2)
        {
            if(joueur->metal>=80)
            {
                resultat=1;
                joueur->metal-=80;
            }
        }
        else if(typeDeBatiment==3)
        {
            if(joueur->metal>=90)
            {
                resultat=1;
                joueur->metal-=90;
            }
        }
        else if(typeDeBatiment==4)
        {
            if(joueur->metal>=140)
            {
                resultat=1;
                joueur->metal-=140;
            }
        }
        else if(typeDeBatiment==5)
        {
            if(joueur->metal>=170)
            {
                resultat=1;
                joueur->metal-=170;
            }
        }
        else if(typeDeBatiment==6)
        {
            if(joueur->metal>=200)
            {
                resultat=1;
                joueur->metal-=200;
            }
        }

    }
    if(typeDeTest==2)
    {
        if(joueur->pierre>=50)
        {
            resultat=1;
            joueur->pierre-=50;
        }
    }
    if(typeDeTest==3)
    {
        if(joueur->pierre>=300)
        {
            resultat=1;
            joueur->pierre-=300;
        }
    }
    if(typeDeTest==4)
    {

        if(typeDeBatiment==0)
        {
            if(joueur->metal>=10)
            {
                resultat=1;
                joueur->metal-=10;
            }
        }
        else if(typeDeBatiment==1)
        {
            if(joueur->metal>=15)
            {
                resultat=1;
                joueur->metal-=15;
            }
        }
    }
    if(typeDeTest==5)
    {
        if(joueur->pierre>=200)
        {
            resultat=1;
            joueur->pierre-=200;
        }
    }

    if(resultat==0)
    {
        //play_sample(buzzer, 200,128, 1000,0);
        voice_start(voice[2]);
    }
    return resultat;
}


void determinerBatiment(t_listeBR *liste,int *x, int *y,int *niveauBatiment)//Permet de recuperer les informations d un batiments pour le deplacer par la suite
{
    int condition =1;
    t_maillonBR *actuel;
    actuel=liste->premier;
    while(actuel!=NULL)
    {

        if((actuel->x==*x)&&(actuel->y==*y)&&(actuel->niveau<2))
        {
            *niveauBatiment = actuel->niveau;
            condition = 0;
        }
        actuel=actuel->suivant;
    }
    if(condition ==1)
    {
        actuel=liste->premier;

        while(actuel!=NULL)
        {
            if((actuel->x==*x)&&(actuel->y==*y)&&(actuel->niveau==2))//||((actuel->x==*x+60)&&(actuel->y==*y))||((actuel->x==*x)&&(actuel->y==*y+60))||((actuel->x==*x+60)&&(actuel->y==*y+60))&&((actuel->niveau==2)))
            {
                *x = actuel->x;
                *y = actuel->y;
                *niveauBatiment = actuel->niveau;
            }
            else if((actuel->x==*x-60)&&(actuel->y==*y)&&(actuel->niveau==2))
            {
                *x = actuel->x;
                *y = actuel->y;

                *niveauBatiment = actuel->niveau;
            }
            else if((actuel->x==*x)&&(actuel->y==*y-60)&&(actuel->niveau==2))
            {
                *x = actuel->x;
                *y = actuel->y;
                *niveauBatiment = actuel->niveau;
            }
            else if((actuel->x==*x-60)&&(actuel->y==*y-60)&&(actuel->niveau==2))
            {
                *x = actuel->x;
                *y = actuel->y;
                *niveauBatiment = actuel->niveau;
            }
            actuel=actuel->suivant;
        }
    }
    actuel = NULL;
    free(actuel);
}


void ameliorerBatiment(t_listeBR *liste, int x, int y)
{
    t_maillonBR *actuel;
    actuel = liste->premier;

    while(actuel!=NULL)
    {
        if((actuel->x==x)&&(actuel->y==y)&&(actuel->niveau<3))
        {
            actuel->niveau+=1;
        }
        actuel= actuel->suivant;
    }
    actuel = NULL;
    free(actuel);
}

void supprimerBatiment(t_listeBR *liste, int x, int y)
{
    t_maillonBR *actuel;
    t_maillonBR *precedent;
    actuel = liste->premier;

    int condition=0;

    if((actuel->x==x)&&(actuel->y==y))
    {
        liste->premier=actuel->suivant;
        condition=1;

    }
    else
    {
        precedent=liste->premier;
        actuel=actuel->suivant;
    }

    if(condition!=1)
    {
        while(actuel!=NULL)
        {
            if((actuel->x==x)&&(actuel->y==y))
            {
                precedent->suivant=actuel->suivant;
            }
            actuel=actuel->suivant;
            precedent=precedent->suivant;
        }
    }
    actuel = NULL;
    precedent = NULL;
    free(actuel);
    free(precedent);
}


void supprimerBatimentD(t_listedef *liste,t_listeEDD *liste2, int x, int y)
{
    t_defense *actuel;
    t_defense *precedent;
    t_maillonEDD *actuel2;

    actuel2= liste2->premier;
    actuel = liste->premier;

    int condition=0;


    if(((actuel->x==x+25)&&(actuel->y==y+25))||((actuel->x==x+50)&&(actuel->y==y+50)))
    {
        while(actuel2!=NULL)
        {
            if((actuel2->x==x&&actuel2->y==y)&&(actuel->type>=3))
            {
                actuel2->emplacementDisponible=1;
                actuel2=actuel2->suivant;
                actuel2->emplacementDisponible=1;
                actuel2=actuel2->suivant;
                actuel2->emplacementDisponible=1;
                actuel2=actuel2->suivant;
                actuel2->emplacementDisponible=1;

            }
            if((actuel2->x==x&&actuel2->y==y)&&(actuel->type<3))
            {
                actuel2->emplacementDisponible=1;
            }
            actuel2 =actuel2->suivant;
        }



        liste->premier=actuel->suivant;
        condition=1;

    }
    else
    {
        precedent=liste->premier;
        actuel=actuel->suivant;
    }

    if(condition!=1)
    {
        while(actuel!=NULL)
        {
            printf("%d\n",actuel->x);
            printf("%d\n",actuel->y);
            if(((actuel->x==x+25)&&(actuel->y==y+25))||((actuel->x==x+50)&&(actuel->y==y+50)))
            {
                while(actuel2!=NULL)
                {
                    if((actuel2->x==x&&actuel2->y==y)&&(actuel->type>=3))
                    {
                        actuel2->emplacementDisponible=1;
                        actuel2=actuel2->suivant;
                        actuel2->emplacementDisponible=1;
                        actuel2=actuel2->suivant;
                        actuel2->emplacementDisponible=1;
                        actuel2=actuel2->suivant;
                        actuel2->emplacementDisponible=1;

                    }
                    if((actuel2->x==x&&actuel2->y==y)&&(actuel->type<3))
                    {
                        actuel2->emplacementDisponible=1;
                    }
                    actuel2 =actuel2->suivant;
                }


                precedent->suivant=actuel->suivant;
            }
            actuel=actuel->suivant;
            precedent=precedent->suivant;
        }
    }
    actuel = NULL;
    actuel2 = NULL;
    precedent = NULL;
    free(actuel);
    free(actuel2);
    free(precedent);
}


void definirCoordonnees(int *x,int *y,t_borne borne,int niveau)//Permet de replacer les coordonnes dans un quadrillage
{
    int i,j;

    if(niveau<2)
    {
        for(i=borne.xDeb; i<=borne.xFin; i+=60)
        {
            for(j=borne.yDeb; j<=borne.yFin; j+=60)
            {
                if((*x>=i)&&(*x<i+60)&&(*y>=j)&&(*y<j+60))
                {
                    *x = i;
                    *y = j;
                }
            }
        }
    }
    else if(niveau==2)

    {
        for(i=borne.xDeb; i<=borne.xFin; i+=120)
        {
            for(j=borne.yDeb; j<=borne.yFin; j+=120)
            {
                if((*x>=i)&&(*x<i+120)&&(*y>=j)&&(*y<j+120))
                {
                    *x = i;
                    *y = j;
                }
            }
        }
    }
    else if(niveau==3)
    {
        for(i=0; i<=*x; i+=60)
        {
            for(j=70; j<=*y; j+=60)
            {
                if((*x>=i)&&(*x<i+60)&&(*y>=j)&&(*y<j+60))
                {
                    *x = i;
                    *y = j;
                }
            }
        }
    }
}

int testSiBatimentPresent(t_listeBR *liste,int x, int y,int niveau)
{
    int resultat = 1;
    t_maillonBR *actuel;
    actuel= liste->premier;

    if(niveau<2)
    {
        while(actuel!=NULL)
        {
            if((actuel->x==x)&&(actuel->y==y))
            {
                resultat = 0;
            }
            actuel=actuel->suivant;
        }

        actuel=liste->premier;
        while(actuel!=NULL)
        {
            if((actuel->niveau==2)&&(actuel->x<=x)&&(actuel->x+120>x)&&(actuel->y<=y)&&(actuel->y+120>y))
            {
                resultat = 0;
            }
            actuel = actuel->suivant;
        }
    }
    else if(niveau==2)
    {
        actuel= liste->premier;
        while(actuel!=NULL)
        {
            if(((x==actuel->x)&&(y==actuel->y))||((x+60==actuel->x)&&(actuel->y==y))||((x+60==actuel->x)&&(y+60==actuel->y))||((x==actuel->x)&&(y+60==actuel->y)))
            {
                resultat=0;
            }
            actuel=actuel->suivant;
        }

    }
    actuel = NULL;
    free(actuel);

    return resultat;
}

int testSiBatimentPresentA(t_listeBR *liste,int x, int y)//Test si des batiments sont présent aux alentours d'un batiments qui va s'ameliorer
{
    int resultat = 1;
    t_maillonBR *actuel;
    actuel= liste->premier;



    while(actuel!=NULL)
    {
        if(((x+60==actuel->x)&&(actuel->y==y))||((x+60==actuel->x)&&(y+60==actuel->y))||((x==actuel->x)&&(y+60==actuel->y)))
        {
            resultat=0;
        }
        actuel=actuel->suivant;
    }

    actuel= liste->premier;
    while(actuel!=NULL)
    {
        if((actuel->x==x&&actuel->y==y)&&(actuel->niveau<1))
        {
            resultat=1;
        }
        actuel=actuel->suivant;
    }

    actuel = NULL;
    free(actuel);

    return resultat;
}


int testDefensePresente(t_listeEDD *listeEDD,int x,int y,int typeDeBatiment)
{
    int resultat = 0;
    int condition;


    t_maillonEDD *actuel;
    actuel = listeEDD->premier;

    if(typeDeBatiment<4)
    {
        while(actuel!=NULL)
        {
            if((actuel->x==x)&&(actuel->y==y))
            {
                if(actuel->emplacementDisponible==1)
                {
                    resultat = 1;
                }
            }
            actuel=actuel->suivant;
        }
    }
    else if(typeDeBatiment>=4)
    {
        while(actuel!=NULL)
        {
            if((actuel->x==x)&&(actuel->y==y))
            {
                if(actuel->emplacementDisponible==1)
                {
                    condition++;
                }
                actuel=actuel->suivant;
                if(actuel->emplacementDisponible==1)
                {
                    condition++;
                }
                actuel=actuel->suivant;
                if(actuel->emplacementDisponible==1)
                {
                    condition++;
                }

                actuel=actuel->suivant;
                if(actuel->emplacementDisponible==1)
                {
                    condition++;
                }
                if(condition==4)
                {
                    resultat=1;
                }
            }
            actuel=actuel->suivant;
        }


    }
    actuel = NULL;
    free(actuel);
    return resultat;
}

int testMinePresente(t_listeMine *liste, int x,int y)
{
    int resultat=1;
    t_maillonMine *actuel;

    if(liste->premier==NULL)
    {
        resultat = 1;
    }
    else
    {
        actuel=liste->premier;
        while(actuel!=NULL)
        {
            if((actuel->x==x)&&(actuel->y==y))
            {
                resultat = 0;
            }
            actuel=actuel->suivant;
        }
    }

    return resultat;
}

void ajusterDefense(int*x,int*y)
{
    int i,j;
    for(i=0; i<=*x; i+=60)
    {
        for(j=70; j<=*y; j+=60)
        {
            if((*x>=i)&&(*x<i+60)&&(*y>=j)&&(*y<j+60))
            {
                *x = i;
                *y = j;
            }
        }
    }
}

