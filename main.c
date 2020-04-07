<<<<<<< HEAD
=======

<<<<<<< Updated upstream
>>>>>>> ab50734d9af911d4bc1a2931f7c6f842e4c16313
#include "h/mes_fonctions.h"
#include "h/fonctions_menu.h"

int main(int argc, char **argv) {

srand(time(NULL));
GenMap();
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
      dessinePAUSE(LargeurFenetre, HauteurFenetre);

      DeplacementIA0(&fantome, map);

      DeplacementPac(&pac, map);
      Manger(pac, &stat, taille, map);
      AffichageScore(90, 10, stat);
      AfficheVie(5, 10, stat);
      stat.vie = pac.state;
    }
    else if(start ==2){

    	afficheHighscore(LargeurFenetre, HauteurFenetre);
    	}
   
    else if(start ==3){

    	affichePause(LargeurFenetre, HauteurFenetre);
    	}
    else if(start ==0){
      menu(LargeurFenetre, HauteurFenetre);}
    break;

  case Clavier: // Une touche du clavier a ete pressee
    switch (caractereClavier()) {
    
      break;
    case 'k':
    case 'K':
      pac.d = 1;
      break;
    case 'l':
    case 'L':
      pac.d = 2;
      break;
    case 'm':
    case 'M':
      pac.d = 3;
      break;
    case 'o':
    case 'O':
      pac.d = 4;
      break;
    
      break;
    }
    break;
  case BoutonSouris:
  	switch(etatBoutonSouris()){
  	case GaucheAppuye:
  	//cas menu début
  	if(start ==0){
  	
  		//Bouton Play appuyé
  		if (( (abscisseSouris() > 35 * LargeurFenetre / 100) && (abscisseSouris() < 65 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 32 * HauteurFenetre / 100) && (ordonneeSouris() < 40 * HauteurFenetre / 100) ) ){
  		start = 1;
  		}
  		
  		//Bouton Quit appuyé
  		if (( (abscisseSouris() > 60 * LargeurFenetre / 100) && (abscisseSouris() < 90 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 17 * HauteurFenetre / 100) && (ordonneeSouris() < 25 * HauteurFenetre / 100) ) ){
  		system("clear");
      	exit(0);
  		}
  		
  		//Bouton Highscore appuyé
  		if (( (abscisseSouris() > 10 * LargeurFenetre / 100) && (abscisseSouris() < 40 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 17 * HauteurFenetre / 100) && (ordonneeSouris() < 25 * HauteurFenetre / 100) ) ){
  		start = 2;
  		}
  		}
  	
  	//cas highscore
  	if(start ==2){
  	
  		//Bouton Retour appuyé
  		if (( (abscisseSouris() > 35 * LargeurFenetre / 100) && (abscisseSouris() < 65 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 15 * HauteurFenetre / 100) && (ordonneeSouris() < 23 * HauteurFenetre / 100) ) ){
  		start = 0;
  		}
  	
  	
  	}
  	
  	//cas in game
  	if(start ==1){
  	
  		//Bouton Pause appuyé
  		if (( (abscisseSouris() > 70 * LargeurFenetre / 100) && (abscisseSouris() < 90 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 90 * HauteurFenetre / 100) && (ordonneeSouris() < 95 * HauteurFenetre / 100) ) ){
  		start = 3;
  		}
  	
  	
  	}
  	
  	//cas pause
  	if(start ==3){
  	
  		//Bouton Quit appuyé
  		if (( (abscisseSouris() > 35 * LargeurFenetre / 100) && (abscisseSouris() < 65 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 17 * HauteurFenetre / 100) && (ordonneeSouris() < 25 * HauteurFenetre / 100) ) ){
  		system("clear");
      	exit(0);
  		}
  		
  		//Bouton Reprendre appuyé
  		if (( (abscisseSouris() > 30.5 * LargeurFenetre / 100) && (abscisseSouris() < 70.5 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 37 * HauteurFenetre / 100) && (ordonneeSouris() < 45 * HauteurFenetre / 100) ) ){
  		start = 1;
  		}
  		
  		//Bouton Retour menu appuyé
  		if (( (abscisseSouris() > 20.5 * LargeurFenetre / 100) && (abscisseSouris() < 80.5 * LargeurFenetre / 100) ) && ( (ordonneeSouris() > 57 * HauteurFenetre / 100) && (ordonneeSouris() < 65 * HauteurFenetre / 100) ) ){
  		start = 0;
  		}
  		
  		
  	
  	
  	}
  		
  		break;
  	case DroiteAppuye:
  		
  		break;
  	case GaucheRelache:
  		
  		break;
  	case DroiteRelache:
  		
  		break;
  	
  	
  	}
  	
  	
  case Inactivite:
  case Souris:
  case Redimensionnement:
  case ClavierSpecial:
    break;
  }
}
