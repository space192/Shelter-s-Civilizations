#include "../prototypes.h"

double calcul_angle(t_defense defense, t_ennemi mechant) //calcul de l'angle entre le mechant et la defense
{
    double temp;
    temp = atan2(mechant.y+mechant.centre - defense.y, mechant.x+mechant.centre - defense.x) - atan2(-defense.radius, 0);
    if(temp < 0)
    {
        temp += 2*M_PI;
    }
    temp*=180/M_PI;
    temp = temp/1.40625;
    return temp;
}

int test(t_defense defense, t_ennemi mechant) //test si enement present dans le rayon d'action de la tourelle
{
    int verif;
    if((pow(mechant.x - defense.x, 2)+ pow(mechant.y - defense.y, 2) < pow(defense.radius, 2))|| (pow(mechant.x+mechant.tx-defense.x, 2)+pow(mechant.y-defense.y, 2) < pow(defense.radius, 2)) || (pow(mechant.x-defense.x,2)+pow(mechant.y+mechant.ty-defense.y,2) < pow(defense.radius, 2)) || (pow(mechant.x+mechant.tx - defense.x, 2)+pow(mechant.y+mechant.ty-defense.y, 2)<pow(defense.radius, 2)))
    {
        verif = 1;
    }
    else
    {
        verif = 0;
    }
    return verif;
}
int testBalle(t_defense defense, t_balle balle) //test si balle toujours dans la zone de portée de la tourelle
{
    int verif;
    if((pow(balle.x - defense.x, 2)+ pow(balle.y - defense.y, 2) < pow(defense.radius, 2))|| (pow(balle.x+balle.tx-defense.x, 2)+pow(balle.y-defense.y, 2) < pow(defense.radius, 2)) || (pow(balle.x-defense.x,2)+pow(balle.y+balle.ty-defense.y,2) < pow(defense.radius, 2)) || (pow(balle.x+balle.tx - defense.x, 2)+pow(balle.y+balle.ty-defense.y, 2)<pow(defense.radius, 2)))
    {
        verif = 1;
    }
    else
    {
        verif = 0;
    }
    return verif;
}

void verificationListe(t_listedef *listedef) //verification de tout les elements de la liste chainée pour eviter les problemes
{
    t_defense *actuelDef = listedef->premier;
    t_balle *actuelBalle = actuelDef->liste->premier;
    t_balle *precedentBalle = actuelDef->liste->premier;
    t_balle *temp = NULL;
    while(actuelDef != NULL)
    {
        while(actuelBalle != NULL)
        {
            if(testBalle(*actuelDef, *actuelBalle) == 0)
            {
                if(actuelBalle == actuelDef->liste->premier)
                {
                    temp = actuelDef->liste->premier;
                    actuelDef->liste->premier = actuelDef->liste->premier->suivant;
                    free(temp);
                    actuelBalle = actuelDef->liste->premier;
                }
                else
                {
                    temp = actuelBalle;
                    precedentBalle->suivant = actuelBalle->suivant;
                    free(temp);
                    actuelBalle = precedentBalle;
                }
            }
            else
            {
                precedentBalle = actuelBalle;
                actuelBalle = actuelBalle->suivant;
            }
        }
        actuelDef = actuelDef->suivant;
    }
    actuelDef = NULL;
    actuelBalle = NULL;
    precedentBalle =NULL;
    temp = NULL;
    free(actuelDef);
    free(actuelBalle);
    free(temp);
}

