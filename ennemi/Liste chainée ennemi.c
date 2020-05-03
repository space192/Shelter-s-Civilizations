#include "../prototypes.h"

void initAncre(t_listeMechant* horde)
{
    horde->premier = NULL;//(t_ennemi*)malloc(sizeof(t_ennemi));

    horde->nbElement = 0; //nb de mechant sur la map
    //horde->premier = creerEnnemis((rand()%2), 1, 1, horde->nbElement); //on ajoute un ennemi car il faut au minimum un ennemi
    horde->cmptG = 0;
    horde->tmpG = 50; //temps entre chaque generation d'ennemis
    horde->cmptV = 0;
    horde->tmpV = 800; //temsp entre les vagues
    horde->cmptDestruc = 0;
    horde->tmpDestruct = 3000;

    horde->listeActua = 0;

    horde->vagueM = 0;
    horde->nbFait = 0;
    horde->vagueFinis = 0; //on commence avec la vague qui n'est pas finis
}

void actualiserListeMechant(t_listeMechant* horde, int* niveau)  ///CARACTERISTIQUE DES MECHANTS EN FONCTION DU NIVEAU
{
    if(*niveau == 1)  //pour le niveau 1
    {
        horde->typeMechant[0] = 10 + horde->vagueM*2; //nombre de traceurs par vague
        horde->typeMechant[1] = 15 + horde->vagueM*2; //nombre de limace
        horde->typeMechant[2] = 10 + horde->vagueM*2; //nombre de mec vénère
        horde->typeMechant[3] = 0; //nombre de boss
        horde->typeMechant[4] = 0;

        horde->pvM[0] = 200; //point de vie des mechants
        horde->pvM[1] = 400;
        horde->pvM[2] = 200;
        horde->pvM[3] = 4000;
        horde->pvM[4] = 4000;

        horde->degatsM[0] = 10; //degat des mechants
        horde->degatsM[1] = 15;
        horde->degatsM[2] = 10;
        horde->degatsM[3] = 100;
        horde->degatsM[4] = 100;

        horde->tmpDegat[0] = 50; //vitesse t'attaque des mechants
        horde->tmpDegat[1] = 100;
        horde->tmpDegat[2] = 50;
        horde->tmpDegat[3] = 200;
        horde->tmpDegat[4] = 200;

        horde->tmpDep[0] = 4;
        horde->tmpDep[1] = 6;
        horde->tmpDep[2] = 4;
        horde->tmpDep[3] = 15;
        horde->tmpDep[4] = 15;

        horde->nbVague = 5;
    }
    else if(*niveau == 3)
    {
        horde->typeMechant[0] = 20 + horde->vagueM*2;
        horde->typeMechant[1] = 10 + horde->vagueM*2;
        horde->typeMechant[2] = 20 + horde->vagueM*2;
        horde->typeMechant[3] = 0; //nombre de boss
        horde->typeMechant[4] = 0;

        horde->pvM[0] = 400;
        horde->pvM[1] = 600;
        horde->pvM[2] = 400;
        horde->pvM[3] = 4000;
        horde->pvM[4] = 4000;

        horde->degatsM[0] = 10; //degat des mechants
        horde->degatsM[1] = 15;
        horde->degatsM[2] = 10;
        horde->degatsM[3] = 100;
        horde->degatsM[4] = 100;

        horde->tmpDegat[0] = 50; //vitesse t'attaque des mechants
        horde->tmpDegat[1] = 100;
        horde->tmpDegat[2] = 50;
        horde->tmpDegat[3] = 200;
        horde->tmpDegat[4] = 200;

        horde->tmpDep[0] = 4;
        horde->tmpDep[1] = 6;
        horde->tmpDep[2] = 4;
        horde->tmpDep[3] = 10;
        horde->tmpDep[4] = 10;

        horde->nbVague =5;
    }
    else if(*niveau == 5)
    {
        horde->typeMechant[0] = 20 + horde->vagueM*2;
        horde->typeMechant[1] = 10 + horde->vagueM*2;
        horde->typeMechant[2] = 25;
        horde->typeMechant[3] = (horde->vagueM%5)*horde->vagueM/5;
        horde->typeMechant[4] = (horde->vagueM%5)*horde->vagueM/5;

        horde->pvM[0] = 600;
        horde->pvM[1] = 800;
        horde->pvM[2] = 600;
        horde->pvM[3] = 4000;
        horde->pvM[4] = 4000;

        horde->degatsM[0] = 20; //degat des mechants
        horde->degatsM[1] = 30;
        horde->degatsM[2] = 20;
        horde->degatsM[3] = 100;
        horde->degatsM[4] = 100;

        horde->tmpDegat[0] = 50; //vitesse t'attaque des mechants
        horde->tmpDegat[1] = 100;
        horde->tmpDegat[2] = 50;
        horde->tmpDegat[3] = 200;
        horde->tmpDegat[4] = 200;

        horde->tmpDep[0] = 4;
        horde->tmpDep[1] = 6;
        horde->tmpDep[2] = 4;
        horde->tmpDep[3] = 10;
        horde->tmpDep[4] = 10;

        horde->nbVague = 5;
    }
    else if(*niveau == 7)
    {
        horde->typeMechant[0] = 10 + horde->vagueM*2; //nombre de petit mechant par vague
        horde->typeMechant[1] = 5 + horde->vagueM*2; //nombre de moyen mechant
        horde->typeMechant[2] = 10 + horde->vagueM*2;
        horde->typeMechant[3] = (horde->vagueM%5)*horde->vagueM/5;; //nombre de boss
        horde->typeMechant[4] = (horde->vagueM%5)*horde->vagueM/5;;

        horde->pvM[0] = 600 + horde->vagueM; //point de vie des mechants
        horde->pvM[1] = 1000 + horde->vagueM;
        horde->pvM[2] = 600 + horde->vagueM;
        horde->pvM[3] = 600 + horde->vagueM;
        horde->pvM[4] = 600 + horde->vagueM;

        horde->degatsM[0] = 20 + horde->vagueM; //degat des mechants
        horde->degatsM[1] = 30 + horde->vagueM;
        horde->degatsM[2] = 20 + horde->vagueM;
        horde->degatsM[2] = 100 + horde->vagueM;
        horde->degatsM[2] = 100 + horde->vagueM;

        horde->tmpDegat[0] = 50; //vitesse t'attaque des mechants
        horde->tmpDegat[1] = 100;
        horde->tmpDegat[2] = 50;
        horde->tmpDegat[2] = 200;
        horde->tmpDegat[2] = 200;

        horde->tmpDep[0] = 4;
        horde->tmpDep[1] = 6;
        horde->tmpDep[2] = 4;
        horde->tmpDep[3] = 10;
        horde->tmpDep[4] = 10;

        horde->nbVague = 1000000;
    }

//horde->vagueM = 0;
    horde->nbFait = 0;
    horde->nbAfaire = horde->typeMechant[0] + horde->typeMechant[1] + horde->typeMechant[2] + horde->typeMechant[3] + horde->typeMechant[4]; //nombre de mechant à faire
    horde->listeActua = 1; //la liste a ete actualise

}

