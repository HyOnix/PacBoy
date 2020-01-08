
#include "h/mes_fonctions.h"


int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();
	return 0;
}

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
