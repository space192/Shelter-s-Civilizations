#include "../prototypes.h"


void lancerAllegro(int largeur, int hauteur)
{
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, largeur, hauteur, 0,0)!=0 || install_sound(DIGI_AUTODETECT,MIDI_NONE, 0) !=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}

t_listeBR *InitialisationBR(BITMAP* batiments[3])
{
    t_listeBR *liste=malloc(sizeof(t_listeBR));
    t_maillonBR *maillon =(t_maillonBR*) malloc(sizeof(t_maillonBR));
    t_maillonBR *maillon2 =(t_maillonBR*) malloc(sizeof(t_maillonBR));
    t_maillonBR *maillon3 =(t_maillonBR*) malloc(sizeof(t_maillonBR));
    t_maillonBR *maillon4 =(t_maillonBR*) malloc(sizeof(t_maillonBR));
    t_maillonBR *maillon5 =(t_maillonBR*) malloc(sizeof(t_maillonBR));
    t_maillonBR *maillon6 =(t_maillonBR*) malloc(sizeof(t_maillonBR));
    t_maillonBR *maillon7 =(t_maillonBR*) malloc(sizeof(t_maillonBR));

    if(liste == NULL||maillon==NULL||maillon3==NULL||maillon2==NULL)
    {
        printf("erreur d'allocation dynamique 1\n");
        exit(EXIT_FAILURE);
    }

    maillon->x = 40;
    maillon->y = 1630;
    maillon2->x = 100;
    maillon2->y = 1630;
    maillon3->x = 160;
    maillon3->y = 1630;
    maillon4->x = 40;
    maillon4->y = 1690;
    maillon5->x = 40;
    maillon5->y = 1750;
    maillon6->x = 100;
    maillon6->y = 1690;
    maillon7->x = 100;
    maillon7->y = 1750;

    maillon->tic = 0;
    maillon2->tic = 0;
    maillon3->tic = 0;

    maillon->type = 1;
    maillon2->type = 2;
    maillon3->type = 3;
    maillon4->type = 4;
    maillon5->type = 4;
    maillon6->type = 4;
    maillon7->type = 4;

    maillon->ticMax = 2000;
    maillon2->ticMax = 3000;
    maillon3->ticMax = 4000;

    maillon->niveau = 0;
    maillon2->niveau = 0;
    maillon3->niveau = 0;
    maillon4->niveau = 0;
    maillon5->niveau = 0;
    maillon6->niveau = 0;
    maillon7->niveau = 0;

    maillon7->suivant = NULL;
    maillon6->suivant=maillon7;
    maillon5->suivant=maillon6;
    maillon4->suivant = maillon5;
    maillon3->suivant = maillon4;
    maillon2->suivant = maillon3;
    maillon->suivant = maillon2;
    liste->premier = maillon;

    return liste;
}