int typeEnnemiGenerer(int nbMechant[5], int numVague, int *niveau)
{
    int alea = 0, generer = 0;


    while(generer == 0) //on sort un nombre du tableau avec le nombre de mechant
    {

        /*if((numVague%5 == 0) && ((*niveau)>5))
            alea = rand()%5;
        else*/
            alea = rand()%5;

        if(nbMechant[alea] > 0)
        {
            nbMechant[alea]--;
            generer = 1;
        }
    }

    return alea;
}

void ajouterPremierEnnemi(t_listeMechant* ancre, int nivMur, int numVague, int *niveau)
{
    t_ennemi* nouveau = (t_ennemi*)malloc(sizeof(t_ennemi)); //On déclare le nouveau maillon au quel on alloue dynamiquement un espace mémoire

    ancre->nbElement = 1;   //On incrémente la taille de la chaine

    if (ancre == NULL || nouveau == NULL) //on test que l'allocation dynamique a fonctionnée et que les donnees recues en parametre sont bonnes
    {
        printf("Donnee impossible à lire ou allocation dynamique non reussie dans le programme ajouterEnnemi");
        exit(EXIT_FAILURE);
    }
    ancre->premier = creerEnnemis(ancre, typeEnnemiGenerer(ancre->typeMechant, numVague, niveau), ancre->nbElement, nivMur);   //On remplie le nouveau maillon avec ces données /
    ancre->premier->suivant = NULL;
}

void ajouterEnnemi(t_listeMechant* ancre, int nivMur, int numVague, int *niveau)
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
    nouveau = creerEnnemis(ancre, typeEnnemiGenerer(ancre->typeMechant, numVague, niveau), ancre->nbElement, nivMur);   //On remplie le nouveau maillon avec ces données /

    while(actuel->suivant != NULL) //on teste tant que l'adresse du maillon suivant n'est pas nulle est donc qu'on est pas arrivee a la fin de la liste
        actuel = actuel->suivant;  //On avance dans la liste en passant à l'élément suivant

    nouveau->suivant = NULL;   //On donne comme adresse suivante à cet éléement NULL car c'est le dernier de la liste
    actuel->suivant = nouveau;   //L'ancien dernier element de la liste pointe maintenant sur le nouvel element suivant
}

