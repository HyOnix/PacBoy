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
                    case '*':
                      couleurCourante(255, 255, 0);
              				epaisseurDeTrait(mini/100);
                      point((j+1)*taille+decx,i*taille+decy);
                      break;
                  }

              }
        }
}
