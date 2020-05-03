#include "../prototypes.h"

void chargementImageMenu(BITMAP *image[37])
{
    int i;
    image[0] = load_bitmap("image/menu/nouvelle partie.bmp", NULL);
    image[1] = load_bitmap("image/menu/charger une partie.bmp", NULL);
    image[2] = load_bitmap("image/menu/Score en ligne.bmp", NULL);
    image[3] = load_bitmap("image/menu/Quitter.bmp", NULL);                                      //chargement des images du menu
    image[4] = load_bitmap("image/menu/Niveau 1.bmp", NULL);
    image[5] = load_bitmap("image/menu/Niveau 2.bmp", NULL);
    image[6] = load_bitmap("image/menu/Niveau 3.bmp", NULL);
    image[7] = load_bitmap("image/menu/Endless mode.bmp", NULL);
    image[8] = load_bitmap("image/menu/petit jouer.bmp", NULL);
    image[9] = load_bitmap("image/menu/petit retour.bmp", NULL);
    image[10] = load_bitmap("image/menu/avant partie.bmp", NULL);
    image[11] = load_bitmap("image/menu/checkbox.bmp", NULL);
    image[12] = load_bitmap("image/menu/retour.bmp", NULL);
    image[13] = load_bitmap("image/reseau/affichage score.bmp", NULL);
    image[14] = load_bitmap("image/reseau/barre Score.bmp", NULL);
    image[15] = load_bitmap("image/reseau/slider1.bmp", NULL);
    image[16] = load_bitmap("image/menu/Submit score.bmp", NULL);
    image[17] = load_bitmap("image/menu/oui.bmp", NULL);
    image[18] = load_bitmap("image/menu/non.bmp", NULL);
    image[19] = load_bitmap("image/menu/Wiki.bmp", NULL);
    image[20] = load_bitmap("image/menu/wiki/wikiview.bmp", NULL);
    image[21] = load_bitmap("image/menu/wiki/wiki.bmp", NULL);
    image[22] = load_bitmap("image/menu/wiki/bouton.bmp", NULL);
    image[23] = load_bitmap("image/menu/wiki/Menu Gauche.bmp", NULL);
    image[24] = load_bitmap("image/menu/wiki/Mine d'or.bmp", NULL);
    image[25] = load_bitmap("image/menu/wiki/carriere.bmp", NULL);
    image[26] = load_bitmap("image/menu/wiki/Fonderie.bmp", NULL);
    image[27] = load_bitmap("image/menu/wiki/Bertha.bmp", NULL);
    image[28] = load_bitmap("image/menu/wiki/Laserinator.bmp", NULL);
    image[29] = load_bitmap("image/menu/wiki/terminator.bmp", NULL);
    image[30] = load_bitmap("image/menu/wiki/Les Mines.bmp", NULL);
    image[31] = load_bitmap("image/menu/wiki/RadCafard.bmp", NULL);
    image[32] = load_bitmap("image/menu/wiki/infected centipede.bmp", NULL);
    image[33] = load_bitmap("image/menu/wiki/les Runners.bmp", NULL);
    image[34] = load_bitmap("image/menu/wiki/Hotel de Ville.bmp", NULL);
    image[35] = load_bitmap("image/menu/wiki/Base.bmp", NULL);
    image[36] = load_bitmap("image/menu/wiki/accueil.bmp", NULL);
    for(i =0; i <  24; i++)
    {
        if(image[i] == NULL)
        {
            allegro_message("erreur chargement image %d", i);
            exit(EXIT_FAILURE);
        }
    }
}

void dechargementImage(BITMAP *image[37])
{
    int i;
    for(i=0; i < 25; i++)
    {
        destroy_bitmap(image[i]);                                       //dechargement des images du jeu
    }
}


void toucheClavier(char chaine[100], BITMAP *buffer, int *pos, int *clic)
{
    int touche;
    char ASCII, code;
    if(keypressed())                        //detection touche clavier enfoncé
    {
        touche = readkey();                 //lecture de la valeur de la touche
        ASCII = touche & 0xff;
        code = touche >> 8;
        if(ASCII >=32 && ASCII <= 126)      //teste si touche du clavier
        {
            if(*pos < 100)                  //test pour taille chaine pour eviter depassement taille memoire
            {
                chaine[*pos] = ASCII;
                (*pos)++;
                chaine[*pos] = '\0';
            }
        }
        else if(code == KEY_BACKSPACE)      //gestion de la touche effacer
        {
            if(*pos > 0)
            {
                (*pos)--;
            }
            chaine[*pos] = '\0';
        }
    }
    textout_ex(buffer, font, chaine, 420, 474, makecol(255,255,255), -1);
    if(*clic < 400 && *clic > 200)
    {
        vline(buffer,420 + *pos *8, 473, 483, makecol(255,255,255));        //gestion du curseur
    }
    if(*clic < 400)
    {
        (*clic)++;
    }
    else
    {
        *clic = 0;
    }
}