t_listeEDD *InitialisationEDD()
{
    int x=480;
    int y=1630;
    t_listeEDD *liste=malloc(sizeof(t_listeEDD));
    t_maillonEDD *maillon=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon2=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon3=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon4=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon5=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon6=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon7=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));
    t_maillonEDD *maillon8=(t_maillonEDD*) malloc(sizeof(t_maillonEDD));


    if(liste == NULL||maillon==NULL||maillon3==NULL||maillon2==NULL||maillon4==NULL||maillon5==NULL||maillon6==NULL||maillon7==NULL||maillon8==NULL)
    {
        printf("erreur d'allocation dynamique 2\n");
        exit(EXIT_FAILURE);
    }

    maillon->x=x;
    maillon->y=y;
    maillon->afficherFondation=1;
    maillon->emplacementDisponible=0;

    maillon2->x=x+60;
    maillon2->y=y;
    maillon2->afficherFondation=0;
    maillon2->emplacementDisponible=0;

    maillon3->x=x;
    maillon3->y=y+60;
    maillon3->afficherFondation=0;
    maillon3->emplacementDisponible=0;

    maillon4->x=x+60;
    maillon4->y=y+60;
    maillon4->afficherFondation=0;
    maillon4->emplacementDisponible=0;

    maillon5->x=x;
    maillon5->y=y+120;
    maillon5->afficherFondation=1;
    maillon5->emplacementDisponible=0;

    maillon6->x=x+60;
    maillon6->y=y+120;
    maillon6->afficherFondation=0;
    maillon6->emplacementDisponible=0;

    maillon7->x=x;
    maillon7->y=y+180;
    maillon7->afficherFondation=0;
    maillon7->emplacementDisponible=0;

    maillon8->x=x+60;
    maillon8->y=y+180;
    maillon8->afficherFondation=0;
    maillon8->emplacementDisponible=0;

    maillon->numeroEDD=1;
    maillon2->numeroEDD=2;
    maillon3->numeroEDD=3;
    maillon4->numeroEDD=4;
    maillon5->numeroEDD=5;
    maillon6->numeroEDD=6;
    maillon7->numeroEDD=7;
    maillon8->numeroEDD=8;

    maillon8->suivant=NULL;
    maillon7->suivant=maillon8;
    maillon6->suivant=maillon7;
    maillon5->suivant=maillon6;
    maillon4->suivant=maillon5;
    maillon3->suivant=maillon4;
    maillon2->suivant=maillon3;
    maillon->suivant=maillon2;
    liste->premier=maillon;

    return liste;

}

 void libereBitmap(BITMAP *page,BITMAP *transisition[3],BITMAP *base[3],BITMAP *batiments[9],BITMAP *fond,BITMAP *construc,BITMAP *menuC,BITMAP *menuD,BITMAP *layoutMenu[3],BITMAP *miniMap,BITMAP *fondation,BITMAP *pause[4],BITMAP *IMGdefense[4],BITMAP* chemin,BITMAP* angle,BITMAP* place, BITMAP *SeqM[],BITMAP* beacon[2])
 {
    int i;

    destroy_bitmap(page);
    destroy_bitmap(fond);
    destroy_bitmap(construc);
    destroy_bitmap(menuC);
    destroy_bitmap(menuD);
    destroy_bitmap(miniMap);
    destroy_bitmap(fondation);
    destroy_bitmap(chemin);
    destroy_bitmap(angle);
    destroy_bitmap(place);

    for(i=0;i<4;i++)
    {
        destroy_bitmap(pause[i]);
        destroy_bitmap(IMGdefense[i]);
    }

    for(i=0;i<3;i++)
    {
        destroy_bitmap(base[i]);
        destroy_bitmap(layoutMenu[i]);
        destroy_bitmap(transisition[i]);
    }
    for(i=0;i<9;i++)
    {
        destroy_bitmap(batiments[i]);
    }
    for(i=0; i < NB_SEQM ; i++)
    {
        destroy_bitmap(SeqM[i]);
    }
    for(i=0; i < 2; i++)
    {
        destroy_bitmap(beacon[i]);
    }
}

void libererSon(SAMPLE *selectSound,SAMPLE *newBSound,SAMPLE *buzzer,SAMPLE *bullet)
{
    /*destroy_sample(musique1);
    destroy_sample(musique2);
    destroy_sample(musique3);
    destroy_sample(musique4);
    destroy_sample(musique5);
    destroy_sample(musique6);*/
    destroy_sample(selectSound);
    destroy_sample(newBSound);
    destroy_sample(buzzer);
    destroy_sample(bullet);

    if((selectSound==NULL)&&(newBSound==NULL)&&(buzzer==NULL)&&(bullet==NULL))
    {
        printf("ca a marche");
    }
}

void detruireListe(t_listeBR *liste1,t_listedef *liste2, t_listeEDD *liste3,t_listeMine *listeMine,t_listeMechant* liste4)
{
    while(listeMine->premier !=NULL)
    {
        t_maillonMine *supr =listeMine->premier;
        listeMine->premier = listeMine->premier->suivant;
        free(supr);
    }



    while(liste1->premier != NULL)
    {
        t_maillonBR *aSupprimer = liste1->premier;
        liste1->premier = liste1->premier->suivant;
        free(aSupprimer);
    }

    while(liste3->premier != NULL)
    {
        t_maillonEDD *aSupprimer2 = liste3->premier;
        liste3->premier = liste3->premier->suivant;
        free(aSupprimer2);
    }

    while(liste4->premier != NULL)
    {
        t_ennemi *aSupprimer5 = liste4->premier;
        liste4->premier = liste4->premier->suivant;
        free(aSupprimer5);
    }

    while(liste2->premier != NULL)
    {
        while(liste2->premier->liste->premier != NULL)
        {
            t_balle *aSupprimer3 = liste2->premier->liste->premier;
            liste2->premier->liste->premier = liste2->premier->liste->premier->suivant;
            free(aSupprimer3);

        }
        free(liste2->premier->liste);
        t_defense *aSupprimer4 = liste2->premier;
        liste2->premier = liste2->premier->suivant;
        free(aSupprimer4);
    }
}
