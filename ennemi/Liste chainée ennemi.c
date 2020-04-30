#include "../prototypes.h"

void initAncre(t_listeMechant* horde)
{
    horde->premier = NULL;//(t_ennemi*)malloc(sizeof(t_ennemi));

    horde->nbElement = 0; //nb de mechant sur la map
    //horde->premier = creerEnnemis((rand()%2), 1, 1, horde->nbElement); //on ajoute un ennemi car il faut au minimum un ennemi
    horde->cmptG = 0;
    horde->tmpG = 20; //temps entre chaque generation d'ennemis
    horde->cmptV = 0;
    horde->tmpV = 200; //temsp entre les vagues

    horde->listeActua = 0;

    horde->vagueM = 0;
    horde->nbFait = 0;
    horde->vagueFinis = 0; //on commence avec la vague qui n'est pas finis
}

void actualiserListeMechant(t_listeMechant* horde, int niveau)  ///CARACTERISTIQUE DES MECHANTS EN FONCTION DU NIVEAU
{
    if(niveau == 1)  //pour le niveau 1
    {
        horde->typeMechant[0] = 10 * (horde->vagueM/2 + 1); //nombre de petit mechant par vague
        horde->typeMechant[1] = 5 * (horde->vagueM/2 + 1); //nombre de moyen mechant
        horde->typeMechant[2] = 0 * (horde->vagueM/2 + 1); //nombre de boss

        horde->pvM[0] = 100; //point de vie des mechants
        horde->pvM[1] = 250;
        horde->pvM[2] = 1000;

        horde->degatsM[0] = 5; //degat des mechants
        horde->degatsM[1] = 10;
        horde->degatsM[2] = 20;

        horde->tmpDegat[0] = 30; //vitesse t'attaque des mechants
        horde->tmpDegat[1] = 100;
        horde->tmpDegat[2] = 200;

        horde->nbVague = 5;
    }
    else if(niveau == 2)
    {
        horde->typeMechant[0] = 10;
        horde->typeMechant[1] = 5;
        horde->typeMechant[2] = 1;

        horde->pvM[0] = 100;
        horde->pvM[1] = 250;
        horde->pvM[2] = 1000;

        horde->degatsM[0] = 5;
        horde->degatsM[1] = 10;
        horde->degatsM[2] = 20;

        horde->tmpDegat[0] = 30;
        horde->tmpDegat[1] = 100;
        horde->tmpDegat[2] = 200;

        horde->nbVague = 5;
    }
    else if(niveau == 3)
    {
        horde->typeMechant[0] = 10;
        horde->typeMechant[1] = 5;
        horde->typeMechant[2] = 2;

        horde->pvM[0] = 100;
        horde->pvM[1] = 250;
        horde->pvM[2] = 1000;

        horde->degatsM[0] = 5;
        horde->degatsM[1] = 10;
        horde->degatsM[2] = 20;

        horde->tmpDegat[0] = 30;
        horde->tmpDegat[1] = 100;
        horde->tmpDegat[2] = 200;

        horde->nbVague = 5;
    }

//horde->vagueM = 0;
    horde->nbFait = 0;
    horde->nbAfaire = horde->typeMechant[0] + horde->typeMechant[1] + horde->typeMechant[2]; //nombre de mechant à faire
    horde->listeActua = 1; //la liste a ete actualise

}

int typeEnnemiGenerer(int nbMechant[3])
{
    int alea = 0, generer = 0;

    while(generer == 0) //on sort un nombre du tableau avec le nombre de mechant
    {
        alea = rand()%3;

        if(nbMechant[alea] > 0)
        {
            nbMechant[alea]--;
            generer = 1;
        }
    }
    return alea;
}

void ajouterPremierEnnemi(t_listeMechant* ancre)
{
    t_ennemi* nouveau = (t_ennemi*)malloc(sizeof(t_ennemi)); //On déclare le nouveau maillon au quel on alloue dynamiquement un espace mémoire

    ancre->nbElement = 1;   //On incrémente la taille de la chaine

    if (ancre == NULL || nouveau == NULL) //on test que l'allocation dynamique a fonctionnée et que les donnees recues en parametre sont bonnes
    {
        printf("Donnee impossible à lire ou allocation dynamique non reussie dans le programme ajouterEnnemi");
        exit(EXIT_FAILURE);
    }
    ancre->premier = creerEnnemis(ancre, typeEnnemiGenerer(ancre->typeMechant), 1, 1, ancre->nbElement);   //On remplie le nouveau maillon avec ces données /
    ancre->premier->suivant = NULL;
}

