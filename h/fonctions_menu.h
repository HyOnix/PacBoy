// .h necessaires a l'application
#ifndef MES_FONCTIONS_H
#define MES_FONCTIONS_H
#include "GfxLib.h"
#include "ESLib.h"
/* Largeur et hauteur par defaut d'une fenetre correspondant a nos criteres */
struct PALETTE_RVB
{
  int red;
  int green;
  int blue;
};

typedef struct PALETTE_RVB palette_rvb;

void menu(int Largeur, int Hauteur);

void dessineJOUER(int Largeur, int Hauteur);

void dessineQUIT(int Largeur, int Hauteur, float x1, float x2, float y1, float y2);

void dessineTITRE(int Largeur, int Hauteur);

void dessineHIGHSCORE(int Largeur, int Hauteur);

void fantomeDraw(float x, float y, float taille, int red, int green, int blue);

void afficheHighscore(int Largeur, int Hauteur);

void dessineRETOUR(int Largeur, int Hauteur);

void dessinePAUSE(int Largeur, int Hauteur);

void affichePause(int Largeur, int Hauteur);

void DrawFantome(float x, float y, int dx, int dy, int red, int green, int blue);
/* Les prototypes des fonctions que nous aurons a ecrire */
void affiche_menu();
// plus les autres
// ..................

void JouerSon(char*nom);
void PauseSon();

#endif
