#include "../prototypes.h"

void recupererBatimentProduction(t_listeBR *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int i,n;
    t_maillonBR temp;
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
            fichier2 = fopen("sauvegarde/Niveau 2/NBR.sav", "r");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/BR.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 3/NBR.sav", "r");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/BR.sav", "rb");
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
        allegro_message("erreur batiment production");
        exit(EXIT_FAILURE);
    }
    else
    {
        liste->premier = NULL;
        fscanf(fichier2, "%d", &n);
        for(i=0; i < n ; i++)
        {
            AjouterMaillonBRVide(liste);
            fread(&temp, sizeof(t_maillonBR), 1, fichier);
            liste->premier->niveau = temp.niveau;
            liste->premier->tic = temp.tic;
            liste->premier->ticMax = temp.ticMax;
            liste->premier->type = temp.type;
            liste->premier->x = temp.x;
            liste->premier->y = temp.y;
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
    t_defense temp;
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
        allegro_message("erreur defense");
        exit(EXIT_FAILURE);
    }
    else
    {
        liste->premier = NULL;
        fscanf(fichier2, "%d", &n);
        for(i=0; i < n ; i++)
        {
            AjouterMaillonDefenseVide(liste);
            fread(&temp, sizeof(t_defense), 1, fichier);
            liste->premier->x = temp.x;
            liste->premier->y = temp.y;
            liste->premier->cadenceMax = temp.cadenceMax;
            liste->premier->angle = 64;
            liste->premier->centre = temp.centre;
            liste->premier->degat = temp.degat;
            liste->premier->liste = malloc(sizeof(t_listeBalle));
            liste->premier->liste->premier = NULL;
            liste->premier->radius = temp.radius;
            liste->premier->target = temp.target;
            liste->premier->test = temp.test;
            liste->premier->type = temp.type;
            liste->premier->valeurCanon = temp.valeurCanon;
        }
    }
    fclose(fichier);
    fclose(fichier2);
}

void AjouterMaillonDefenseVide(t_listedef *liste)
{
    t_defense *nouveau = malloc(sizeof(t_defense));
    if(liste->premier == NULL)
    {
        nouveau->suivant = NULL;
        liste->premier = nouveau;
    }
    else
    {
        nouveau->suivant = liste->premier;
        liste->premier = nouveau;
    }
}


t_maillonEDD *ajoutEDDnada()
{
    t_maillonEDD *nouveau = malloc(sizeof(t_maillonEDD));
    return nouveau;
}

void recupererEmplacementDispo(t_listeEDD *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int i,n;
    t_maillonEDD temp;
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
        allegro_message("erreur emplacement dispo");
        exit(EXIT_FAILURE);
    }
    else
    {
        t_maillonEDD *actuel = liste->premier;
        t_maillonEDD *precedent = liste->premier;
        liste->premier = NULL;
        int compteur, j;
        fscanf(fichier2, "%d", &n);
        for(i=0; i < n; i++)
        {
            compteur = 0;
            fread(&temp, sizeof(t_maillonEDD), 1, fichier);
            actuel = liste->premier;
            precedent = liste->premier;
            while(actuel!=NULL)
            {
                if(temp.numeroEDD > actuel->numeroEDD)
                {
                    compteur++;
                }
                precedent = actuel;
                actuel = actuel->suivant;
            }
            actuel = liste->premier;
            precedent = liste->premier;
            for(j=0; j < compteur; j++)
            {
                precedent = actuel;
                actuel = actuel->suivant;
            }
            t_maillonEDD *nouveau = ajoutEDDnada();
            if(actuel == liste->premier)
            {
                nouveau->suivant = liste->premier;
                liste->premier = nouveau;
                nouveau->x = temp.x;
                nouveau->y = temp.y;
                nouveau->afficherFondation = temp.afficherFondation;
                nouveau->emplacementDisponible = temp.emplacementDisponible;
                nouveau->numeroEDD = temp.numeroEDD;
            }
            else
            {
                nouveau->suivant = actuel;
                precedent->suivant = nouveau;
                nouveau->x = temp.x;
                nouveau->y = temp.y;
                nouveau->afficherFondation = temp.afficherFondation;
                nouveau->emplacementDisponible = temp.emplacementDisponible;
                nouveau->numeroEDD = temp.numeroEDD;
            }
        }
        actuel = NULL;
        precedent = NULL;
        free(actuel);
        free(precedent);
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

int recupererNiveauUnlock()
{
    int temp;
    FILE *fichier = fopen("sauvegarde/unlock.sav", "r");
    if(fichier == NULL)
    {
        allegro_message("erreur lor du chargement de la sauvegarde");
    }
    fscanf(fichier, "%d", &temp);
    fclose(fichier);
    return temp;
}

void recupererAnecdote(t_joueur *joueur, int *TBase, int *scoreE, int *PDV, int sauvegarde)
{
    FILE *fichier = fopen("sauvegarde/anecdote.sav", "rb");
    switch(sauvegarde)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/anecdote.sav", "rb");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/anecdote.sav", "rb");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/anecdote.sav", "rb");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/anecdote.sav", "rb");
            break;
        }
    default:
        {
            fichier = NULL;
            break;
        }
    }
    if(fichier == NULL)
    {
        printf("erreur lors de l'ouverture du fichier");
    }
    else
    {
        fread(joueur, sizeof(t_joueur), 1, fichier);
        fread(TBase, sizeof(int), 1, fichier);
        fread(scoreE, sizeof(int), 1, fichier);
        fread(PDV, sizeof(int), 1, fichier);
    }
    fclose(fichier);
}