void ajouterEnnemi(t_listeMechant* ancre)
{
    t_ennemi* nouveau = (t_ennemi*)malloc(sizeof(t_ennemi)); //On déclare le nouveau maillon au quel on alloue dynamiquement un espace mémoire
    t_ennemi* actuel; //On déclare une variable qui permet de parcourir la liste
    ancre->nbElement++;   //On incrémente la taille de la chaine

    if (ancre == NULL || nouveau == NULL) //on test que l'allocation dynamique a fonctionnée et que les donnees recues en parametre sont bonnes
    {
        printf("Donnee impossible à lire ou allocation dynamique non reussie dans le programme ajouterEnnemi");
        exit(EXIT_FAILURE);
    }

    actuel = ancre->premier; //si ancre n'est pas NULL, alors on peut continuer le programme
    nouveau = creerEnnemis(ancre, typeEnnemiGenerer(ancre->typeMechant), 1, 1, ancre->nbElement);   //On remplie le nouveau maillon avec ces données /

    while(actuel->suivant != NULL) //on teste tant que l'adresse du maillon suivant n'est pas nulle est donc qu'on est pas arrivee a la fin de la liste
        actuel = actuel->suivant;  //On avance dans la liste en passant à l'élément suivant

    nouveau->suivant = NULL;   //On donne comme adresse suivante à cet éléement NULL car c'est le dernier de la liste
    actuel->suivant = nouveau;   //L'ancien dernier element de la liste pointe maintenant sur le nouvel element suivant
}

void creer_horde(t_listeMechant* ancreH, int niveau, int vit)
{
    int niveauFINIS = 0;

    if(ancreH->listeActua == 0)
        actualiserListeMechant(ancreH, niveau);

    if(ancreH->vagueFinis == 1) //si la vague est finie
    {
        //on compte pour attendre le debut de la prochaine vague
        ancreH->cmptV++;
        if(ancreH->cmptV >= ancreH->tmpV)
        {
            ancreH->cmptV = 0; //quand on a finis de compter, on remet le compteur a 0
            ancreH->vagueFinis = 0; //et la vague suivante peut venir
            ancreH->listeActua = 0;
        }
    }
    else if(ancreH->vagueFinis == 0) //si la vague n'est pas finis
    {
        if(ancreH->nbElement < NB_MECHANT_MAX) //si il n'y a pas trop d'ennemis sur la map
        {

            if( ancreH->nbFait < ancreH->nbAfaire)//tant que la horde contient moins d'ennemis que demandé pour cette vague, on en ajoute
            {
                ancreH->cmptG++;
                if((ancreH->cmptG >= ancreH->tmpG)) //on incremente le compteur pour qu'il ajoute un ennemi a la horde à un certains interval de temps
                {
                    if(ancreH->nbElement <= 0)
                    {
                        ajouterPremierEnnemi(ancreH);
                        ancreH->nbFait++;
                    }
                    else
                    {
                        ajouterEnnemi(ancreH); //on ajoute un ennemi
                        ancreH->nbFait++;
                    }

                    ancreH->cmptG = 0; //on remet le compteur à 0
                }
            }
            else if((ancreH->nbFait == ancreH->nbAfaire) && (ancreH->nbElement <= 0)) //si on a fait tous les mechant et qu'il n'en reste plus sur la map, on indique que la vague est finie
            {
                ancreH->vagueFinis = 1;
                ancreH->vagueM ++;

                if(ancreH->vagueM >= ancreH->nbVague)
                {
                    niveauFINIS = 1;//le niveau est finis
                    printf("LE NIVEAU EST FINIS MOTHERFUCKER, j'ecris ca pour pas avoir de warning psq on a pas encore fait de quoi passer au niveau suivant %d\n", niveauFINIS);
                }
            }
        }
    }//fin else if vague pas finie
    //printf("vagueA : %d, nbVague : %d,  nbFait %d - %d a faire, nbElement :%d\n", ancreH->vagueM, ancreH->nbVague, ancreH->nbFait, ancreH->nbAfaire, ancreH->nbElement);
}

