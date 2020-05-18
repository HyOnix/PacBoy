// .h necessaires a l'application
#include "../h/GfxLib.h"
#include "../h/ESLib.h"
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define LargeurFenetre 600
#define HauteurFenetre 800

void GenMap();

typedef struct {
  int x;
  int y;
  int v;
  int d;
  int state;
} Entity;

typedef struct {
  int point;
  int vie;
  int etat;
  int vul;
} GameStat;

int min(int a, int b);

void DeplacementPac(Entity *pac, char coef[32][29]);
void InitEntity(Entity *ent, int x, int y, int v, int d, int s);
void Manger(Entity pac, GameStat *stat, int taille, char coef[32][29]);
void AffichageScore(int x, int y, GameStat stat);
void AfficheVie(int x, int y, GameStat stat);

void arrondiBout(int x, int y, int taille, int orientation);
void arrondiAngle(int x, int y, int taille, int orientation);
void FillMap(char coef[32][29]);
void Map(char map[32][29], int x, int y);
void DrawPac(float x, float y, int dx, int dy, int direction);
void tri_angle(float x, float y, int ouverture, int direction, float taille);

void DeplacementIA0(Entity *pac, char coef[32][29]);
void DeplacementIA1(Entity *pac,Entity *cible, char coef[32][29]);
