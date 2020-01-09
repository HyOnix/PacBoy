
#include "h/mes_fonctions.h"


int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("OpenGL", LargeurFenetre, HauteurFenetre);
	lanceBoucleEvenements();
	return 0;
}

void gestionEvenement(EvenementGfx evenement){
	static char map[32][29];
	int taille=min(largeurFenetre(),hauteurFenetre())/32;
	static Entity pac;
	switch (evenement){
		case Initialisation:{
				printf("Initialisation\n");//////////////////////////////////
				FillMap(map);
				InitEntity(&pac,1.5*taille,2.5*taille,3,0,0);
				demandeAnimation_ips(25);////////////////////////////////////
			}
			break;
		case Affichage:{


				effaceFenetre (0,0,0);
				Map(map,50,50);
				DrawPac(pac.x,pac.y,50,50,pac.d);
				DeplacementPac(&pac,map);
				Manger(pac,taille,map);

			break;
		case Clavier: // Une touche du clavier a ete pressee
	  	switch (caractereClavier()){
				case 'Q':case 'q':exit(0);break;
				case 'k':case 'K':pac.d=1;break;
				case 'l':case 'L':pac.d=2;break;
				case 'm':case 'M':pac.d=3;break;
				case 'o':case 'O':pac.d=4;break;
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
