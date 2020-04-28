#include "prototypes.h"

void jeu(int sauvegarde)
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
    int tutoA=1;


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
    BITMAP *layoutMenu = NULL;
    BITMAP *layoutMenu2 = NULL;
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

    angle = load_bitmap("image/ennemi/angle mechant.bmp", NULL);
    chemin = load_bitmap("image/ennemi/chemin ennemi.bmp", NULL);
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
    layoutMenu = load_bitmap("image/menu jeu/layoutMenu.bmp",NULL);
    layoutMenu2 = load_bitmap("image/menu jeu/layoutMenu2.bmp",NULL);
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
    SAMPLE *bullet;

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


    bullet = load_wav("son/tir.wav");
    t_joueur joueur1;
    t_borne borne;
    t_listeBR *listeRessource = NULL;
    t_listedef *listedef = initialisationDef();
    t_listeEDD *listeEmplacementDefense= NULL;
    t_listeMechant* horde = (t_listeMechant*)malloc(sizeof(t_listeMechant));
    if(sauvegarde == 0)
    {
        listeRessource = InitialisationBR(batiments);
        listeEmplacementDefense = InitialisationEDD();
    }
    else
    {
        recupererBatimentProduction(listeRessource, sauvegarde);
        recupererEmplacementDispo(listeEmplacementDefense, sauvegarde);
        recupererDefense(listedef, sauvegarde);
        triEDD(listeEmplacementDefense);
    }

    if(sauvegarde != 0)
    {
        recupererDefense(listedef, sauvegarde);
    }
    initSeqM(SeqM);
    initAncre(horde);

    joueur1.or=200;
    joueur1.pierre=2000;
    joueur1.metal=200;
    ajusterBase(&borne, agrandissement,&PDVMuraille);
    while ((!key[KEY_ESC])&&(jeuActif==1))
    {


        clear_bitmap(page);
        clear_bitmap(place);

        //génétation des ennemis
        creer_horde(horde, NB_MECHANT);

        gererMusique(&conditionMusique,&musiqueActive,voice,listeMusique,sample1,sample2);
        afficherBase(page,fond,base,fondation,listeEmplacementDefense,agrandissement,deplAffX,deplAffY);
        afficherBatiment(listeRessource,page,batiments,beacon,&batimentP,&conditionBase,deplAffX,deplAffY);
        if(pauseActive==0)
        {
            //calcule des positions des ennemis
            calculerPosition(horde, chemin, place, angle);
            gererDeplacement(&deplAffX,&deplAffY);
            incrementerTic(listeRessource,page,&angleR,&couleurR,deplAffX,deplAffY);
        }
        afficherLayoutMenu(page,layoutMenu,layoutMenu2,miniMap,deplAffX,deplAffY,joueur1,horde,PDVMuraille,agrandissement);
        testRecolter(listeRessource,&joueur1, &compteur,deplAffX, deplAffY);
        construireNouveauBatiment(listeRessource,page,menuC,construc,&conditionConstruction, &compteur2, &typeDeBatiment,&niveauBatiment,&agrandissement,&joueur1,deplAffX, deplAffY,&borne,buzzer,newBSound,selectSound,&PDVMuraille);
        ajouterFondation(page,construc,listeEmplacementDefense,&conditionConstruction,listeRessource,&xp,&yp,&compteur2,&niveauBatiment,&borne,deplAffX,deplAffY,&numeroEDD,&joueur1,buzzer);
        ajouterDefense(page,menuD,&joueur1,listeEmplacementDefense,listedef,&conditionConstruction,&typeDeBatiment,&compteur2,deplAffX,deplAffY,newBSound,buzzer);
        //affichage des ennemis
        dessinerMechant(horde, page, deplAffX, deplAffY, SeqM);

        if(listedef->premier!=NULL)
        {
            gestion_test_look_shoot_kill(listedef, horde, page, IMGdefense,bullet,deplAffX,deplAffY);
        }

        tutoriel(page,&tutoA,angleR,listeRessource,joueur1,listeEmplacementDefense,listedef);
        gererPause(page,&pauseActive,pause,&volumeMusique,&musiqueActive,voice,listeMusique2,&jeuActif);

        textprintf(page, font, 10, 10, makecol(255, 255, 255), "x: %d; y: %d", mouse_x, mouse_y);
        textprintf(page, font, 10, 20, makecol(255, 255, 255), "xs: %d; ys: %d", deplAffX + mouse_x, deplAffY + mouse_y);

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    sauvegarderNiveauUnlock(sauvegarde);
    if(sauvegarde!=0)
    {
        SauvegarderBatimentProduction(listeRessource, sauvegarde);
        SauvegarderEmplacementDisponible(listeEmplacementDefense, sauvegarde);
        SauvegarderDefense(listedef, sauvegarde);
    }
    libereBitmap(page,base,batiments,fond,construc,menuC,menuD,layoutMenu,miniMap,fondation,pause,IMGdefense,chemin,angle,place);
    libererSon(selectSound,newBSound,buzzer,bullet);
    detruireListe(listeRessource,listedef,listeEmplacementDefense,horde);
}
