#include "../prototypes.h"

void chargementImageMenu(BITMAP *image[19])
{
    int i;
    image[0] = load_bitmap("image/menu/nouvelle partie.bmp", NULL);
    image[1] = load_bitmap("image/menu/charger une partie.bmp", NULL);
    image[2] = load_bitmap("image/menu/Score en ligne.bmp", NULL);
    image[3] = load_bitmap("image/menu/Quitter.bmp", NULL);
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
    for(i =0; i <  18; i++)
    {
        if(image[i] == NULL)
        {
            allegro_message("erreur chargement image %d", i);
            exit(EXIT_FAILURE);
        }
    }
}

void dechargementImage(BITMAP *image[18])
{
    int i;
    for(i=0; i < 18; i++)
    {
        destroy_bitmap(image[i]);
    }
}


void toucheClavier(char chaine[100], BITMAP *buffer, int *pos, int *clic)
{
    int touche;
    char ASCII, code;
    if(keypressed())
    {
        touche = readkey();
        ASCII = touche & 0xff;
        code = touche >> 8;
        if(ASCII >=32 && ASCII <= 126)
        {
            if(*pos < 100)
            {
                chaine[*pos] = ASCII;
                (*pos)++;
                chaine[*pos] = '\0';
            }
        }
        else if(code == KEY_BACKSPACE)
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
        vline(buffer,420 + *pos *8, 473, 483, makecol(255,255,255));
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
