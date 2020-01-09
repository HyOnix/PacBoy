#include "../h/ESLib.h"
#include "../h/fonctions_menu.h"
#include <stdio.h>

/* Largeur et hauteur par defaut d'une fenetre correspondant a nos criteres */

void affiche_menu(){
		sautDeLigne();
     	ecrisChaine("*************  TP GRAPHIQUE ******** \n");
     	ecrisChaine("taper h	pour afficher ce menu    :\n");
     	ecrisChaine("taper r	pour rafraichir la fenêtre graphique    :\n");
     	ecrisChaine("taper q    pour  SORTIR de l'APPLICATION  : \n");  
     	sautDeLigne();   
     
}



void menu(int Largeur, int Hauteur){
static int x=0;
if(x>=1600){
dessineJOUER(Largeur, Hauteur);
dessineQUIT(Largeur, Hauteur);

dessineTITRE(Largeur, Hauteur);

dessineHIGHSCORE(Largeur, Hauteur);
}



if(x>=100){
fantomeDraw(12*Largeur/100, (75*Hauteur/100) - 5*Largeur/100, 5*Largeur/100, 255, 20, 20);
couleurCourante(255, 20, 20);
epaisseurDeTrait(1);
x++;
}

if(x>=200){
afficheChaine(" - SHADOW", 5*Largeur/100, 17*Largeur/100, (73.5*Hauteur/100) - 5*Largeur/100);
x++;}
if(x>=300){
afficheChaine("' BLINKY '", 5*Largeur/100, 62*Largeur/100, (73.5*Hauteur/100) - 5*Largeur/100);
x++;}

if(x>=400){
fantomeDraw(12*Largeur/100, (68*Hauteur/100) - 5*Largeur/100, 5*Largeur/100, 228, 139, 224);

couleurCourante(228, 139, 224);
epaisseurDeTrait(1);
x++;}
if(x>=500){
afficheChaine(" - SPEEDY", 5*Largeur/100, 17*Largeur/100, (66.5*Hauteur/100) - 5*Largeur/100);
x++;}
if(x>=600){
afficheChaine("' PINKY '", 5*Largeur/100, 62*Largeur/100, (66.5*Hauteur/100) - 5*Largeur/100);
x++;}



if(x>=700){
fantomeDraw(12*Largeur/100, (61*Hauteur/100) - 5*Largeur/100, 5*Largeur/100, 115, 202, 228);
couleurCourante(115, 202, 228);
epaisseurDeTrait(1);
x++;}
if(x>=800){
afficheChaine(" - BASHFUL", 5*Largeur/100, 17*Largeur/100, (59.5*Hauteur/100) - 5*Largeur/100);
x++;}
if(x>=900){
afficheChaine("' INKY '", 5*Largeur/100, 62*Largeur/100, (59.5*Hauteur/100) - 5*Largeur/100);
x++;}

if(x>=1000){
fantomeDraw(12*Largeur/100, (54*Hauteur/100) - 5*Largeur/100, 5*Largeur/100, 255, 192, 27);
epaisseurDeTrait(1);
couleurCourante(255, 192, 27);
x++;
}
if(x>=1100){
afficheChaine(" - POKEY", 5*Largeur/100, 17*Largeur/100, (52.5*Hauteur/100) - 5*Largeur/100);
x++;}
if(x>=1200){
afficheChaine("' CLYDE '", 5*Largeur/100, 62*Largeur/100, (52.5*Hauteur/100) - 5*Largeur/100);
x++;}


couleurCourante(255, 255,255);
afficheChaine(" CHARACTER / NICKNAME", 5*Largeur/100, 17*Largeur/100, (79.5*Hauteur/100) - 5*Largeur/100);
if(x>=1300){
afficheChaine("TEAM DRAGON FORCE ALPHAS - TOUS DROITS RESERVES - 2020", 2*Largeur/100, 11*Largeur/100, 5*Hauteur/100);
x++;}
//printf("%i\n",x);
x++;
}

