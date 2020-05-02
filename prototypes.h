#ifndef PROTORYPES_H_INCLUDED
#define PROTORYPES_H_INCLUDED


#include "structures.h"
int jeu(int sauvegarde, int tutoA, char *pseudoJoueur);
void gererMusique(int *condition,int *musique,int voice,char listeMusique[6][100],SAMPLE* sample1,SAMPLE* sample2);
void gererPause(BITMAP *page,int *pauseActive, BITMAP* pause[4],int* volumeMusique,int *musique,int voice,char listeMusique[6][100],int *jeuActif);
void libereBitmap(BITMAP *page,BITMAP *transisition[3],BITMAP *base[3],BITMAP *batiments[9],BITMAP *fond,BITMAP *construc,BITMAP *menuC,BITMAP *menuD,BITMAP *layoutMenu[3],BITMAP *miniMap,BITMAP *fondation,BITMAP *pause[4],BITMAP *IMGdefense[4],BITMAP* chemin,BITMAP* angle,BITMAP* place, BITMAP *SeqM[],BITMAP* beacon[2],BITMAP* IMGMine[2]);
void libererSon(SAMPLE *selectSound,SAMPLE *newBSound,SAMPLE *buzzer,SAMPLE *bullet);

void tutoriel(BITMAP* page,int *tutoA,int angle,t_listeBR *liste1,t_joueur joueur,t_listeEDD *liste2,t_listedef *liste3);

t_listeBR *InitialisationBR(BITMAP* batiments[3]);
t_listeEDD *InitialisationEDD();
void incrementerTic(t_listeBR* liste,BITMAP* page, float *angle,float *couleurR,int deplAffX,int deplAffY);
void afficherBase(BITMAP* page,BITMAP* fond,BITMAP* base[3],BITMAP* fondation,int PDV,t_listeEDD *liste,int agrandissement, int deplAffX, int deplAffY);
void gererDeplacement(int *deplAffX,int *deplAffY);
void testRecolter(t_listeBR *liste,t_joueur *joueur,int *i,int deplAffX,int deplAffY);
void afficherEmplacementDisponible(t_listeBR *liste,BITMAP* page,int niveau,int deplAffX,int deplAffY,t_borne borne);
void ajouterBatiment(t_listeBR *liste, int typeDeBatiment,int niveauBatiment,t_joueur* joueur, int x, int y);
void construireNouveauBatiment(t_listeBR *liste,t_listedef* liste2,t_listeEDD *liste3,BITMAP *page,BITMAP *menuC,BITMAP *construc,int *condition,int *i, int* typeDeBatiment,int *niveaubatiment,int* agrandissement,t_joueur* joueur,int deplAffX,int deplAffY,t_borne *borne,int *PDV,int voice[4]);
void definirCoordonnees(int *x,int *y,t_borne borne,int niveau);
int testSiBatimentPresent(t_listeBR *liste,int x, int y,int niveau);
int testDefensePresente(t_listeEDD *listeEDD,int x,int y,int typeDeBatiment);
int testSiArgentSuffisant(t_joueur *joueur,int niveauBatiment,int typeDeBatiment,int typeDeTest,int voice[4]);
void ajusterBase(t_borne *borne, int agrandissement,int *PDV);
void afficherLayoutMenu(BITMAP* page,BITMAP* layoutMenu[3],BITMAP* miniMap,t_borne borne,char *PseudoJoueur,int score,int niveauJeu, int deplAffX,int deplAffY,t_joueur joueur,t_listeMechant *horde,t_listedef *liste2,int PDV,int agrandissement);
void afficherBatiment(t_listeBR *liste,t_listeMine*listeMine,BITMAP* explosion,BITMAP* page,BITMAP* batiments[3],BITMAP* beacon[2],BITMAP *IMGMine[2],t_batimentP* batimentP,int *condition,int deplAffX, int deplAffY);
void ameliorerBatiment(t_listeBR *liste, int x, int y);
void supprimerBatiment(t_listeBR *liste, int x, int y);
void supprimerBatimentD(t_listedef *liste, t_listeEDD *liste2, int x, int y);
void ajouterFondation(BITMAP* page,BITMAP* chemin,BITMAP *construc,t_listeEDD *liste,int *condition,t_listeBR *listeBR,int *xp,int *yp,int *i,int *niveaubatiment,t_borne *borne,int deplAffX, int deplAffY,int *numeroEDD,t_joueur* joueur,int voice[4]);
void ajusterFondation(int*x,int*y);
void nouvelleFondation(t_listeEDD *liste,int x, int y,int *numeroEDD);
void ajouterDefense(BITMAP* page,BITMAP *menuD,t_joueur* joueur,t_listeEDD *liste,t_listedef *listedef,t_listeMine *listeMine,int *condition,int *typeDeBatiment,int *i,int deplAffX, int deplAffY,int voice[4]);
void afficherDefenseDisponible(t_listeEDD *liste,BITMAP* page,int *typeDeBatiment,int deplAffX,int deplAffY);
void ajusterDefense(int*x,int*y);
void nouvelleDefense(t_listeEDD *liste,t_listedef *listedef,int x, int y,int typeDeBatiment);
void determinerBatiment(t_listeBR *liste,int *x, int *y,int *niveauBatiment);
void afficherInfoBatimentBR(BITMAP* page);
void afficherInfoBatimentD(BITMAP* page);
void afficherInfo(BITMAP* page);
void detruireListe(t_listeBR *liste1,t_listedef *liste2, t_listeEDD *liste3,t_listeMine *listeMine,t_listeMechant* liste4);
void nouvelleMine(t_listeMine *listeMine,int x, int y,int typeDeBatiment);
void gererMine(t_listeMine *liste, t_listeMechant *horde);
int testMinePresente(t_listeMine *liste, int x,int y);

