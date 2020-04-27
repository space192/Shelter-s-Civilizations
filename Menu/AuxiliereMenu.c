#include "../prototypes.h"

void chargementImageMenu(BITMAP *image[12])
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
    for(i =0; i <  12; i++)
    {
        if(image[i] == NULL)
        {
            allegro_message("erreur chargement image %d", i);
        }
    }
}

void dechargementImage(BITMAP *image[12])
{
    int i;
    for(i=0; i < 12; i++)
    {
        destroy_bitmap(image[i]);
    }
}


void toucheClavier(char chaine[100], BITMAP *buffer, int *pos)
{
    int touche;
    char ASCII, code;
    //BITMAP *temp = create_bitmap(435, 17);
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
    textout_ex(buffer, font, chaine, 416, 462, makecol(255,255,255), -1);
    //stretch_blit(temp, buffer, 0,0,temp->w,temp->h, 416, 462, temp->w, temp->h*2);
    //destroy_bitmap(temp);
}
