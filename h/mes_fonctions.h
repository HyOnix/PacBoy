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
<<<<<<< Updated upstream
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
=======
        int x;
        int y;
        int v;
        int d;
        int state;
} Entity;

typedef struct {
        int red;
        int green;
        int blue;
} Color;

typedef struct {
        int point;
        int vie;
        int etat;
        int vul;
        int pos[1][2];
>>>>>>> Stashed changes
} GameStat;

typedef struct {
        int score;
        char* login;
        int classement;
} Score;

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

<<<<<<< Updated upstream
void DeplacementIA0(Entity *pac, char coef[32][29]);
=======
void DeplacementIA0(Entity *chasseur, Entity *cible, char coef[32][29]);
void SaveGame(GameStat stat);
void saveHighScore(GameStat stat,char * login);
void LoadGame(GameStat *stat);

int VulFantome(Entity pac, Entity fantomes[NB_F]);

void DeplacementIA1(Entity *chasseur, Entity *cible, char coef[32][29]);
>>>>>>> Stashed changes
