#include "prototypes.h"

int jeu(int sauvegarde, int tutoA, char *PseudoJoueur)
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
    int niveauJeu;
    int vitesseJeu = 3;
//    int nivMuraille = 1;  //niveau de la muraille : 1-petit  2-extension vers le bas  3-extension vers le haut
    int score = 0;
    int i;

    float angleR= 0;
    float couleurR = 0;
    char listeMusique[6][100]= {"son/musique/sentient.wav",
                                "son/musique/first-light.wav",
                                "son/musique/gathering-horizon.wav",
                                "son/musique/solar-intervention.wav",
                                "son/musique/the-oil-industry.wav",
                                "son/musique/the-search-for-iron.wav"
                               };
    char listeMusique2[6][100]= {"sentient",
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
    BITMAP *transisition[3];
    transisition[0] = load_bitmap("image/menu/continuer.bmp", NULL);
    transisition[1] = load_bitmap("image/menu/Quitter et Sauvegarder.bmp", NULL);
    transisition[2] = load_bitmap("image/menu/Quitter sans Sauvegarder.bmp", NULL);

    BITMAP *miniMap = NULL;
    BITMAP *fondation =NULL;
    BITMAP *pause[4];
    BITMAP *IMGdefense[4];
    BITMAP *chemin=NULL;
    BITMAP *angle=NULL;
    BITMAP *IMGMine[2];
    BITMAP *Explosion = load_bitmap("image/defense/medium-explosion.bmp",NULL);

    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    IMGdefense[0] = load_bitmap("image/defense/1.bmp", NULL);
    IMGdefense[1] = load_bitmap("image/defense/2.bmp", NULL);
    IMGdefense[2] = load_bitmap("image/defense/3.bmp", NULL);
    IMGdefense[3] = load_bitmap("image/defense/bullet.bmp", NULL);
    IMGMine[0]=load_bitmap("image/defense/mine.bmp",NULL);
    IMGMine[1]=load_bitmap("image/defense/mine2.bmp",NULL);

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
    t_listeMine *listeMine=(t_listeMine*)malloc(sizeof(t_listeMine));
    listeMine->premier= NULL;
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
        niveauJeu = 1;
    }
    else if(sauvegarde != 0)
    {
        int temp = 0;
        listedef = malloc(sizeof(t_listedef));
        listedef->premier = NULL;
        recupererDefense(listedef, sauvegarde);
        listeEmplacementDefense = malloc(sizeof(t_listeEDD));
        listeEmplacementDefense->premier = NULL;
        listeRessource = malloc(sizeof(t_listeBR));
        listeRessource->premier = NULL;
        recupererBatimentProduction(listeRessource, sauvegarde);
        recupererEmplacementDispo(listeEmplacementDefense, sauvegarde);
        recupererAnecdote(&joueur1, &agrandissement, &score, &PDVMuraille, sauvegarde);
        ajusterBase(&borne, agrandissement,&temp);
        recupererMine(listeMine, sauvegarde);
        if(sauvegarde == 1)
        {
            niveauJeu = 1;
        }
        else if(sauvegarde == 2)
        {
            niveauJeu =3;
        }
        else if(sauvegarde == 3)
        {
            niveauJeu =5;
        }
        else if(sauvegarde == 4)
        {
            niveauJeu = 7;
        }
    }

    initSeqM(SeqM);
    initAncre(horde);
    while ((!key[KEY_ESC])&&(jeuActif==1))
    {


        clear_bitmap(page);
        clear_bitmap(place);

        if(niveauJeu%2==1)
        {
            creer_horde(horde, &niveauJeu, vitesseJeu, agrandissement);

            gererMusique(&conditionMusique,&musiqueActive,voice,listeMusique,sample1,sample2);
            afficherBase(page,fond,base,fondation,PDVMuraille,listeEmplacementDefense,agrandissement,deplAffX,deplAffY);
            afficherBatiment(listeRessource, listeMine, Explosion, page, batiments, beacon, IMGMine, &batimentP, &conditionBase, deplAffX, deplAffY);

            if(listedef->premier!=NULL)
            {
                gestion_test_look_shoot_kill(listedef, horde, page, IMGdefense,deplAffX,deplAffY,voiceB);
            }

            if(pauseActive==0)
            {
                //calcule des positions des ennemis
                calculerPosition(horde, chemin, place, angle, vitesseJeu, agrandissement);
                gererDeplacement(&deplAffX,&deplAffY);
                incrementerTic(listeRessource,page,&angleR,&couleurR,deplAffX,deplAffY);
            }
            //affichage des ennemis
            dessinerMechant(horde, page, deplAffX, deplAffY, SeqM);

            afficherLayoutMenu(page,layoutMenu,miniMap,borne,PseudoJoueur,score,niveauJeu,deplAffX,deplAffY,joueur1,horde,listedef,PDVMuraille,agrandissement);
            testRecolter(listeRessource,&joueur1, &compteur,deplAffX, deplAffY);
            construireNouveauBatiment(listeRessource,listedef,listeEmplacementDefense,page,menuC,construc,&conditionConstruction, &compteur2, &typeDeBatiment,&niveauBatiment,&agrandissement,&joueur1,deplAffX, deplAffY,&borne,&PDVMuraille,voiceB);
            ajouterFondation(page,chemin,construc,listeEmplacementDefense,&conditionConstruction,listeRessource,&xp,&yp,&compteur2,&niveauBatiment,&borne,deplAffX,deplAffY,&numeroEDD,&joueur1,voiceB);
            ajouterDefense(page,menuD,&joueur1,listeEmplacementDefense,listedef,listeMine,&conditionConstruction,&typeDeBatiment,&compteur2,deplAffX,deplAffY,voiceB);

            attaquerMur(horde, &PDVMuraille);
            gererMine(listeMine,horde);

            tutoriel(page,&tutoA,angleR,listeRessource,joueur1,listeEmplacementDefense,listedef);
            gererPause(page,&pauseActive,pause,&volumeMusique,&musiqueActive,voice,listeMusique2,&jeuActif);

            supprimerEnnemi(horde,&score);
        }
        else if(niveauJeu%2==0 && niveauJeu!= 7)
        {
            rectfill(page, 0,0,1280, 1024, makecol(0,0,0));
            passageNiveau(page, transisition, &niveauJeu, &jeuActif, &compteur);
            if(niveauJeu == 3) //niveau 2
            {
                sauvegarde = 2;
            }
            else if(niveauJeu == 5) //niveau 3
            {
                sauvegarde = 3;
            }
            else if(niveauJeu == 7) //endless mode
            {
                sauvegarde = 4;
            }
            if(jeuActif == 4)
            {
                SauvegarderBatimentProduction(listeRessource, sauvegarde);
                SauvegarderEmplacementDisponible(listeEmplacementDefense, sauvegarde);
                SauvegarderDefense(listedef, sauvegarde);
                sauvegardeAnecdote(joueur1, agrandissement, score, PDVMuraille, sauvegarde);
                sauvegarderMine(listeMine, sauvegarde);
                jeuActif = 1;
            }
        }
        if(PDVMuraille <= 0)
        {
            jeuActif = 4;
        }
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

    for(i=0; i<4; i++)
    {
        release_voice(voiceB[i]);
    }

    if(jeuActif != 4)
    {
        sauvegarderNiveauUnlock(sauvegarde);
        sauvegarderNom(PseudoJoueur);
    }
    if((sauvegarde != 0 && jeuActif != 3 && jeuActif !=1 && jeuActif != 4) || (niveauJeu == 7))
    {
        SauvegarderBatimentProduction(listeRessource, sauvegarde);
        SauvegarderEmplacementDisponible(listeEmplacementDefense, sauvegarde);
        SauvegarderDefense(listedef, sauvegarde);
        sauvegardeAnecdote(joueur1, agrandissement, score, PDVMuraille, sauvegarde);
        sauvegarderMine(listeMine, sauvegarde);
    }
    libereBitmap(page,transisition,base,batiments,fond,construc,menuC,menuD,layoutMenu,miniMap,fondation,pause,IMGdefense,chemin,angle,place, SeqM,beacon,IMGMine);
    libererSon(selectSound,newBSound,buzzer,bullet);
    detruireListe(listeRessource,listedef,listeEmplacementDefense,listeMine,horde);
    return score+(PDVMuraille/5)+(joueur1.or/10)+(joueur1.metal/10)+(joueur1.pierre/10);
}
