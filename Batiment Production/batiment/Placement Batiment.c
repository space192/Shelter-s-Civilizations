#include "../../prototypes.h"


int testSiArgentSuffisant(t_joueur *joueur,int niveauBatiment,int typeDeBatiment,int typeDeTest,SAMPLE *buzzer)
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
            if(joueur->metal>=160)
                {
                    resultat=1;
                    joueur->metal-=160;
                }
        }
        else if(typeDeBatiment==6)
        {
            if(joueur->metal>=180)
                {
                    resultat=1;
                    joueur->metal-=180;
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

    if(resultat==0)
    {
        play_sample(buzzer, 200,128, 1000,0);
    }
    return resultat;
}


void determinerBatiment(t_listeBR *liste,int *x, int *y,int *niveauBatiment)
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
    free(actuel);
}

void supprimerBatiment(t_listeBR *liste, int x, int y)
{
    t_maillonBR *actuel;
    t_maillonBR *precedent;
    actuel = liste->premier;

    if((actuel->x==x)&&(actuel->y==y))
    {
        liste->premier=actuel->suivant;
    }
    else
    {
        precedent=liste->premier;
        actuel=actuel->suivant;
    }

    while(actuel!=NULL)
    {
        if((actuel->x==x)&&(actuel->y==y))
        {
            precedent->suivant=actuel->suivant;
        }
        actuel=actuel->suivant;
        precedent=precedent->suivant;
    }
    free(actuel);
    free(precedent);
}



void definirCoordonnees(int *x,int *y,t_borne borne,int niveau)
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
    free(actuel);
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