void supprimerEnnemi(t_listeMechant *liste,int *score);


/////////////////prototype de lib.h/////////////////////////

void lancerAllegro(int largeur, int hauteur);
double calcul_angle(t_defense defense, t_ennemi mechant);
t_listedef *initialisationDef();
t_listeMechant *initialisationMech();
void ajoutDef(t_listedef *liste, int type, int x, int y);
void ajoutMech(t_listeMechant *liste, int valeur);
int test(t_defense defense, t_ennemi mechant);
void verificationListe(t_listedef *listedef);
void gestion_test_look_shoot_kill(t_listedef *listedef, t_listeMechant *listeMechant, BITMAP *buffer, BITMAP *image[4],int deplAffX, int deplAffY,int voice[4]);
void ajoutBalle(t_listeBalle *defense);
void animation(BITMAP *image[], BITMAP *buffer, t_defense *defense,int deplAffX, int deplAffY);
void chargementImageetSon(BITMAP *image[4], SAMPLE *son);

void chargementImageMenu(BITMAP *image[20]);
void dechargementImage(BITMAP *image[20]);
void affichageBoutton(BITMAP *image,BITMAP *buffer,int etat, int x, int y, float zoom);
void MenuPrincipale(BITMAP *buffer, BITMAP *image[20], int *scene, int *compteur, int sauvegarde);
void NouvellePartie(BITMAP *buffer, BITMAP *image[20], int *scene, int *compteur, int sauvegarde, int *tuto, int *ecrire, char *chaine, int *pos, int *clic, int *score);
void affichageCheck(BITMAP *image, BITMAP *buffer, int etat, int x, int y);
void toucheClavier(char *chaine, BITMAP *buffer, int *pos, int *clic);
void ChargerUnePartie(BITMAP *buffer, BITMAP *image[20], int *scene, int *compteur, int *sauvegarde, int *score,char *chaine);
void leaderBoard(BITMAP *buffer, BITMAP *image[20], int *scene, int *compteur, t_classement tableau[20], int *sourisY, int *y);
void passageNiveau(BITMAP *buffer,BITMAP *bouton[3], int *niveau, int *jeuActif, int *compteur);
void envoieScoreServeur(BITMAP *buffer, BITMAP *image[20], int *scene, int *compteur, char *chaine, int score);



