#include "../prototypes.h"

double calcul_angle(t_defense defense, t_ennemi mechant)
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

int test(t_defense defense, t_ennemi mechant)
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
int testBalle(t_defense defense, t_balle balle)
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

void verificationListe(t_listedef *listedef)
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

void gestion_test_look_shoot_kill(t_listedef *listedef, t_listeMechant *listeMechant, BITMAP *buffer, BITMAP *image[4],int deplAffX, int deplAffY,int voice[4])
{
    t_defense *actuelDef = listedef->premier;
    t_ennemi *actuelMec = listeMechant->premier;
    t_balle *precedentBalle = actuelDef->liste->premier;
    t_balle *actuelBalle = actuelDef->liste->premier;
    t_balle *temp = NULL;
    while(actuelDef != NULL)
    {
        actuelDef->target = 1000;
        actuelDef->test = 0;
        actuelMec = listeMechant->premier;
        while(actuelMec != NULL)
        {
            if(test(*actuelDef, *actuelMec) == 1)
            {
                if(actuelMec->numero < actuelDef->target)
                {
                    actuelDef->target = actuelMec->numero;
                }
            }
            actuelMec = actuelMec->suivant;
        }
        if(actuelDef->target != 1000)
        {
            actuelDef->test = 1;
            actuelMec = listeMechant->premier;
            while(actuelMec->numero != actuelDef->target)
            {
                actuelMec = actuelMec->suivant;
            }
        }
        if(actuelDef->test == 1)
        {
            actuelDef->angle = calcul_angle(*actuelDef, *actuelMec);
            if(actuelDef->valeurCanon >= actuelDef->cadenceMax)
            {
                ajoutBalle(actuelDef->liste);
                actuelDef->valeurCanon = 0;
                //play_sample(son, 15,128, 1000, 0);
                voice_start(voice[3]);
                voice_set_volume(voice[3],10);
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
                        actuelBalle->degat = actuelDef->degat;
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
                        rotate_sprite(buffer, image[3], actuelBalle->x-1-deplAffX, actuelBalle->y-25-deplAffY, itofix(actuelBalle->angle));
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
                            actuelMec->pvM -= actuelBalle->degat;
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
                actuelDef->angle = (int)actuelDef->angle+1;
            }
            else if (actuelDef->angle > 64)
            {
                actuelDef->angle = (int)actuelDef->angle-1;
            }
        }
        //rotate_sprite(buffer, carre, actuelDef->x-25, actuelDef->y-25, itofix(actuelDef->angle));
        animation(image, buffer, actuelDef,deplAffX,deplAffY);
        actuelDef = actuelDef->suivant;
    }
    verificationListe(listedef);
    actuelBalle = NULL;
    actuelDef = NULL;
    actuelMec = NULL;
    precedentBalle = NULL;
    temp = NULL;
    free(actuelBalle);
    free(actuelDef);
    free(actuelMec);
    free(precedentBalle);
    free(temp);
}

