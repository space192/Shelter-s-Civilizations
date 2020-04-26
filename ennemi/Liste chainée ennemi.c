#include "../prototypes.h"

void initAncre(t_listeMechant* horde)
{
    horde->premier = (t_ennemi*)malloc(sizeof(t_ennemi));

    horde->nbElement = 1;
    horde->premier = creerEnnemis((rand()%2), 1, 1, horde->nbElement); //on ajoute un ennemi car il faut au minimum un ennemi
    horde->premier->suivant = NULL;
    horde->cmpt = 0;
    horde->tmp = 20;
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
    nouveau = creerEnnemis((rand()%2), 1, 1, ancre->nbElement);   //On remplie le nouveau maillon avec ces données /

    while(actuel->suivant != NULL) //on teste tant que l'adresse du maillon suivant n'est pas nulle est donc qu'on est pas arrivee a la fin de la liste
        actuel = actuel->suivant;  //On avance dans la liste en passant à l'élément suivant

    nouveau->suivant = NULL;   //On donne comme adresse suivante à cet éléement NULL car c'est le dernier de la liste
    actuel->suivant = nouveau;   //L'ancien dernier element de la liste pointe maintenant sur le nouvel element suivant
}

void creer_horde(t_listeMechant* ancreH, int nbMechant)
{
    if(ancreH->nbElement < nbMechant) //tant que la horde contient moins d'ennemis que demandé on en ajoute
    {
        ancreH->cmpt++;
        if((ancreH->cmpt == ancreH->tmp)) //on incremente le compteur pour qu'il ajoute un ennemi a la horde à un certains interval de temps
        {
            ajouterEnnemi(ancreH); //on ajoute un ennemi
            ancreH->cmpt = 0; //on remet le compteur à 0
        }
    }
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

t_ennemi *creerEnnemis(int type, int tmpDx, int tmpDy, int nb)
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

    nouveau->cmptDx = 0;
    nouveau->cmptDy = 0;
    nouveau->tmpDx = tmpDx;
    nouveau->tmpDy = tmpDy;

    nouveau->cmptImg = 0;
    nouveau->tmpImg = 5;
    nouveau->imgA = 0;
    nouveau->angle = 2;

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
