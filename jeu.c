#include "prototypes.h"

void jeu(int sauvegarde, int tutoA, char *PseudoJoueur)
{
    int compteur = 0;
    int compteur2 = 0;
    int deplAffX = 0;
    int deplAffY = 1200;
    int agrandissement = 0;
    int conditionConstruction = 1;
    int conditionBase = 0;
    int typeDeBatiment = 0;
    int niveauBatiment = 0;
    int volumeMusique = 40;
    int xp;
    int yp;
    int pauseActive= 0;
    int numeroEDD=8;
    int PDVMuraille;
    int jeuActif=1;
    int niveauJeu = 1;
    int vitesseJeu = 1;
    int nivMuraille = 1;
    int score = 0;
    int i;

    float angleR= 0;
    float couleurR = 0;
    char listeMusique[6][100]={"son/musique/sentient.wav",
    "son/musique/first-light.wav",
    "son/musique/gathering-horizon.wav",
    "son/musique/solar-intervention.wav",
    "son/musique/the-oil-industry.wav",
    "son/musique/the-search-for-iron.wav"
    };
    char listeMusique2[6][100]={"sentient",
    "first-light.wav",
    "gathering-horizon",
    "solar-intervention",
    "the-oil-industry",
    "the-search-for-iron"
    };

    t_batimentP batimentP;
    batimentP.x=40;
    batimentP.y=1690;
    batimentP.imageX=0;
    batimentP.imageY=0;

    BITMAP* beacon[2];
    BITMAP *page;
    BITMAP* base[6];
    BITMAP* batiments[9];
    BITMAP *fond = load_bitmap("image/fond.bmp",NULL);
    BITMAP *construc = NULL;
    BITMAP *menuC = NULL;
    BITMAP *menuD = NULL;
    BITMAP *layoutMenu[3];

    BITMAP *miniMap = NULL;
    BITMAP *fondation =NULL;
    BITMAP *pause[4];
    BITMAP *IMGdefense[4];
    BITMAP *chemin=NULL;
    BITMAP *angle=NULL;

    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    IMGdefense[0] = load_bitmap("image/defense/1.bmp", NULL);
    IMGdefense[1] = load_bitmap("image/defense/2.bmp", NULL);
    IMGdefense[2] = load_bitmap("image/defense/3.bmp", NULL);
    IMGdefense[3] = load_bitmap("image/defense/bullet.bmp", NULL);

    angle = load_bitmap("image/ennemi/angle nouveau.bmp", NULL);
    chemin = load_bitmap("image/ennemi/chemin nouveau.bmp", NULL);
    BITMAP *place =create_bitmap(fond->w, fond->h);

    batiments[0]= load_bitmap("image/BR/OR1.bmp",NULL);
    batiments[1]= load_bitmap("image/BR/PI1.bmp",NULL);
    batiments[2]= load_bitmap("image/BR/ME1.bmp",NULL);
    batiments[3]= load_bitmap("image/BR/OR2.bmp",NULL);
    batiments[4]= load_bitmap("image/BR/PI2.bmp",NULL);
    batiments[5]= load_bitmap("image/BR/ME2.bmp",NULL);
    batiments[6]= load_bitmap("image/BR/OR3.bmp",NULL);
    batiments[7]= load_bitmap("image/BR/PI3.bmp",NULL);
    batiments[8]= load_bitmap("image/BR/ME3.bmp",NULL);
    base[0] = load_bitmap("image/base/base1.bmp",NULL);
    base[1] = load_bitmap("image/base/base2.bmp",NULL);
    base[2] = load_bitmap("image/base/base3.bmp",NULL);
    base[3] = load_bitmap("image/base/muraille1.bmp",NULL);
    base[4] = load_bitmap("image/base/muraille2.bmp",NULL);
    base[5] = load_bitmap("image/base/muraille3.bmp",NULL);

    construc = load_bitmap("image/menu jeu/construire.bmp",NULL);
    menuC = load_bitmap("image/menu jeu/menuC.bmp",NULL);
    menuD = load_bitmap("image/menu jeu/menuD.bmp",NULL);
    layoutMenu[0] = load_bitmap("image/menu jeu/layoutMenu.bmp",NULL);
    layoutMenu[1] = load_bitmap("image/menu jeu/layoutMenu2.bmp",NULL);
    layoutMenu[2] = load_bitmap("image/menu jeu/layoutJoueur.bmp",NULL);
    miniMap = load_bitmap("image/menu jeu/miniMap.bmp",NULL);
    fondation = load_bitmap("image/base/fondation.bmp",NULL);

    pause[0]= load_bitmap("image/menu jeu/Pause.bmp",NULL);
    pause[1]= load_bitmap("image/menu jeu/Play.bmp",NULL);
    pause[2]= load_bitmap("image/menu jeu/menuOptions.bmp",NULL);
    pause[3]= load_bitmap("image/menu jeu/menuPause.bmp",NULL);

    beacon[0]=load_bitmap("image/BR/beacon-base.bmp",NULL);
    beacon[1]=load_bitmap("image/BR/beacon-antenna.bmp",NULL);


    SAMPLE *selectSound = load_wav("son/select.wav");
    SAMPLE *newBSound =load_wav("son/put.wav");
    SAMPLE *buzzer = load_wav("son/buzzer.wav");
    SAMPLE *bullet = load_wav("son/tir.wav");

    int voiceB[4];
    voiceB[0]=allocate_voice(selectSound);
    voiceB[1]=allocate_voice(newBSound);
    voiceB[2]=allocate_voice(buzzer);
    voiceB[3]=allocate_voice(bullet);


    int voice;
    SAMPLE *sample1=load_wav(listeMusique[0]);
    voice = allocate_voice(sample1);

    SAMPLE *sample2 = NULL;

    voice_start(voice);
    voice_set_volume(voice,50);

    //destroy_sample(sample);

    int musiqueActive =0;
    int conditionMusique =0;


    BITMAP* SeqM[NB_SEQM];


    t_joueur joueur1;
    t_borne borne;
    t_listeBR *listeRessource = NULL;
    t_listedef *listedef = NULL;
    t_listeEDD *listeEmplacementDefense = NULL;
    t_listeMechant* horde = (t_listeMechant*)malloc(sizeof(t_listeMechant));
    if(sauvegarde == 0)
    {
        listeRessource = InitialisationBR(batiments);
        listeEmplacementDefense = InitialisationEDD();
        listedef = initialisationDef();
        joueur1.or=20000;
        joueur1.pierre=20000;
        joueur1.metal=20000;
        ajusterBase(&borne, agrandissement,&PDVMuraille);
    }
    else if(sauvegarde != 0)
    {
        short int temp = 0;
        listedef = malloc(sizeof(t_listedef));
        listedef->premier = NULL;
        recupererDefense(listedef, sauvegarde);
        listeEmplacementDefense = malloc(sizeof(t_listeEDD));
        listeEmplacementDefense->premier = NULL;
        listeRessource = malloc(sizeof(t_listeBR));
        listeRessource->premier = NULL;
        recupererBatimentProduction(listeRessource, sauvegarde);
        recupererEmplacementDispo(listeEmplacementDefense, sauvegarde);
        recupererAnecdote(&joueur1, &agrandissement, &score, &PDVMuraille);
        ajusterBase(&borne, agrandissement,&temp);
    }

    initSeqM(SeqM);
    initAncre(horde);
    while ((!key[KEY_ESC])&&(jeuActif==1))
    {


        clear_bitmap(page);
        clear_bitmap(place);

        creer_horde(horde, &niveauJeu, vitesseJeu);

        gererMusique(&conditionMusique,&musiqueActive,voice,listeMusique,sample1,sample2);
        afficherBase(page,fond,base,fondation,PDVMuraille,listeEmplacementDefense,agrandissement,deplAffX,deplAffY);
        afficherBatiment(listeRessource,page,batiments,beacon,&batimentP,&conditionBase,deplAffX,deplAffY);

        if(listedef->premier!=NULL)
        {
            gestion_test_look_shoot_kill(listedef, horde, page, IMGdefense,deplAffX,deplAffY,voiceB);
        }

        if(pauseActive==0)
        {
            //calcule des positions des ennemis
            calculerPosition(horde, chemin, place, angle, vitesseJeu, nivMuraille);
            gererDeplacement(&deplAffX,&deplAffY);
            incrementerTic(listeRessource,page,&angleR,&couleurR,deplAffX,deplAffY);
        }
       //affichage des ennemis
        dessinerMechant(horde, page, deplAffX, deplAffY, SeqM);

        afficherLayoutMenu(page,layoutMenu,miniMap,borne,PseudoJoueur,score,niveauJeu,deplAffX,deplAffY,joueur1,horde,listedef,PDVMuraille,agrandissement);
        testRecolter(listeRessource,&joueur1, &compteur,deplAffX, deplAffY);
        construireNouveauBatiment(listeRessource,listedef,listeEmplacementDefense,page,menuC,construc,&conditionConstruction, &compteur2, &typeDeBatiment,&niveauBatiment,&agrandissement,&joueur1,deplAffX, deplAffY,&borne,&PDVMuraille,voiceB);
        ajouterFondation(page,construc,listeEmplacementDefense,&conditionConstruction,listeRessource,&xp,&yp,&compteur2,&niveauBatiment,&borne,deplAffX,deplAffY,&numeroEDD,&joueur1,voiceB);
        ajouterDefense(page,menuD,&joueur1,listeEmplacementDefense,listedef,&conditionConstruction,&typeDeBatiment,&compteur2,deplAffX,deplAffY,voiceB);

        attaquerMur(horde, &PDVMuraille);

        tutoriel(page,&tutoA,angleR,listeRessource,joueur1,listeEmplacementDefense,listedef);
        gererPause(page,&pauseActive,pause,&volumeMusique,&musiqueActive,voice,listeMusique2,&jeuActif);

        supprimerEnnemi(horde,&score);

        //bouton test vitesse
        if(mouse_b&1 && (mouse_x>60 - 25) && (mouse_x <60 + 25) && (mouse_y>60 - 25) && (mouse_y <60 + 25) && (vitesseJeu == 1))
            vitesseJeu = 2;
        else if (mouse_b&1 && (mouse_x>60 - 25) && (mouse_x <60 + 25) && (mouse_y>60 - 25) && (mouse_y <60 + 25) && (vitesseJeu == 2))
            vitesseJeu = 1;

        if(vitesseJeu == 1)
            circlefill(page, 60, 60, 25, makecol(0, 255, 0));
        else if(vitesseJeu == 2)
            circlefill(page, 60, 60, 25, makecol(255, 0, 0));


        if(key[KEY_U])
            blit(place, page, deplAffX, deplAffY, 0, 0, SCREEN_W, SCREEN_H);      //TEST POUR VOIR LES BITMAP CACHEES
        if(key[KEY_I])
            blit(chemin, page, deplAffX, deplAffY, 0, 0, SCREEN_W, SCREEN_H);
        if(key[KEY_O])
            blit(angle, page, deplAffX, deplAffY, 0, 0, SCREEN_W, SCREEN_H);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    voice_stop(voice);
    release_voice(voice);
    destroy_sample(sample1);
    destroy_sample(sample2);

    for(i=0;i<4;i++)
    {
        release_voice(voiceB[i]);
    }



    sauvegarderNiveauUnlock(sauvegarde);
    //if(sauvegarde!=0)
    //{
        SauvegarderBatimentProduction(listeRessource, 4);
        SauvegarderEmplacementDisponible(listeEmplacementDefense, 4);
        SauvegarderDefense(listedef, 4);
        sauvegardeAnecdote(joueur1, agrandissement, score, PDVMuraille);
    //}
    libereBitmap(page,base,batiments,fond,construc,menuC,menuD,layoutMenu,miniMap,fondation,pause,IMGdefense,chemin,angle,place, SeqM,beacon);
    libererSon(selectSound,newBSound,buzzer,bullet);
    detruireListe(listeRessource,listedef,listeEmplacementDefense,horde);
}
