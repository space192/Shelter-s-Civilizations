#include "prototypes.h"

int main()
{
    lancerAllegro(1280, 1024);
    BITMAP *fond=load_bitmap("image/menu/fondMenu.bmp",NULL);
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *image[16];
    t_classement tableau[20];
    char chaine[100];
    int sourisY = 355, y=350;
    chaine[0] = '\0';
    int compteur=0, sauvegarde = 1, continuer = 1, tuto = 0, ecrire = 0, pos=0, clic=0, sauvegardetemp = 4;
    float x=0;
    chargementImageMenu(image);
    int scene = 1; //valeur scene corresponde au different ecran du menu
    //1:Menu Principale
    //2:Nouvelle Partie
    //3:Chargement Partie
    //4:Score en ligne

    while(!key[KEY_ESC] && continuer == 1)
    {
        clear_bitmap(buffer);
        blit(fond,buffer,x,0,0,0,SCREEN_W, SCREEN_H);
        x+=0.4;
        if(x>3071)
        {
            blit(fond,buffer,x-4351,0,0,0,SCREEN_W, SCREEN_H);
        }
        if(x>=4351)
        {
            x=0;
        }
        if(scene == 1)
        {
            MenuPrincipale(buffer, image, &scene, &compteur, sauvegarde);
        }
        if(scene == 2)
        {
            NouvellePartie(buffer, image, &scene, &compteur, sauvegarde, &tuto,&ecrire, chaine, &pos, &clic);
        }
        if(scene == 3)
        {
            ChargerUnePartie(buffer, image, &scene, &compteur, &sauvegardetemp);
        }
        if(scene == 4)
        {
            leaderBoard(buffer, image, &scene, &compteur, tableau, &sourisY, &y);
        }
        if(scene == 5)
        {
            continuer = 0;
        }
        blit(buffer, screen, 0,0,0,0,SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(fond);
    destroy_bitmap(buffer);
    dechargementImage(image);
    allegro_exit();
    return 0;
}
END_OF_MAIN();


