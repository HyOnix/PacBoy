// .h necessaires a l'application
#ifndef MES_FONCTIONS_H
#define MES_FONCTIONS_H
#include "GfxLib.h"
#include "ESLib.h"
/* Largeur et hauteur par defaut d'une fenetre correspondant a nos criteres */
struct PALETTE_RVB {
  int red;
  int green;
  int blue;
};

typedef struct PALETTE_RVB palette_rvb;

void menu(int Largeur, int Hauteur);

void dessineJOUER(int Largeur, int Hauteur);

void dessineQUIT(int Largeur, int Hauteur);

void dessineTITRE(int Largeur, int Hauteur);

void dessineHIGHSCORE(int Largeur, int Hauteur);

void fantomeDraw(float x, float y, float taille, int red, int green, int blue);

void DrawFantome(float x, float y, int dx, int dy);
/* Les prototypes des fonctions que nous aurons a ecrire */
void affiche_menu();
// plus les autres
// ..................

#endif