void dessineJOUER(int Largeur, int Hauteur){
couleurCourante(252, 255,19);
epaisseurDeTrait(1);
//rectangle(35*Largeur/100, 32*Hauteur/100, 65*Largeur/100, 4*Hauteur/10);
ligne(35*Largeur/100,32*Hauteur/100, 65*Largeur/100, 32*Hauteur/100);
ligne(65*Largeur/100,32*Hauteur/100, 65*Largeur/100, 4*Hauteur/10);
ligne(35*Largeur/100,4*Hauteur/10, 65*Largeur/100, 4*Hauteur/10);
ligne(35*Largeur/100,32*Hauteur/100, 35*Largeur/100, 4*Hauteur/10);

epaisseurDeTrait(2);
afficheChaine("PLAY", 8.5*Largeur/100, 38.5*Largeur/100, 33.25*Hauteur/100);

	
}

void dessineQUIT(int Largeur, int Hauteur){

couleurCourante(249, 255, 21);
epaisseurDeTrait(1);
//rectangle(6*Largeur/10, 17*Hauteur/100, 90*Largeur/100, 25*Hauteur/100);
ligne(6*Largeur/10, 17*Hauteur/100,  90*Largeur/100,  17*Hauteur/100);
ligne(6*Largeur/10, 25*Hauteur/100,  90*Largeur/100,  25*Hauteur/100);
ligne(6*Largeur/10, 17*Hauteur/100,  6*Largeur/10,  25*Hauteur/100);
ligne(9*Largeur/10, 17*Hauteur/100,  9*Largeur/10,  25*Hauteur/100);




epaisseurDeTrait(2);
afficheChaine("QUIT", 5.1*Largeur/100, 70*Largeur/100, 19.5*Hauteur/100);
	
}

void dessineTITRE(int Largeur, int Hauteur){
couleurCourante(42, 118,191);


epaisseurDeTrait(5);
couleurCourante(249, 255, 21);
afficheChaine("PAC-BOY", 1*Largeur/10, 25*Largeur/100, 85*Hauteur/100);


	
}

void dessineHIGHSCORE(int Largeur, int Hauteur){

couleurCourante(249, 255, 21);
epaisseurDeTrait(1);
//rectangle(1*Largeur/10, 17*Hauteur/100, 40*Largeur/100, 25*Hauteur/100);
ligne(1*Largeur/10, 17*Hauteur/100, 40*Largeur/100,17*Hauteur/100);
ligne(1*Largeur/10, 25*Hauteur/100, 40*Largeur/100,25*Hauteur/100);
ligne(1*Largeur/10, 17*Hauteur/100, 1*Largeur/10,25*Hauteur/100);
ligne(4*Largeur/10, 17*Hauteur/100, 40*Largeur/100,25*Hauteur/100);

epaisseurDeTrait(2);
afficheChaine("HIGHSCORE", 4.9*Largeur/100, 10.5*Largeur/100, 19.5*Hauteur/100);



}


void fantomeDraw(float x, float y, float taille, int red, int green, int blue){
	couleurCourante(red, green, blue);
	epaisseurDeTrait(taille);
	point(x, y);
	rectangle(x-(taille/2), y, x+(taille/2), y-(taille/2));
	couleurCourante(0,0,0);
	triangle(x-(3*(taille/8)),y-(3*(taille/8)),x-(taille/2),y-(taille/2),x-(taille/4),y-(taille/2));

	triangle(x-(taille/8),y-(3*(taille/8)),x-(taille/4),y-(taille/2),x,y-(taille/2));
	
	triangle(x+(taille/8),y-(3*(taille/8)),x,y-(taille/2),x+(taille/4),y-(taille/2));

	triangle(x+(3*(taille/8)),y-(3*(taille/8)),x+(taille/4),y-(taille/2),x+(taille/2),y-(taille/2));

	couleurCourante(255, 255, 255);
	epaisseurDeTrait(taille/5);
	point(x-(taille/5), y+(taille/5));
	point(x+(taille/5), y+(taille/5));

	couleurCourante(0, 0, 0);
	epaisseurDeTrait(taille/7);
	point(x-(taille/5), y+(taille/5));
	point(x+(taille/5), y+(taille/5));
}




