#include "../prototypes.h"

void recupererBatimentProduction(t_listeBR *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int i,n;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/BR.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 1/NBR.sav", "r");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/BR.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau2/NBR.sav", "r");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/BR.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 3/NBR.sav", "r");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/BR.sav", "wb+");
            fichier2 = fopen("sauvegarde/Endless Mode/NBR.sav", "r");
            break;
        }
    default:
        {
            fichier = NULL;
            fichier2 = NULL;
            break;
        }
    }
    if(fichier == NULL || fichier2 == NULL)
    {
        allegro_message("erreur lors de la creation du fichier\nou le niveau n'a pas été precisé");
        exit(EXIT_FAILURE);
    }
    else
    {
        fscanf(fichier2, "%d", &n);
        for(i=0; i < n ; i++)
        {
            AjouterMaillonBRVide(liste);
            fread(liste->premier, sizeof(t_maillonBR), 1, fichier);
        }
    }
    fclose(fichier);
    fclose(fichier2);
}

void AjouterMaillonBRVide(t_listeBR *liste)
{
    t_maillonBR *nouveau = malloc(sizeof(t_maillonBR));
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void recupererDefense(t_listedef *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int i,n;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/defense.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 1/Ndefense.sav", "r");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/defense.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 2/Ndefense.sav", "r");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/defense.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 3/Ndefense.sav", "r");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/defense.sav", "rb");
            fichier2 = fopen("sauvegarde/Endless Mode/Ndefense.sav", "r");
            break;
        }
    default:
        {
            fichier = NULL;
            fichier2 = NULL;
            break;
        }
    }
    if(fichier == NULL || fichier2 == NULL)
    {
        allegro_message("erreur lors de la creation du fichier\nou le niveau n'a pas été precisé");
        exit(EXIT_FAILURE);
    }
    else
    {
        fscanf(fichier2, "%d", &n);
        for(i=0; i < n ; i++)
        {
            AjouterMaillonDefenseVide(liste);
            fread(liste->premier, sizeof(t_defense), 1, fichier);
        }
    }
    fclose(fichier);
    fclose(fichier2);
}

void AjouterMaillonDefenseVide(t_listedef *liste)
{
    t_defense *nouveau = malloc(sizeof(t_defense));
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


void recupererEmplacementDispo(t_listeEDD *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int i,n;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/EDD.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 1/NEDD.sav", "r");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/EDD.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 2/NEDD.sav", "r");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/EDD.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 3/NEDD.sav", "r");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/EDD.sav", "rb");
            fichier2 = fopen("sauvegarde/Endless Mode/NEDD.sav", "r");
            break;
        }
    default:
        {
            fichier = NULL;
            fichier2 = NULL;
            break;
        }
    }
    if(fichier == NULL || fichier2 == NULL)
    {
        allegro_message("erreur lors de la creation du fichier\nou le niveau n'a pas été precisé");
        exit(EXIT_FAILURE);
    }
    else
    {
        fscanf(fichier2, "%d", &n);
        for(i=0; i < n; i++)
        {
            ajouterEDDVide(liste);
            fread(liste->premier, sizeof(t_maillonEDD), 1, fichier);
        }
    }
    fclose(fichier);
    fclose(fichier2);
}

void ajouterEDDVide(t_listeEDD *liste)
{
    t_maillonEDD *nouveau = malloc(sizeof(t_maillonEDD));
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


t_listeEDD *triEDD(t_listeEDD *liste)
{
    t_listeEDD *liste2 = malloc(sizeof(t_listeEDD));
    liste2->premier=NULL;
    t_maillonEDD *actuel = liste->premier;
    t_maillonEDD *actuel2 = NULL;
    t_maillonEDD *precedent=liste->premier;
    int min;
    while(liste->premier->suivant != NULL)
    {
        actuel2=NULL;
        actuel=liste->premier;
        min = liste->premier->numeroEDD;
        while(actuel!=NULL)
        {
            if(min > actuel->numeroEDD)
            {
                min = actuel->numeroEDD;
            }
            actuel=actuel->suivant;
        }
        actuel = liste->premier;
        precedent= liste->premier;
        while(actuel->numeroEDD != min)
        {
            precedent = actuel;
            actuel = actuel->suivant;
        }
        if(actuel->suivant==NULL)
        {
           precedent->suivant = NULL;
        }
        else if(min == liste->premier->numeroEDD)
        {
            liste->premier = liste->premier->suivant;
        }
        else
        {
            precedent->suivant = actuel->suivant;
        }
        if(liste2->premier==NULL)
        {
            liste2->premier = actuel;
            liste2->premier->suivant = NULL;
        }
        else
        {
            actuel2=liste2->premier;
            while(actuel2->suivant!=NULL)
            {
                actuel2=actuel2->suivant;
            }
            actuel2->suivant = actuel;
            actuel2->suivant->suivant = NULL;
        }
    }
    actuel2=liste2->premier;
    while(actuel2->suivant!=NULL)
    {
        actuel2=actuel2->suivant;
    }
    actuel2->suivant = liste->premier;
    actuel2->suivant->suivant = NULL;
    liste->premier = NULL;
    return liste2;
}



