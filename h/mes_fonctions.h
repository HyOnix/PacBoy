// .h necessaires a l'application
#include "../h/GfxLib.h"
#include "../h/ESLib.h"
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LargeurFenetre 600
#define HauteurFenetre 800

typedef struct {
  int x;
  int y;
  int v;
  int d;
  int state;

} Entity;

int min(int a,int b);
void FillMap(char coef[32][29]);
void Map(char coef[32][29],int x,int y);


void DrawPac(float x, float y,int dx,int dy,int direction);
void tri_angle(float x, float y, int ouverture, int direction, float taille);

void InitEntity(Entity *ent,int x,int y,int v,int d,int s);
void DeplacementPac(Entity *pac,char coef[32][29]);
void Manger(Entity pac,int taille,char coef[32][29]);
