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

void FillMap(char coef[32][29]);
void Map(char coef[32][29],int x,int y);
