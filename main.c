#include "h/mes_fonctions.h"
#include "h/fonctions_menu.h"

int main(int argc, char **argv) {
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

      DeplacementIA0(&fantome, map);

      DeplacementPac(&pac, map);
      Manger(pac, &stat, taille, map);
      AffichageScore(90, 10, stat);
      AfficheVie(5, 10, stat);
      stat.vie = pac.state;
    } else
      menu(LargeurFenetre, HauteurFenetre);
    break;

  case Clavier: // Une touche du clavier a ete pressee
    switch (caractereClavier()) {
    case 'Q':
    case 'q':
      system("clear");
      exit(0);
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
    case 'a':
    case 'A':
      start = 1;
      break;
    }
    break;
  case BoutonSouris:
  case Inactivite:
  case Souris:
  case Redimensionnement:
  case ClavierSpecial:
    break;
  }
}
