#include "prototypes.h"

int main()
{
    lancerAllegro(1280, 1024);
    FONT *police = load_ttf_font("Police/minecraft.ttf", 11, ALLEGTTF_NOSMOOTH);
    if(police == NULL)
    {
        allegro_message("erreur lors du chargement de la police");
        exit(EXIT_FAILURE);
    }
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *image[12];
    char chaine[100];
    chaine[0] = '\0';
    int compteur=0, sauvegarde = 1, continuer = 1, tuto = 1, ecrire = 0, pos=0;
    chargementImageMenu(image);
    int scene = 1; //valeur scene corresponde au different ecran du menu
                   //1:Menu Principale
                   //2:Nouvelle Partie
                   //3:Chargement Partie
                   //4:Score en ligne

    while(!key[KEY_ESC] && continuer == 1)
    {
        clear_bitmap(buffer);
        //affichage d'une animation derriere le menu gerer par un spg ici
        if(scene == 1)
        {
            MenuPrincipale(buffer, image, &scene, &compteur, sauvegarde);
        }
        if(scene == 2)
        {
            NouvellePartie(buffer, image, &scene, &compteur, sauvegarde, &tuto,&ecrire, chaine, &pos, police);
        }
        if(scene == 3)
        {
            ChargerUnePartie(buffer, image, &scene, &compteur, &sauvegarde);
        }
        if(scene == 5)
        {
            continuer = 0;
        }
        //textprintf_ex(buffer, font, 10, 10, makecol(255,255,255), -1, "x:%d et y:%d", mouse_x, mouse_y);
        blit(buffer, screen, 0,0,0,0,SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(buffer);
    dechargementImage(image);
    allegro_exit();
    return 0;
}
END_OF_MAIN();


