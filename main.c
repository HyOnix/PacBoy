
<<<<<<< Updated upstream
#include "h/mes_fonctions.h"


int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();
	return 0;
}
=======
int main(int argc, char **argv) {

	srand(time(NULL));
	//a peut etre nelever de la 
	GenMap();
  initialiseGfx(argc, argv);
  prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
  lanceBoucleEvenements();
  return 0;
}

void gestionEvenement(EvenementGfx evenement) {
  static int start = 0;
  static char map[32][29];
  int taille = min(largeurFenetre(), hauteurFenetre()) / 32;
  static Entity pac;
  static Entity fantome;
  static GameStat stat;
  switch (evenement) {
  case Initialisation: {
    printf("Initialisation\n"); //////////////////////////////////
    FillMap(map);
    InitEntity(&pac, 1.5 * taille, 2.5 * taille, 4, 0, 0);
    InitEntity(&fantome, 1.5 * taille, 22.5 * taille, 4, 2, 0);
    demandeAnimation_ips(20); ////////////////////////////////////
  } break;
  case Affichage:
    effaceFenetre(0, 0, 0);
    if (start == 1) {
      Map(map, 50, 50);
      DrawPac(pac.x, pac.y, 50, 50, pac.d);
      DrawFantome(fantome.x, fantome.y, 50, 50);
>>>>>>> Stashed changes

void gestionEvenement(EvenementGfx evenement){

	switch (evenement){
		case Initialisation:{
				printf("Initialisation\n");//////////////////////////////////

				demandeAnimation_ips(30);////////////////////////////////////
			}
			break;
		case Affichage:{
				effaceFenetre (0,0,0);
			break;
		case Clavier: // Une touche du clavier a ete pressee
	  	switch (caractereClavier()){
				case 'Q':case 'q':exit(0);break;
				};break;
	    }
	    break;
	  case BoutonSouris:
		break;
		case Inactivite:
		case Souris:
		case Redimensionnement:
		case ClavierSpecial:
		break;
	}
}
