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



void Map(char map[32][29],int x ,int y){
        int mini =min(largeurFenetre(),hauteurFenetre());
        int taille=mini/32;
        int decx=(largeurFenetre()-29*taille)*x/100;
        int decy=(hauteurFenetre()-32*taille)*y/100;
        int cmp=0,pos;
        int g=0,b=0,h=0,d=0;
        int list[4];
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 29; j++) {
              cmp=0;g=0;b=0;h=0;d=0;
              switch (map[i][j]) {
                case '0':
                    if (map[i+1][j]=='0') {g=1;}
                    if (map[i-1][j]=='0') {d=1;}
                    if (map[i][j+1]=='0') {b=1;}
                    if (map[i][j-1]=='0') {h=1;}
                    //printf("%i\n",cmp
                    list[0]=g;
                    list[1]=b;
                    list[2]=d;
                    list[3]=h;
                    cmp=list[0]+list[1]+list[2]+list[3];
                    switch (cmp) {
                      case 1:
                        couleurCourante(0, 0, 255);

                        if (g) {
                          arrondiBout(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,3);
                        }
                        if (d) {
                          arrondiBout(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,1);
                        }
                        if (h) {
                          arrondiBout(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,2);
                        }
                        if (b) {
                          arrondiBout(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,4);
                        }

                      break;
                      case 3:
                        couleurCourante(0, 0, 255);
                        rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                      break;
                      case 2:
                      couleurCourante(0, 0, 255);
                      if (map[i+1][j]=='0' && map[i-1][j]=='0') {couleurCourante(0, 0, 255);rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);break;}
                      if (map[i][j+1]=='0' && map[i][j-1]=='0') {couleurCourante(0, 0, 255);rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);break;}

                      for (pos = 0; list[pos]==1; pos++);
                      //printf("%i\n",pos);
                      if (list[(pos+1)%4]) {
                        switch ((pos+1)%4) {
                          case 0:
                            //arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 4);
                          break;
                          case 1:
                            arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 1);
                          break;
                          case 2:
                            //arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 4);
                          break;
                          case 3:
                            //arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 2);
                          break;
                        }
                      }
                      if (list[(pos+3)%4]) {
                        switch ((pos+3)%4) {
                          case 0:
                            arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 2);
                          break;
                          case 1:
                            arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 4);
                          break;
                          case 2:
                            //arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 3);
                          break;
                          case 3:
                            arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille, 3);
                          break;
                        }
                      }

                      break;
                      case 0:
                        couleurCourante(255, 255, 255);
                        rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                      break;

                    }
                    if (cmp>=4 || cmp<0) {
                      couleurCourante(0, 0, 255);
                      rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                    }

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
                    case '-':
                      couleurCourante(0, 0, 255);
                      rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                    break;
                }

              }
        }
}

void DrawPac(float x, float y,int dx,int dy,int direction){
	int r=2;
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
  taille=2+5;
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
}

void AfficheVie(int x,int y,GameStat stat){
  char buf[10]="VIE:";
  epaisseurDeTrait(2);
  int mini =min(largeurFenetre(),hauteurFenetre())/20;
  afficheChaine(buf,mini,largeurFenetre()*y/100,hauteurFenetre()*x/100);
  sprintf(buf, "%d", stat.vie);
  afficheChaine(buf,mini,2*mini+largeurFenetre()*y/100,hauteurFenetre()*x/100);
}

void AffichageScore(int x,int y,GameStat stat){
  char buf[10]="SCORE:";
  epaisseurDeTrait(2);
  int mini =min(largeurFenetre(),hauteurFenetre())/20;
  afficheChaine(buf,mini,largeurFenetre()*y/100,hauteurFenetre()*x/100);
  sprintf(buf, "%d", stat.point*10);
  afficheChaine(buf,mini,4*mini+largeurFenetre()*y/100,hauteurFenetre()*x/100);
}

void Manger(Entity pac,GameStat *stat,int taille,char coef[32][29]){

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
    stat->point++;
  }
  couleurCourante(255, 0, 0);
	epaisseurDeTrait(taille);
	//point(x, y);
}


<<<<<<< HEAD
void arrondiBout(int x,int y,int taille, int orientation){
=======
//couleurCourante(0, 0, 255);
//rectangle(j*taille+adjx,i*taille+adjy,(j+1)*taille+adjx,(i+1)*taille+adjy);
void arrondiBout(int x,int y,int taille, int orientation){
	couleurCourante(0, 0, 255);
>>>>>>> basabDEV
	epaisseurDeTrait(taille);
	point(x, y);
	switch (orientation)
	{
		case 1: //haut
			rectangle(x-(taille/2), y, x+(taille/2), y-(taille/2));
			break;
<<<<<<< HEAD

=======
	
>>>>>>> basabDEV
		case 2: //droit
			rectangle(x, y+(taille/2), x-(taille/2), y-(taille/2));
			break;

		case 3: //bas
			rectangle(x-(taille/2), y, x+(taille/2), y+(taille/2));
			break;

		case 4: //gauche
			rectangle(x, y-(taille/2), x+(taille/2), y+(taille/2));
			break;
	}
}

void arrondiAngle(int x, int y,int taille, int orientation){
<<<<<<< HEAD
=======
	couleurCourante(249, 255, 21);
>>>>>>> basabDEV
	epaisseurDeTrait(taille);
	point(x, y);
	switch (orientation)
	{
		case 1:
			//bas/gauche
			rectangle(x, y-(taille/2), x+(taille/2), y+(taille/2));
			rectangle(x, y-(taille/2), x-(taille/2), y);
<<<<<<< HEAD

			break;

=======
			
			break;
	
>>>>>>> basabDEV
		case 2:
			//haut/gauche
			rectangle(x, y+(taille/2), x-(taille/2), y-(taille/2));
			rectangle(x, y+(taille/2), x+(taille/2), y);
<<<<<<< HEAD

=======
			
>>>>>>> basabDEV
			break;

		case 3:
			//bas/droite
			rectangle(x, y-(taille/2), x+(taille/2), y);
			rectangle(x, y-(taille/2), x-(taille/2), y+(taille/2));
<<<<<<< HEAD

=======
			 
>>>>>>> basabDEV
			break;

		case 4:
			//droite/haut
			rectangle(x, y+(taille/2), x+(taille/2), y-(taille/2));
			rectangle(x, y+(taille/2), x-(taille/2), y);
			break;
	}
<<<<<<< HEAD

}
=======
	
}
>>>>>>> basabDEV
