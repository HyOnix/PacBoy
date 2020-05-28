// .h necessaires a l'application
#ifndef MES_FONCTIONS_H
#define MES_FONCTIONS_H
#include "GfxLib.h"
#include "ESLib.h"
/* Largeur et hauteur par defaut d'une fenetre correspondant a nos criteres */

/* Les prototypes des fonctions que nous aurons a ecrire */

void menu(int Largeur, int Hauteur);

void dessineJOUER(int Largeur, int Hauteur);

void dessineBox(float x1, float x2, float y1, float y2);

void dessineTITRE(int Largeur, int Hauteur);

void dessineHIGHSCORE(int Largeur, int Hauteur);

void fantomeDraw(float x, float y, float taille, int red, int green, int blue);

void afficheHighscore(int Largeur, int Hauteur);

void dessineRETOUR(int Largeur, int Hauteur, int y);

void dessinePAUSE(int Largeur, int Hauteur);

void affichePause(int Largeur, int Hauteur);

void affichePlay(int Largeur, int Hauteur);

void DrawFantome(float x, float y, int dx, int dy, int red, int green, int blue);

void afficheGameover(int Largeur, int Hauteur, int score);

// plus les autres
// ..................

#endif