////////////////prototype bilbioMechant.h///////////////////////////////////////

//gestion des séquences des ennemis
void chargerSequence(BITMAP* *sqc);
void initSeqM(BITMAP* tableauSeq[NB_SEQM]);
void imageAfficheMechant(t_ennemi *elemA, BITMAP* seqMechant[NB_SEQM]);

//gérération et suppression des ennemis
void initAncre(t_listeMechant* horde);
void actualiserListeMechant(t_listeMechant* horde, int* niveau);
int typeEnnemiGenerer(int nbMechant[5], int numVague, int* niveau);
void ajouterPremierEnnemi(t_listeMechant* ancre, int nivMur, int numVague, int* niveau);
void ajouterEnnemi(t_listeMechant* ancre, int nivMur, int numVague, int* niveau);
void creer_horde(t_listeMechant* ancreH, int* niveau, int vit, int nivMur);
void posAlea(int* x, int* y, int nivMur, int type);
t_ennemi *creerEnnemis(t_listeMechant *ancre, int type, int nb, int nivMur);
void supprimerElementTete(t_listeMechant* ancre);
void supprimerListe(t_listeMechant* ancre);

//gestion des déplacement et position des ennemis
void actualiserDeplacement(t_ennemi* mechantA, BITMAP* chemin);
int testFuturePlaceLibre(BITMAP* place, t_ennemi* elem);
int testPlaceLibre(BITMAP* place, int x, int y);
int testChemin(t_ennemi* elemA, int x, int y, int nivMur);
int espacementH(t_ennemi* elem, BITMAP* place, int *chemin, int nivMur);
int testUtile(BITMAP* place, int x, int y);
void espacementV(t_ennemi* elem, BITMAP* place, int nivMur);
void etalementMur(t_ennemi* elemA, BITMAP* place, int nivMur);
void etalement(t_ennemi* elem, BITMAP* place, int nivMur);
void replacementY(t_ennemi *elem);
void calculeAngle(t_ennemi *mechant, BITMAP* angle);
void calculerPosition(t_listeMechant* ancreH, BITMAP* chemin, BITMAP* place, BITMAP* angle, int vitese, int nivMur);
void ennemiDevantMur(BITMAP* place, t_ennemi* elemA, int nivMur);
void attaquerMur(t_listeMechant* horde, int* pvMur);


//gestion affichage des ennemis
void dessinerMechant(t_listeMechant* horde, BITMAP* buffer, int screenx, int screeny, BITMAP* lesSeq[NB_SEQM]);
void positionEcran(int* screenx, int* screeny, BITMAP* decor);


//////////////prototype sauvegarde////////////////////

t_listeEDD *triEDD(t_listeEDD *liste);
void sauvegarderNiveauUnlock(int sauvegarde);
void AjouterMaillonBRVide(t_listeBR *liste);
void recupererBatimentProduction(t_listeBR *liste, int niveau);
int recupererNiveauUnlock();
void AjouterMaillonDefenseVide(t_listedef *liste);
void recupererDefense(t_listedef *liste, int niveau);
void ajouterEDDVide(t_listeEDD *liste);
void recupererEmplacementDispo(t_listeEDD *liste, int niveau);
void SauvegarderBatimentProduction(t_listeBR *liste, int niveau);
void SauvegarderEmplacementDisponible(t_listeEDD *liste, int niveau);
void SauvegarderDefense(t_listedef *liste, int niveau);
void recupererAnecdote(t_joueur *joueur, int *TBase, int *scoreE, int *PDV, int sauvegarde);
void sauvegardeAnecdote(t_joueur joueur, int TBase, int scoreE, int PDV, int sauvegarde);
void recupererNom(char *chaine);
void sauvegarderNom(char *nom);
void recupererMine(t_listeMine *liste, int niveau);
void sauvegarderMine(t_listeMine *liste, int niveau);

#endif // PROTORYPES_H_INCLUDED

