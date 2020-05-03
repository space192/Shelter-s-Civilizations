#include "../prototypes.h"

void recupererBatimentProduction(t_listeBR *liste, int niveau)
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int i,n;
    t_maillonBR temp;           //creation d'un maillon temporaire pour les Batiment de production afin d'eviter de perdre l'adresse de nos liste chainée
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/BR.sav", "rb"); //gestion du multi niveau
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
            liste->premier->ticMax = temp.ticMax; //du au maillon temporaire on est obligé de recuperer les informations une par une dans les nouveaux maillon
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
    t_maillonBR *nouveau = malloc(sizeof(t_maillonBR)); //creation de maillon vide
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
            fichier = fopen("sauvegarde/Niveau 1/defense.sav", "rb"); //gestion multi fichier
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
        for(i=0; i < n ; i++)                                   //meme systeme de maillon temporaire pour les defenses(du a un default de conception de la liste chainée
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
    t_defense *nouveau = malloc(sizeof(t_defense));     //ajout maillon defense vide
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
            fichier = fopen("sauvegarde/Niveau 1/EDD.sav", "rb"); //gestion multi niveau
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
                nouveau->y = temp.y;                                                            //ici gestion de recuperer les maillons dans l'ordre du fait de leur placement
                nouveau->afficherFondation = temp.afficherFondation;                            //car le emplacement disponible fonctionne par 4 il est donc impossible de separer 1 et 2 de l'autre
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
        allegro_message("erreur lor du chargement de la sauvegarde");  //recuperation non binaire nieau debloqué
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
            fichier = fopen("sauvegarde/Niveau 1/anecdote.sav", "rb"); //gestion multi niveau
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

void recupererNom(char *chaine)
{
    FILE *fichier = fopen("sauvegarde/sauvegardeNom.sav", "r"); //recuperation du nom du joueur
    if(fichier == NULL)
    {
        printf("erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    else
    {
        fgets(chaine, 99, fichier);
        fclose(fichier);
    }
}

void ajouterMineVide(t_listeMine *liste)
{
    t_maillonMine *nouveau = malloc(sizeof(t_maillonMine));
    if(nouveau == NULL)
    {
        allegro_message("erreur d'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    else
    {
        nouveau->suivant = liste->premier;
        liste->premier = nouveau;
    }
}

void recupererMine(t_listeMine *liste, int niveau)
{
    FILE *fichier= NULL, *fichier2= NULL;
    switch(niveau)
    {
    case 1:
        {
            fichier = fopen("sauvegarde/Niveau 1/Mine.sav", "rb"); //gestion du multi fichier
            fichier2 = fopen("sauvegarde/Niveau 1/nMine.sav", "r");
            break;
        }
    case 2:
        {
            fichier = fopen("sauvegarde/Niveau 2/Mine.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 2/nMine.sav", "r");
            break;
        }
    case 3:
        {
            fichier = fopen("sauvegarde/Niveau 3/Mine.sav", "rb");
            fichier2 = fopen("sauvegarde/Niveau 3/nMine.sav", "r");
            break;
        }
    case 4:
        {
            fichier = fopen("sauvegarde/Endless Mode/Mine.sav", "rb");
            fichier2 = fopen("sauvegarde/Endless Mode/nMine.sav", "r");
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
        allegro_message("erreur fichier Mine");
        exit(EXIT_FAILURE);
    }
    else
    {
        int i,max;
        t_maillonMine temp;
        fscanf(fichier2, "%d", &max);
        for(i=0; i < max; i++)
        {
            ajouterMineVide(liste);
            fread(&temp, sizeof(t_maillonMine), 1 , fichier); //recuperation de la liste de mine
            liste->premier->x = temp.x;
            liste->premier->y = temp.y;
            liste->premier->type = temp.type;
            liste->premier->etat = temp.etat;
        }
        fclose(fichier);
        fclose(fichier2);
    }
}