void viderBalle(t_listeBalle *liste) //vide les balles lorsqu'il n'y a pas d'ennemies dans la zone
{
    while(liste->premier != NULL)
    {
        t_balle *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void gestion_test_look_shoot_kill(t_listedef *listedef, t_listeMechant *listeMechant, BITMAP *buffer, BITMAP *image[4],int deplAffX, int deplAffY,int voice[4]) //fonction principale defense
{
    t_defense *actuelDef = listedef->premier;
    t_ennemi *actuelMec = listeMechant->premier;
    t_balle *precedentBalle = actuelDef->liste->premier;    //creation variable parcours
    t_balle *actuelBalle = actuelDef->liste->premier;
    t_balle *temp = NULL;
    while(actuelDef != NULL)
    {
        actuelDef->target = 2000000; //valeur target en attendant
        actuelDef->test = 0;         //chaque defense doit passer un test pour savoir si elle doit s'activer, on la met a 0 pour OFF par defaut
        actuelMec = listeMechant->premier;
        while(actuelMec != NULL)
        {
            if(test(*actuelDef, *actuelMec) == 1)
            {
                if(actuelMec->numero < actuelDef->target)
                {
                    actuelDef->target = actuelMec->numero;      //determiner quel enemmie attaqué en fonction du numéro de celui ci
                }
            }
            actuelMec = actuelMec->suivant;
        }
        if(actuelDef->target != 2000000)
        {
            actuelDef->test = 1;
            actuelMec = listeMechant->premier;              //si un ennemie present dans la zone, on retourne au mechant qui est le plus proche et donc a target en premier
            while(actuelMec->numero != actuelDef->target)
            {
                actuelMec = actuelMec->suivant;
            }
        }
        if(actuelDef->test == 1)
        {
            actuelDef->angle = calcul_angle(*actuelDef, *actuelMec); //calcul de l'angle de la defense avec le mechant
            if(actuelDef->valeurCanon >= actuelDef->cadenceMax)
            {
                ajoutBalle(actuelDef->liste);
                actuelDef->valeurCanon = 0;
                //play_sample(son, 15,128, 1000, 0);
                voice_start(voice[3]);
                voice_set_volume(voice[3],10);                      //test par rapport a la cadence de tir de la defense pour l'ajout d'une balle ainsi que de jouer le son de tirer
            }
            else
            {
                actuelDef->valeurCanon++;
            }

            if(actuelDef->liste->premier!=NULL)
            {
                actuelBalle = actuelDef->liste->premier;
                while(actuelBalle != NULL)
                {
                    if(actuelBalle->pass == 0)
                    {
                        actuelBalle->degat = actuelDef->degat; //allocation des nouveau parametre a chacune des balles
                        actuelBalle->angle = actuelDef->angle;
                        actuelBalle->x = actuelDef->x;
                        actuelBalle->y = actuelDef->y;
                        actuelBalle->pass = 1;
                        actuelBalle->dx = actuelMec->x-actuelDef->x;
                        actuelBalle->dy = actuelMec->y-actuelDef->y;
                    }
                    if(testBalle(*actuelDef, *actuelBalle) == 1)
                    {
                        actuelBalle->x += actuelBalle->dx/20;
                        actuelBalle->y += actuelBalle->dy/20;
                        rotate_sprite(buffer, image[3], actuelBalle->x-1-deplAffX, actuelBalle->y-25-deplAffY, itofix(actuelBalle->angle)); //rotation de la balle
                    }
                    precedentBalle = actuelBalle;
                    actuelBalle = actuelBalle->suivant;
                }
                actuelMec = listeMechant->premier;
                while(actuelMec != NULL)
                {
                    actuelBalle = actuelDef->liste->premier;
                    while(actuelBalle != NULL)
                    {
                        if((actuelBalle->x > actuelMec->x && actuelBalle->y > actuelMec->y)&& (actuelBalle->x < actuelMec->x + actuelMec->tx && actuelBalle->y < actuelMec->y + actuelMec->ty))
                        {
                            actuelMec->pvM -= actuelBalle->degat; //gestion des hits zone sur les mechants
                        }
                        actuelBalle = actuelBalle->suivant;
                    }
                    actuelMec = actuelMec->suivant;
                }
            }
        }
        else if(actuelDef->test == 0)
        {
            if(actuelDef->angle < 64)
            {
                actuelDef->angle = (int)actuelDef->angle+1; // si tourelle sur OFF se replace sur un angle 90°
            }
            else if (actuelDef->angle > 64)
            {
                actuelDef->angle = (int)actuelDef->angle-1;
            }
            viderBalle(actuelDef->liste); //vide les balles
        }
        animation(image, buffer, actuelDef,deplAffX,deplAffY); //affiche la tourelle
        actuelDef = actuelDef->suivant;
    }
    verificationListe(listedef);
    actuelBalle = NULL;
    actuelDef = NULL;           //on evite les memory leak ;)
    actuelMec = NULL;
    precedentBalle = NULL;
    temp = NULL;
    free(actuelBalle);
    free(actuelDef);
    free(actuelMec);
    free(precedentBalle);
    free(temp);
}