void posAlea(int* x, int* y)
{
    int ptAppa = 0; //indice pour definir aleatoiremeent le point d'apparition du monstre
    int xMax = 0, xMin = 0; //varaible pour définir les zones d'apparaitions
    int yMax = 0, yMin = 0;


    ptAppa = rand()%(3); //donne un nombre entre 1 et 3

    switch(ptAppa)
    {
    case 0 : //point d'apparition du haut
        xMin = 3690;
        xMax = 3690;
        yMin = 810;
        yMax = 810;
        break;
    case 1 : //point d'apparition du haut
        xMin = 3450;
        xMax = 3450;
        yMin = 1881;
        yMax = 1920;
        break;
    case 2 : //point d'apparition du haut
        xMin = 3220;
        xMax = 3260;
        yMin = 2700;
        yMax = 2700;
        break;
    }

    *x = (rand()%(xMax-xMin+1)) + xMin; //on donne une position aleatoire dans ces zones prédéfinies
    *y = (rand()%(yMax-yMin+1)) + yMin;
}

t_ennemi *creerEnnemis(t_listeMechant *ancre, int type, int tmpDx, int tmpDy, int nb)
{
    t_ennemi *nouveau = malloc(sizeof(t_ennemi));
    int x = 0, y = 0;

    posAlea(&x, &y); //on recupere des coordonnees d'une zone d'apparition

    nouveau->depx = 0;
    nouveau->depy = 0;
    nouveau->tx = 30;
    nouveau->ty = 30;
    nouveau->x = x - nouveau->tx/2;
    nouveau->y = y - nouveau->ty/2;
    nouveau->type = type;
    nouveau->numero = nb;
    nouveau->centre = (nouveau->tx/2 + nouveau->ty/2);

    nouveau->cmptDx = 0;
    nouveau->cmptDy = 0;
    nouveau->tmpDx = tmpDx;
    nouveau->tmpDy = tmpDy;

    nouveau->cmptImg = 0;
    nouveau->tmpImg = 5;
    nouveau->imgA = 0;
    nouveau->angle = 2;

    nouveau->pvM = ancre->pvM[type];
    nouveau->degatsM = ancre->degatsM[type];
    nouveau->cmptDeg = 0;
    nouveau->tmpDeg = ancre->tmpDegat[type];

    return nouveau;
}

void supprimerElementTete(t_listeMechant* ancre) //code insipiré de openClassRoom : https://openclassrooms.com/en/courses/19980-apprenez-a-programmer-en-c/19733-les-listes-chainees
{
    if (ancre == NULL) //On test que l'ancre que l'on reçoit en paramètre est correctement reçue, sinon on arrete le programme
    {
        printf("\nL'ancre n'est pas lue dans le programme supprimerMaillonTete");
        exit(EXIT_FAILURE);
    }

    if (ancre->premier != NULL) //On test que la liste existe et contient au moins un élément
    {
        t_ennemi* aSupprimer = ancre->premier; //On déclare un maillon que l'on remplit avec l'adresse du maillon à supprimer
        ancre->premier = ancre->premier->suivant;  //On attache l'ancre au maillon qui seconde le premier qui a été supprimé
        ancre->nbElement--;  //On décremente la taille de la chaine car on a enlevé un élément

        free(aSupprimer);  //On libère l'espace mémoire de du maillon que l'on a supprimer
    }
}

void supprimerListe(t_listeMechant* ancre)
{
    int i=0;  //On déclare un compteur de boucle

    for(i=0; i<ancre->nbElement; i++) //On supprime les element de la liste un à un
    {
        supprimerElementTete(ancre);
    }
}

void attaquerMur(t_listeMechant* horde, int* pvMur)
{
    int degatInfli = 0;
    t_ennemi* actuel; //On déclare une variable qui permet de parcourir la liste

    if (horde == NULL) //on test que l'allocation dynamique a fonctionnée et que les donnees recues en parametre sont bonnes
    {
        printf("Donnee impossible à lire ou allocation dynamique non reussie dans le programme attaquerMur\n");
        exit(EXIT_FAILURE);
    }
    if(horde->premier!=NULL)
    {
        actuel = horde->premier; //si horde n'est pas NULL, alors on peut continuer le programme

        while(actuel->suivant != NULL) //on teste tant que l'adresse du maillon suivant n'est pas nulle est donc qu'on est pas arrivee a la fin de la liste
        {
            if(actuel->x < 475)
            {
                actuel->cmptDeg++;
                if(actuel->cmptDeg >= actuel->tmpDeg)
                {
                    actuel->cmptDeg = 0;
                    degatInfli = degatInfli + actuel->degatsM;
                }
            }
            actuel = actuel->suivant;  //On avance dans la liste en passant à l'élément suivant
        }
    }
    *pvMur = *pvMur - degatInfli;
}





