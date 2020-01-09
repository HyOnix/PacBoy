#include "../h/mes_fonctions.h"

int min(int a,int b){return (a < b) ? a : b ;}

void FillMap(char coef[32][29]){
        FILE * ptrfile = fopen("file/map.txt","r");
        char init;
        for (size_t i = 0; i < 32; i++) {
                for (size_t j = 0; j < 29; j++) {
                        fscanf(ptrfile,"%c ",&init);
                        coef[i][j]=init;
                }
        }
        fclose(ptrfile);
}



void Map(char coef[32][29],int x ,int y){
        int mini =min(largeurFenetre(),hauteurFenetre());
        int taille=mini/32;
        int decx=(largeurFenetre()-29*taille)*x/100;
        int decy=(hauteurFenetre()-32*taille)*y/100;
        for (size_t i = 0; i < 32; i++) {
            for (size_t j = 0; j < 29; j++) {
                  switch (coef[i][j]) {
                    case '0':
                      couleurCourante(0, 0, 255);
                      rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                      break;
                    case '.':
                      couleurCourante(150, 150, 150);
                      //rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                      break;
                    case '*':
                      couleurCourante(255, 255, 0);
              				epaisseurDeTrait(mini/100);
                      point((j+1)*taille+decx,i*taille+decy);
                      //point((j)*taille+decx,i*taille+decy);
                      break;
                  }

              }
        }
}

void DrawPac(float x, float y,int dx,int dy,int direction){
	int r=3;
  int mini =min(largeurFenetre(),hauteurFenetre());
  int taille=mini/32;
	static int count = 0;
	static int state=0;

  dx=(largeurFenetre()-29*taille)*dx/100;
  dy=(hauteurFenetre()-32*taille)*dy/100;

  x+=dx+1*taille/2;
  y+=dy-1*taille/2;

  taille=mini/25;
	//dessine le cercle qui est toujours présent
	couleurCourante(249, 255, 21);
	epaisseurDeTrait(taille);
	point(x, y);
	couleurCourante(0, 0, 0);
  taille--;
	switch (count){
	case 0 :
		tri_angle(x, y, 8, direction, taille);
		break;

	case 1 :
		tri_angle(x, y, 4, direction, taille);
		break;
	case 2 :
		tri_angle(x, y, 2, direction, taille);
		break;
	}

	state = (state +1)%(r*3);
	count = state/r;
}

void tri_angle(float x, float y, int ouverture, int direction, float taille){

	switch (direction)
	{
	case 1: // left
		triangle(x, y, x-(taille/2), y-(taille/ouverture), x-(taille/2), y+(taille/ouverture));
		break;

	case 2: //down
		triangle(x, y, x+(taille/ouverture), y-(taille/2), x-(taille/ouverture), y-(taille/2));
		break;

	case 3: //right
		triangle(x, y, x+(taille/2), y+(taille/ouverture), x+(taille/2), y-(taille/ouverture));
		break;

	case 4: //up
		triangle(x, y, x-(taille/ouverture), y+(taille/2), x+(taille/ouverture), y+(taille/2));
		break;
	}
}

void InitEntity(Entity *ent,int x,int y,int v,int d,int s){
  ent->x=x;
  ent->y=y;
  ent->v=v;
  ent->d=d;
  ent->state=s;
}

int isOK(int x,int y,char coef[32][29]){
  int mini =min(largeurFenetre(),hauteurFenetre());
  int taille=mini/32;
  y/=taille;
  x/=taille;
  if (coef[y][x]==' ' || coef[y][x]=='*') {
    return 1;
    //printf("ok");
  }
  //printf("ERREUR x:%i y:%i %c\n", x,y,coef[y][x]);
  return 0;
}

void DeplacementPac(Entity *pac,char coef[32][29]){
  int mini =min(largeurFenetre(),hauteurFenetre());
  int taille=mini/32;
  taille=2+7;
  switch (pac->d) {
    case 1:
    case 3:
      if (isOK(pac->x+(pac->d-2)*(pac->v+taille),pac->y,coef)) {
        pac->x+=(pac->d-2)*(pac->v);
      }
      break;
    case 2:
    case 4:
      if (isOK(pac->x,pac->y+(pac->d-3)*(pac->v+taille),coef)) {
        pac->y+=(pac->d-3)*(pac->v);
      }
      break;
  }
//  printf("x: %i  y: %i\n",pac->x/taille,pac->y/taille);
  if (pac->y/taille==31 || pac->y/taille==30) {
    switch (pac->x/taille) {
      case 0:pac->x=54*taille;
      break;
      case 54:pac->x=1*taille;
      break;
    }
  }

}

void Manger(Entity pac,int taille,char coef[32][29]){

  int mini =min(largeurFenetre(),hauteurFenetre());
  taille=mini/32;
  int decx=(largeurFenetre()-29*taille)*50/100;
  int decy=(hauteurFenetre()-32*taille)*80/100;

  int x=((pac.x)/taille);
  int y=((pac.y)/taille);

  x*=taille;
  y*=taille;
  x+=decx;
  y+=decy;

  if(coef[(y-decy)/taille][(x-decx)/taille]=='*'){
    coef[(y-decy)/taille][(x-decx)/taille]=' ';
  }
  couleurCourante(255, 0, 0);
	epaisseurDeTrait(taille);
	//point(x, y);
}
