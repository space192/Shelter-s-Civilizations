#include "../prototypes.h"


void SauvegarderBatimentProduction(t_listeBR *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int n=0;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/BR.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 1/NBR.sav", "w");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/BR.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 2/NBR.sav", "w");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/BR.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 3/NBR.sav", "w");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/BR.sav", "wb+");
            fichier2 = fopen("sauvegarde/Endless Mode/NBR.sav", "w");
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
        allegro_message("erreur fichier batiment production");
    }
    else
    {
        t_maillonBR *actuel = liste->premier;
        while(actuel != NULL)
        {
            fwrite(actuel, sizeof(t_maillonBR), 1, fichier);
            n++;
            actuel = actuel->suivant;
        }
        fprintf(fichier2, "%d", n);
        actuel = NULL;
        free(actuel);
    }
    fclose(fichier);
    fclose(fichier2);
}

void SauvegarderEmplacementDisponible(t_listeEDD *liste, int niveau)
{
    t_maillonEDD *actuel = liste->premier;
    FILE *fichier = NULL;
    FILE *fichier2= NULL;
    int n=0;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/EDD.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 1/NEDD.sav", "w");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/EDD.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 2/NEDD.sav", "w");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/EDD.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 3/NEDD.sav", "w");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/EDD.sav", "wb+");
            fichier2 = fopen("sauvegarde/Endless Mode/NEDD.sav", "w");
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
        allegro_message("erreur fichier emplacement dispo");
    }
    else
    {
        while(actuel != NULL)
        {
            fwrite(actuel, sizeof(t_maillonEDD), 1, fichier);
            n++;
            actuel = actuel->suivant;
        }
        fprintf(fichier2, "%d", n);
    }
    fclose(fichier);
    fclose(fichier2);
    free(actuel);
}

void SauvegarderDefense(t_listedef *liste, int niveau)
{
    t_defense *actuel = liste->premier;
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int n=0;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/defense.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 1/Ndefense.sav", "w");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/defense.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 2/Ndefense.sav", "w");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/defense.sav", "wb+");
            fichier2 = fopen("sauvegarde/Niveau 3/Ndefense.sav", "w");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/defense.sav", "wb+");
            fichier2 = fopen("sauvegarde/Endless Mode/Ndefense.sav", "w");
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
        allegro_message("erreur fichier defense");
    }
    else
    {
        while(actuel != NULL)
        {
            fwrite(actuel, sizeof(t_defense), 1, fichier);
            n++;
            actuel = actuel->suivant;
        }
        fprintf(fichier2, "%d", n);
    }
    fclose(fichier);
    fclose(fichier2);
    free(actuel);
}


void sauvegarderNiveauUnlock(int sauvegarde)
{
    FILE *fichier = fopen("sauvegarde/unlock.sav", "r");
    if(fichier == NULL)
    {
        allegro_message("erreur fichier Unlock");
    }
    else
    {
        int test;
        fscanf(fichier, "%d", &test);
        if(test < sauvegarde)
        {
            freopen("sauvegarde/unlock.sav", "w", fichier);
            if(fichier != NULL)
            {
                fprintf(fichier, "%d", sauvegarde);
            }
        }
    }
    fclose(fichier);
}

void sauvegardeAnecdote(t_joueur joueur, int TBase, int scoreE, int PDV, int sauvegarde)
{
    FILE *fichier = NULL;
    switch(sauvegarde)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/anecdote.sav", "wb");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/anecdote.sav", "wb");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/anecdote.sav", "wb");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/anecdote.sav", "wb");
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
        allegro_message("erreur fichier anecdote");
    }
    else
    {
        fwrite(&joueur, sizeof(t_joueur), 1, fichier);
        fwrite(&TBase, sizeof(int), 1, fichier);
        fwrite(&scoreE, sizeof(int), 1, fichier);
        fwrite(&PDV, sizeof(int), 1, fichier);
        fclose(fichier);
    }
}


void sauvegarderNom(char *nom)
{
    FILE *fichier = fopen("sauvegarde/sauvegardeNom.sav", "w");
    if(fichier == NULL)
    {
        allegro_message("erreur fichier Nom");
    }
    else
    {
        fprintf(fichier, "%s", nom);
        fclose(fichier);
    }
}


void sauvegarderMine(t_listeMine *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/Mine.sav", "wb");
            fichier2 = fopen("sauvegarde/Niveau 1/nMine.sav", "w");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/Mine.sav", "wb");
            fichier2 = fopen("sauvegarde/Niveau 2/nMine.sav", "w");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/Mine.sav", "wb");
            fichier2 = fopen("sauvegarde/Niveau 3/nMine.sav", "w");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/Mine.sav", "wb");
            fichier2 = fopen("sauvegarde/Endless Mode/nMine.sav", "w");
            break;
        }
    default:
        {
            fichier = NULL;
            fichier2 = NULL;
        }
    }
    if(fichier == NULL || fichier2 == NULL)
    {
        allegro_message("erreur fichier Mine");
    }
    else
    {
        int n = 0;
        t_maillonMine *actuel = liste->premier;
        while(actuel != NULL)
        {
            fwrite(actuel, sizeof(t_maillonMine), 1, fichier);
            n++;
            actuel = actuel->suivant;
        }
        actuel = NULL;
        free(actuel);
        fprintf(fichier2, "%d", n);
        fclose(fichier);
        fclose(fichier2);
    }
}
