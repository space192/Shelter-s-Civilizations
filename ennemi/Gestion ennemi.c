#include "../prototypes.h"

void actualiserDeplacement(t_ennemi* mechantA, BITMAP* chemin)
{
    int couleur = 0, r, v, b, j, bc;
    int i = VITESSE;

    r = makecol(255,0,0);
    v = makecol(0,255,0);
    b = makecol(0,0,255);
    bc = makecol(0,255,255);
    j = makecol(255,255,0);

    couleur = getpixel(chemin, mechantA->x, mechantA->y);

    if(couleur == r) //le mechant se déplace horizontalement
    {
        mechantA->depx = -1 * i;
        mechantA->depy = 0 * i;
    }
    else if (couleur == v)//le mechant monte
    {
        mechantA->depx = -1 * i;
        mechantA->depy = -1 * i;
    }
    else if (couleur == b)//le mechant descend
    {
        mechantA->depx = -1 * i;
        mechantA->depy = 1 * i;
    }
    else if (couleur == j)//le mechant est dans le lac
    {
        mechantA->depx = -1 * i/2;
        mechantA->depy = 2 * i;
    }
    else if (couleur == bc)//le mechant déscend beaucoup
    {
        mechantA->depx = -1 * i;
        mechantA->depy = 2 * i;
    }
    else
    {
        mechantA->depx = 0 * i;
        mechantA->depy = 0 * i;
    }
}

void supprimerEnnemi(t_listeMechant *liste,int *score)
{
    t_ennemi *actuel = NULL;
    t_ennemi *precedent;

    if(liste->premier!=NULL)
    {
        actuel = liste->premier;

        int condition=0;
        if(actuel->pvM <=0)
        {
            liste->nbElement--;
            if(actuel->type == 0)
            {
                (*score)+=10;
            }
            else if(actuel->type == 1)
            {
                (*score)+=50;
            }
            else if(actuel->type == 2)
            {
                (*score)+=200;
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

                if(actuel->pvM<=0)
                {
                    liste->nbElement--;
                    if(actuel->type == 0)
                    {
                        (*score)+=10;
                    }
                    else if(actuel->type == 1)
                    {
                        (*score)+=50;
                    }
                    else if(actuel->type == 2)
                    {
                        (*score)+=200;
                    }
                    precedent->suivant=actuel->suivant;
                }
                actuel=actuel->suivant;
                precedent=precedent->suivant;
            }
        }
    }


    actuel = NULL;
    precedent = NULL;
    free(actuel);
    free(precedent);
}

int testFuturePlaceLibre(BITMAP* place, t_ennemi* elem) //le sous programme renvoie 1 si la place est libre, sinon 0
{
    int pixel = 0, libre = 1;

    //test la couleur du pixel à la future position du mechant
    pixel = getpixel(place, elem->x + elem->depx, elem->y + elem->depy);

    if(pixel == makecol(255, 255, 255))
        libre = 0;

    return libre;
}

int testPlaceLibre(BITMAP* place, int x, int y) //le sous programme renvoie 1 si la place est libre, sinon 0
{
    int pixel = 0, libre = 1;

    //test la couleur du pixel à la future position du mechant
    pixel = getpixel(place, x, y);

    if(pixel == makecol(255, 255, 255))
        libre = 0;

    return libre;
}

int testChemin(int x, int y) //test que les mechant ne sortent pas du chemin, tant qu'ils sont sur le chemin on renvoie 0, envoie 1 si ils sortent du chemin et 2 s'ils sont au bout
{
    int test = 0;

    if((x < 600) && ((y < 1630) || (y > 1870 - 30)))
        test = 1;
    if(x <= 445)
        test = 2;

    return test;
}

int espacementH(t_ennemi* elem, BITMAP* place, int *chemin) //espace horizontalement de 5 pixels les mechants et renvoie 1 s'ils sont bloqués
{
    int i = 0, libre = 1, bloquer = 0;

    while((i<ESP_X + 1)&&(libre == 1)&&(*chemin == 0)) //on regarde si les pixels devant le mechant sont libres pour savoir s'il peut avancer
    {
        i++;
        libre = testPlaceLibre(place, elem->x - i, elem->y);
        *chemin = testChemin(elem->x - i, elem->y); //on verifie qu'il reste sur le chemin
    }

    if(i == ESP_X + 1)//on a largement la place pour avancer et on avance
        elem->depx = -1;
    else if((i == ESP_X)&&(libre == 0))//on a 5 case d'espacement donc on n'avance plus
    {
        elem->depx = 0;
        bloquer = 1;//on est bloquer et le booleen bloquer passe à 1
    }
    else if(i<ESP_X) //s'il n'y a pas la place d'avancer alors on recule pour garder l'espacement nécessaire
        elem->depx = 1;

    if((i == ESP_X)  &&  (*chemin == 2)) //on est au bord de la zone et on n'avance plus
        elem->depx = 0;

    return bloquer;
}