void creer_horde(t_listeMechant* ancreH, int* niveau, int vit, int nivMur)
{
    if(ancreH->listeActua == 0)
        actualiserListeMechant(ancreH, niveau);

    if(ancreH->vagueFinis == 1) //si la vague est finie
    {
        //on compte pour attendre le debut de la prochaine vague
        ancreH->cmptV = ancreH->cmptV + vit;
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
                ancreH->cmptG = ancreH->cmptG + 1;
                if((ancreH->cmptG >= ancreH->tmpG)) //on incremente le compteur pour qu'il ajoute un ennemi a la horde à un certains interval de temps
                {
                    if(ancreH->nbElement <= 0)
                    {
                        ajouterPremierEnnemi(ancreH, nivMur, ancreH->vagueM, niveau);
                        ancreH->nbFait++;
                    }
                    else
                    {
                        ajouterEnnemi(ancreH, nivMur, ancreH->vagueM, niveau); //on ajoute un ennemi
                        ancreH->nbFait++;
                    }

                    ancreH->cmptG = 0; //on remet le compteur à 0
                }
            }
            else if((ancreH->nbFait == ancreH->nbAfaire) && (ancreH->nbElement <= 0)) //si on a fait tous les mechant et qu'il n'en reste plus sur la map, on indique que la vague est finie
            {
                ancreH->vagueFinis = 1;
                ancreH->vagueM++;

                if(ancreH->vagueM >= ancreH->nbVague)
                {
                    (*niveau)++;
                    ancreH->listeActua = 0;
                    ancreH->vagueM = 0;
                }
            }
        }
    }//fin else if vague pas finie
    //printf("vagueA : %d, nbVague : %d,  nbFait %d - %d a faire, nbElement :%d\n", ancreH->vagueM, ancreH->nbVague, ancreH->nbFait, ancreH->nbAfaire, ancreH->nbElement);
}

void posAlea(int* x, int* y, int nivMur, int type)
{
    int ptAppa = 0; //indice pour definir aleatoiremeent le point d'apparition du monstre
    int xMax = 0, xMin = 0; //varaible pour définir les zones d'apparaitions
    int yMax = 0, yMin = 0;


    if(type == 0)
    {
        switch(nivMur)
        {
        case 0 : //point d'apparition du haut
            yMin = 1580 + 35;
            yMax = 1925;
            break;
        case 1 : //point d'apparition du haut
            yMin = 1580 + 35;
            yMax = 2165;
            break;
        case 2 : //point d'apparition du haut
            yMin = 1340 + 35;
            yMax = 2165;
            break;
        }
        xMin = 3840;
        xMax = 3840;
    }
    else
    {
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
    }

    *x = (rand()%(xMax-xMin+1)) + xMin; //on donne une position aleatoire dans ces zones prédéfinies
    *y = (rand()%(yMax-yMin+1)) + yMin;
}

t_ennemi *creerEnnemis(t_listeMechant *ancre, int type, int nb, int nivMur)
{
    t_ennemi *nouveau = malloc(sizeof(t_ennemi));
    int x = 0, y = 0;

    posAlea(&x, &y, nivMur, type); //on recupere des coordonnees d'une zone d'apparition

    nouveau->depx = 0;
    nouveau->depy = 0;
    nouveau->tx = 30;
    nouveau->ty = 30;
    nouveau->x = x - nouveau->tx/2;
    nouveau->y = y - nouveau->ty/2;
    nouveau->type = type;
    nouveau->numero = nb;
    nouveau->centre = (nouveau->tx/2 + nouveau->ty/2);

    nouveau->cmptDepM = 0;
    nouveau->tmpDepM = ancre->tmpDep[type];



    nouveau->cmptImg = 0;

    if(type == 0)
        nouveau->tmpImg = 2;
    else if(type == 1)
        nouveau->tmpImg = 2;
    else if(type == 2)
        nouveau->tmpImg = 3;
    else if(type == 3)
        nouveau->tmpImg = 10;
    else if(type == 4)
        nouveau->tmpImg = 10;


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
            if(actuel->x <= 475)
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

    if(*pvMur <= 0)
        *pvMur = 0;
}





