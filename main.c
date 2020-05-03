#include "prototypes.h"
#include "Online/socket.h"

int main()
{
    lancerAllegro(1280, 1024);
    lancer_Reseau();
    BITMAP *fond=load_bitmap("image/menu/fondMenu.bmp",NULL);
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *image[37];
    t_classement tableau[20];
    char chaine[100];
    int sourisY = 355, y=0;
    chaine[0] = '\0';
    int compteur=0, sauvegarde, continuer = 1, tuto = 0, ecrire = 0, pos=0, clic=0;
    float x=0;
    chargementImageMenu(image);
    sauvegarde = recupererNiveauUnlock();
    int scene = 1;
    int score;
    int article = 0;
    connexionReseau(3, NULL, 0);
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
            NouvellePartie(buffer, image, &scene, &compteur, sauvegarde, &tuto,&ecrire, chaine, &pos, &clic, &score);
        }
        if(scene == 3)
        {
            ChargerUnePartie(buffer, image, &scene, &compteur, &sauvegarde, &score, chaine);
        }
        if(scene == 4)
        {
            leaderBoard(buffer, image, &scene, &compteur, tableau, &sourisY, &y);
        }
        if(scene == 5)
        {
            continuer = 0;
        }
        if(scene == 6)
        {
            envoieScoreServeur(buffer, image, &scene, &compteur, chaine, score);
        }
        if(scene == 7)
        {
            wiki(buffer, image, &scene, &compteur, &article);
        }
        textprintf_ex(buffer, font, 1190, 1010, makecol(255,255,255), -1, "online:%d", online);
        if(online >0)
        {
            circlefill(buffer, 1263, 1013, 5,makecol(0,255,0));
        }
        else
        {
            circlefill(buffer, 1263, 1013, 5,makecol(255,0,0));
        }
        blit(buffer, screen, 0,0,0,0,SCREEN_W, SCREEN_H);
    }
    connexionReseau(4, NULL, 0);
    destroy_bitmap(fond);
    destroy_bitmap(buffer);
    dechargementImage(image);
    allegro_exit();
    fermer_reseau();
    return 0;
}
END_OF_MAIN();