int testUtile(BITMAP* place, int x, int y) //fonction qui teste si c'est utile d'avancer, renvoie 1 si oui, 0 si non
{
    int test = 0;

    if(testPlaceLibre(place, x, y))
        test = 1;

    return test;
}

void espacementV(t_ennemi* elem, BITMAP* place)
{
    int libreH = 0, libreB = 0; //booleen pour savoir si la place au dessus en dessous du mechant est libre
    int cheminH = 0, cheminB = 0; //booleen pour savoir si la place au dessus ou en dessous est dnas le chemin

    libreH = testPlaceLibre(place, elem->x, elem->y - ESP_Y);
    libreB = testPlaceLibre(place, elem->x, elem->y + ESP_Y);

    cheminH = testChemin(elem->x, elem->y - ESP_Y);
    cheminB = testChemin(elem->x, elem->y + ESP_Y);

    if((libreH == 1)  && (cheminH == 0) && (testUtile(place, elem->x - ESP_X, elem->y - ESP_Y) == 1))
    {
        elem->depy = - ESP_Y;
        elem->angle = 3;
    }
    else if((libreB == 1) && (cheminB == 0) && (testUtile(place, elem->x - ESP_X, elem->y + ESP_Y) == 1))
    {
        elem->depy = ESP_Y;
        elem->angle = 0;
    }
}

void etalementMur(t_ennemi* elemA, BITMAP* place, int nivMur)
{
        //shit
}

void etalement(t_ennemi* elem, BITMAP* place, int nivMur)
{
    int bloquer = 0, chemin = 0; //chemin est un booleen qui est à 0 tant que les mechants sont sur le chemin, 1 s'ils en sortent et 2 s'ils sont au bout

    bloquer = espacementH(elem, place, &chemin);

    //printf("bloquer : %d, chemin : %d\n", bloquer, chemin);

    if((bloquer == 1)) //si les ennemis ne peuvent plus avancer mais pas au bout du chemin
        espacementV(elem, place);
}

void replacementY(t_ennemi *elem)
{
    int i = 0;

    for(i = -ESP_Y/2;  i< ESP_Y/2; i++)
    {
        if((elem->y + i) % ESP_Y == 0)
            elem->y = elem->y + i;
    }
}

void calculeAngle(t_ennemi *mechant, BITMAP* angle)
{
    int couleur = 0, r, v, b, j, bc;

    r = makecol(255,0,0);
    v = makecol(0,255,0);
    b = makecol(0,0,255);
    bc = makecol(0,255,255);
    j = makecol(255,255,0);

    couleur = getpixel(angle, mechant->x, mechant->y);

    if(couleur == r) //le mechant se déplace horizontalement
        mechant->angle = 2;
    else if (couleur == v)//le mechant monte
        mechant->angle = 3;
    else if (couleur == b)//le mechant descend
        mechant->angle = 0;
    else if (couleur == j)//le mechant est dans le lac
        mechant->angle = 2;
    else if (couleur == bc)//le mechant descend beaucoup
        mechant->angle = 1;
    else
        mechant->angle = mechant->angle;
}

void calculerPosition(t_listeMechant* ancreH, BITMAP* chemin, BITMAP* place, BITMAP* angle, int vitesse, int nivMur)
{
    t_ennemi* elemA = NULL; //element actuel permettant de parcourir la liste
    elemA = ancreH->premier;

    while(elemA != NULL) //parcours de la horde d'ennemis
    {

        elemA->cmptDx = elemA->cmptDx + vitesse;
        elemA->cmptDy = elemA->cmptDy + vitesse;

        actualiserDeplacement(elemA, chemin);
        calculeAngle(elemA, angle);

        if(elemA->x <= 800) //si on arrive dans la zone devant le mur où les mechant s'etalent, on les distances de 5 pixels en verticale
            replacementY(elemA);

        if(elemA->x < 800)
            etalement(elemA, place, nivMur);

        if(elemA->cmptDx >= elemA->tmpDx/vitesse) //test le compteur pour savoir si on peut deplacer l'ennemi
        {
            if(testFuturePlaceLibre(place, elemA) == 1)
                elemA->x = elemA->x + elemA->depx;
            elemA->cmptDx = 0;
        }

        if(elemA->cmptDy >= elemA->tmpDy/vitesse)
        {
            if(testFuturePlaceLibre(place, elemA) == 1)
                elemA->y = elemA->y + elemA->depy;
            elemA->cmptDy = 0;
        }
        putpixel(place, elemA->x, elemA->y, makecol(255,255,255));
        elemA = elemA->suivant;
    }
    elemA = NULL;
    free(elemA);
}
