#include "../h/ESLib.h"
#include "../h/fonctions_menu.h"
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

/* Largeur et hauteur par defaut d'une fenetre correspondant a nos criteres */

void afficheHighscore(int Largeur, int Hauteur) {
    couleurCourante(42, 118, 191);
    epaisseurDeTrait(5);
    couleurCourante(249, 255, 21);
    afficheChaine("HIGHSCORE", 1 * Largeur / 10, 20 * Largeur / 100,
                  85 * Hauteur / 100);
    dessineRETOUR(Largeur, Hauteur);
}

void affiche_menu() {
    sautDeLigne();
    ecrisChaine("*************  TP GRAPHIQUE ******** \n");
    ecrisChaine("taper h	pour afficher ce menu    :\n");
    ecrisChaine("taper r	pour rafraichir la fenêtre graphique    :\n");
    ecrisChaine("taper q	pour  SORTIR de l'APPLICATION  : \n");
    sautDeLigne();
}

void menu(int Largeur, int Hauteur) {
    static int x = 0;
    if (x >= 1600) {
        dessineJOUER(Largeur, Hauteur);
        dessineQUIT(Largeur, Hauteur, 60 * Largeur / 100, 90 * Largeur / 100,
                    17 * Hauteur / 100, 25 * Hauteur / 100);
        epaisseurDeTrait(2);
        afficheChaine("QUIT", 5.1 * Largeur / 100, 70 * Largeur / 100,
                      19.5 * Hauteur / 100);

        dessineTITRE(Largeur, Hauteur);

        dessineHIGHSCORE(Largeur, Hauteur);
    }

    if (x >= 100) {
        fantomeDraw(12 * Largeur / 100,
                    (75 * Hauteur / 100) - 5 * Largeur / 100, 5 * Largeur / 100,
                    255, 20, 20);
        couleurCourante(255, 20, 20);
        epaisseurDeTrait(1);
        x++;
    }

    if (x >= 200) {
        afficheChaine(" - SHADOW", 5 * Largeur / 100, 17 * Largeur / 100,
                      (73.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }
    if (x >= 300) {
        afficheChaine("' BLINKY '", 5 * Largeur / 100, 62 * Largeur / 100,
                      (73.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }

    if (x >= 400) {
        fantomeDraw(12 * Largeur / 100,
                    (68 * Hauteur / 100) - 5 * Largeur / 100, 5 * Largeur / 100,
                    228, 139, 224);

        couleurCourante(228, 139, 224);
        epaisseurDeTrait(1);
        x++;
    }
    if (x >= 500) {
        afficheChaine(" - SPEEDY", 5 * Largeur / 100, 17 * Largeur / 100,
                      (66.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }
    if (x >= 600) {
        afficheChaine("' PINKY '", 5 * Largeur / 100, 62 * Largeur / 100,
                      (66.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }

    if (x >= 700) {
        fantomeDraw(12 * Largeur / 100,
                    (61 * Hauteur / 100) - 5 * Largeur / 100, 5 * Largeur / 100,
                    115, 202, 228);
        couleurCourante(115, 202, 228);
        epaisseurDeTrait(1);
        x++;
    }
    if (x >= 800) {
        afficheChaine(" - BASHFUL", 5 * Largeur / 100, 17 * Largeur / 100,
                      (59.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }
    if (x >= 900) {
        afficheChaine("' INKY '", 5 * Largeur / 100, 62 * Largeur / 100,
                      (59.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }

    if (x >= 1000) {
        fantomeDraw(12 * Largeur / 100,
                    (54 * Hauteur / 100) - 5 * Largeur / 100, 5 * Largeur / 100,
                    255, 192, 27);
        epaisseurDeTrait(1);
        couleurCourante(255, 192, 27);
        x++;
    }
    if (x >= 1100) {
        afficheChaine(" - POKEY", 5 * Largeur / 100, 17 * Largeur / 100,
                      (52.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }
    if (x >= 1200) {
        afficheChaine("' CLYDE '", 5 * Largeur / 100, 62 * Largeur / 100,
                      (52.5 * Hauteur / 100) - 5 * Largeur / 100);
        x++;
    }

    couleurCourante(255, 255, 255);
    afficheChaine(" CHARACTER / NICKNAME", 5 * Largeur / 100,
                  17 * Largeur / 100,
                  (79.5 * Hauteur / 100) - 5 * Largeur / 100);
    if (x >= 1300) {
        afficheChaine("TEAM DRAGON FORCE ALPHAS - TOUS DROITS RESERVES - 2020",
                      2 * Largeur / 100, 11 * Largeur / 100, 5 * Hauteur / 100);
        x++;
    }
    // printf("%i\n",x);
    x++;
}

void dessineJOUER(int Largeur, int Hauteur) {
    couleurCourante(252, 255, 19);
    epaisseurDeTrait(1);
    // rectangle(35*Largeur/100, 32*Hauteur/100, 65*Largeur/100, 4*Hauteur/10);
    ligne(35 * Largeur / 100, 32 * Hauteur / 100, 65 * Largeur / 100,
          32 * Hauteur / 100);
    ligne(65 * Largeur / 100, 32 * Hauteur / 100, 65 * Largeur / 100,
          4 * Hauteur / 10);
    ligne(35 * Largeur / 100, 4 * Hauteur / 10, 65 * Largeur / 100,
          4 * Hauteur / 10);
    ligne(35 * Largeur / 100, 32 * Hauteur / 100, 35 * Largeur / 100,
          4 * Hauteur / 10);

    epaisseurDeTrait(2);
    afficheChaine("PLAY", 8.5 * Largeur / 100, 38.5 * Largeur / 100,
                  33.25 * Hauteur / 100);
}

void dessineTITRE(int Largeur, int Hauteur) {
    couleurCourante(42, 118, 191);

    epaisseurDeTrait(5);
    couleurCourante(249, 255, 21);
    afficheChaine("PAC-BOY", 1 * Largeur / 10, 25 * Largeur / 100,
                  85 * Hauteur / 100);
}

void dessineHIGHSCORE(int Largeur, int Hauteur) {

    couleurCourante(249, 255, 21);
    epaisseurDeTrait(1);
    // rectangle(1*Largeur/10, 17*Hauteur/100, 40*Largeur/100, 25*Hauteur/100);
    ligne(1 * Largeur / 10, 17 * Hauteur / 100, 40 * Largeur / 100,
          17 * Hauteur / 100);
    ligne(1 * Largeur / 10, 25 * Hauteur / 100, 40 * Largeur / 100,
          25 * Hauteur / 100);
    ligne(1 * Largeur / 10, 17 * Hauteur / 100, 1 * Largeur / 10,
          25 * Hauteur / 100);
    ligne(4 * Largeur / 10, 17 * Hauteur / 100, 40 * Largeur / 100,
          25 * Hauteur / 100);

    epaisseurDeTrait(2);
    afficheChaine("HIGHSCORE", 4.9 * Largeur / 100, 10.5 * Largeur / 100,
                  19.5 * Hauteur / 100);
}

void fantomeDraw(float x, float y, float taille, int red, int green, int blue) {
    couleurCourante(red, green, blue);
    epaisseurDeTrait(taille);
    point(x, y);
    rectangle(x - (taille / 2), y, x + (taille / 2), y - (taille / 2));
    couleurCourante(0, 0, 0);
    triangle(x - (3 * (taille / 8)), y - (3 * (taille / 8)), x - (taille / 2),
             y - (taille / 2), x - (taille / 4), y - (taille / 2));

    triangle(x - (taille / 8), y - (3 * (taille / 8)), x - (taille / 4),
             y - (taille / 2), x, y - (taille / 2));

    triangle(x + (taille / 8), y - (3 * (taille / 8)), x, y - (taille / 2),
             x + (taille / 4), y - (taille / 2));

    triangle(x + (3 * (taille / 8)), y - (3 * (taille / 8)), x + (taille / 4),
             y - (taille / 2), x + (taille / 2), y - (taille / 2));

    couleurCourante(255, 255, 255);
    epaisseurDeTrait(taille / 5);
    point(x - (taille / 5), y + (taille / 5));
    point(x + (taille / 5), y + (taille / 5));

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(taille / 7);
    point(x - (taille / 5), y + (taille / 5));
    point(x + (taille / 5), y + (taille / 5));
}

void DrawFantome(float x, float y, int dx, int dy, int red, int green,
                 int blue) {
    int mini = 600;
    int taille = mini / 32;

    dx = (largeurFenetre() - 29 * taille) * dx / 100;
    dy = (hauteurFenetre() - 32 * taille) * dy / 100;

    x += dx + 1 * taille / 2;
    y += dy - 1 * taille / 2;

    taille = mini / 25;

    couleurCourante(red, green, blue);
    epaisseurDeTrait(taille);
    point(x, y);
    rectangle(x - (taille / 2), y, x + (taille / 2), y - (taille / 2));
    couleurCourante(0, 0, 0);
    triangle(x - (3 * (taille / 8)), y - (3 * (taille / 8)), x - (taille / 2),
             y - (taille / 2), x - (taille / 4), y - (taille / 2));

    triangle(x - (taille / 8), y - (3 * (taille / 8)), x - (taille / 4),
             y - (taille / 2), x, y - (taille / 2));

    triangle(x + (taille / 8), y - (3 * (taille / 8)), x, y - (taille / 2),
             x + (taille / 4), y - (taille / 2));

    triangle(x + (3 * (taille / 8)), y - (3 * (taille / 8)), x + (taille / 4),
             y - (taille / 2), x + (taille / 2), y - (taille / 2));

    couleurCourante(255, 255, 255);
    epaisseurDeTrait(taille / 5);
    point(x - (taille / 5), y + (taille / 5));
    point(x + (taille / 5), y + (taille / 5));

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(taille / 7);
    point(x - (taille / 5), y + (taille / 5));
    point(x + (taille / 5), y + (taille / 5));
}

void dessineRETOUR(int Largeur, int Hauteur) {
    couleurCourante(252, 255, 19);
    epaisseurDeTrait(1);

    ligne(35 * Largeur / 100, 15 * Hauteur / 100, 65 * Largeur / 100,
          15 * Hauteur / 100);

    ligne(65 * Largeur / 100, 15 * Hauteur / 100, 65 * Largeur / 100,
          23 * Hauteur / 100);

    ligne(35 * Largeur / 100, 23 * Hauteur / 100, 65 * Largeur / 100,
          23 * Hauteur / 100);

    ligne(35 * Largeur / 100, 15 * Hauteur / 100, 35 * Largeur / 100,
          23 * Hauteur / 100);

    epaisseurDeTrait(2);
    afficheChaine("RETOUR", 6.5 * Largeur / 100, 36.5 * Largeur / 100,
                  17.25 * Hauteur / 100);
}

void dessinePAUSE(int Largeur, int Hauteur) {

    couleurCourante(249, 255, 21);
    epaisseurDeTrait(1);
    // rectangle(6*Largeur/10, 17*Hauteur/100, 90*Largeur/100, 25*Hauteur/100);
    ligne(70 * Largeur / 100, 90 * Hauteur / 100, 90 * Largeur / 100,
          90 * Hauteur / 100);

    ligne(70 * Largeur / 100, 95 * Hauteur / 100, 90 * Largeur / 100,
          95 * Hauteur / 100);

    ligne(70 * Largeur / 100, 90 * Hauteur / 100, 70 * Largeur / 100,
          95 * Hauteur / 100);

    ligne(90 * Largeur / 100, 90 * Hauteur / 100, 90 * Largeur / 100,
          95 * Hauteur / 100);

    epaisseurDeTrait(2);
    afficheChaine("PAUSE", 5.1 * Largeur / 100, 71 * Largeur / 100,
                  91 * Hauteur / 100);
}

void affichePause(int Largeur, int Hauteur) {

    dessineQUIT(Largeur, Hauteur, 35 * Largeur / 100, 65 * Largeur / 100,
                17 * Hauteur / 100, 25 * Hauteur / 100);
    epaisseurDeTrait(2);
    afficheChaine("QUIT", 5.1 * Largeur / 100, 45 * Largeur / 100,
                  19.5 * Hauteur / 100);

    dessineQUIT(Largeur, Hauteur, 30.5 * Largeur / 100, 70.5 * Largeur / 100,
                37 * Hauteur / 100, 45 * Hauteur / 100);
    epaisseurDeTrait(2);
    afficheChaine("REPRENDRE", 5.1 * Largeur / 100, 35 * Largeur / 100,
                  39.5 * Hauteur / 100);

    dessineQUIT(Largeur, Hauteur, 20.5 * Largeur / 100, 80.5 * Largeur / 100,
                57 * Hauteur / 100, 65 * Hauteur / 100);
    epaisseurDeTrait(2);
    afficheChaine("RETOUR AU MENU", 5.1 * Largeur / 100, 25 * Largeur / 100,
                  59.5 * Hauteur / 100);
    afficheChaine("PAUSE", 15.1 * Largeur / 100, 23 * Largeur / 100,
                  79.5 * Hauteur / 100);
}

void dessineQUIT(int Largeur, int Hauteur, float x1, float x2, float y1,
                 float y2) {

    couleurCourante(249, 255, 21);
    epaisseurDeTrait(1);
    // rectangle(6*Largeur/10, 17*Hauteur/100, 90*Largeur/100, 25*Hauteur/100);
    ligne(x1, y1, x2, y1);
    ligne(x1, y2, x2, y2);
    ligne(x1, y1, x1, y2);
    ligne(x2, y1, x2, y2);
}

void afficheGameover(int Largeur, int Hauteur) {
    epaisseurDeTrait(2);
    afficheChaine("GAME OVER", 15.1 * Largeur / 100, 18 * Largeur / 100,
                  79.5 * Hauteur / 100);
}

void JouerSon(char*nom){

    static Mix_Music *musique;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,  MIX_DEFAULT_CHANNELS, 1024); //Initialisation de l'API Mixer
    musique = Mix_LoadMUS(nom);
    Mix_PlayMusic(musique,1);


}

void PauseSon(){
  if(Mix_PausedMusic() == 1)//Si la musique est en pause
    {
        Mix_ResumeMusic(); //Reprendre la musique
    }
    else
    {
        Mix_PauseMusic(); //Mettre en pause la musique
    }
}