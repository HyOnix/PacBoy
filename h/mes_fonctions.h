// .h necessaires a l'application
#include "../h/ESLib.h"
#include "../h/GfxLib.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LargeurFenetre 600
#define HauteurFenetre 800
#define NB_F 4


//structure utile au differentes entité du jeu(Pacboy, fantome)
typedef struct {
    int x;
    int y;
    int v;
    int d;
    int state;
} Entity;

//structure utile pour faire une couleur
typedef struct {
    int red;
    int green;
    int blue;
} Color;

//structure utile pour sauvegarder ou reprendre le jeu
typedef struct {
    int point;
    int vie;
    int etat;
    int vul;
    int pos[NB_F][2];
} GameStat;

//structure utile pour afficher et retrouver les scores dans le fichier highscore
typedef struct {
        int score;
        char* login;
        int classement;
} Score;


/**
 * \fn int SaveMap(char map[32][29])
 * \brief sauvegarde le tableau de jeu dans un fichier
 *
 * \param[in] map:tableau qui contient les données du jeu
 */
int SaveMap(char map[32][29]);

/**
 * \fn void FillMap(char coef[32][29], char *file)
 * \brief Initialise le tableau de caractère de la carte en lisant un fichier correspondant à la carte
 *
 * \param[in] coef:tableau qui va etre remplie en accord avec le fichier.
 * \param[in] file: le fichier qui sert a remplir le tableau.
 */
void FillMap(char coef[32][29], char *file);

/**
 * \fn void Map(char map[32][29], int x,int y)
 * \brief Affiche la carte (Mur + Piece)
 *
 * \param[in] x:position x de la carte sur la map.
 * \param[in] y:position y de la carte sur la map.
 * \param[in] map:tableau qui contient les données de la map.
 */
void Map(char map[32][29], int x, int y);

/**
 * \fn void DrawPac(float x, float y, int dx, int dy, int direction)
 * \brief Affiche le Pac-Boy
 *
 * \param[in] x:position x du pacboy.
 * \param[in] y:position y du pacboy.
 * \param[in] dx:vitesse en x Pac-Boy .
 * \param[in] dy:vitesse en y Pac-Boyr.
 * \param[in] direction:direction du pacboy.
 */
void DrawPac(float x, float y, int dx, int dy, int direction);

/**
 * \fn void Tri_Angle(int x, int y, int direction, int ouverture, int taille)
 * \brief Dessine un triangle avec une taille et un "angle" particulier
 *
 * \param[in] x:postion x ou dessiner le triangle.
 * \param[in] y:postion y ou dessiner le triangle.
 * \param[in] direction:sens du triangle.
 * \param[in] ouverture:valeur de l'angle ou la hauteur arrive .
 * \param[in] taille:hauteur du triangle
 */
void tri_angle(float x, float y, int ouverture, int direction, float taille);

/**
 * \fn void SaveGame(GameStat stat, char map[32][29])
 * \brief sauvegarde dans un fichier les données du joueur
 *
 * \param[in] stat:données du joueur
 * \param[in] map: tableau qui contient les données de la map.
 */
void SaveGame(GameStat stat, char map[32][29]);

/**
 * \fn void saveHighScore(GameStat stat,char * login)
 * \brief sauvegarde dans un fichier le score du joueur (s'il fait partie des 10 meilleurs scores de tout les temps)
 *
 * \param[in] stat:données du joueur
 * \param[in] login: pseudo du joueur
 */
void saveHighScore(GameStat stat,char * login);

/**
 * \fn void GenMap()
 * \brief Genere un fichier texte de carte aleatoire
 */
void GenMap();

/**
 * \fn int min(int a, int b)
 * \brief retourne la valeur mininmu entre deux valeurs 
 *
 * \param[in] a:premiere valeur a comparer
 * \param[in] b:deuxieme valeur a comparer
 *
 * \return la valeur le minimum
 */
int min(int a, int b);

/**
 * \fn void LoadGame(GameStat *stat)
 * \brief lance 
 *
 * \param[in] a:premiere valeur a comparer
 * \param[in] b:deuxieme valeur a comparer
 *
 * \return la valeur le minimum
 */
void LoadGame(GameStat *stat);
void InitEntity(Entity *ent, int x, int y, int v, int d, int s);

void DeplacementIA0(Entity *chasseur, Entity *cible, char coef[32][29]);
void DeplacementIA1(Entity *chasseur, Entity *cible, char coef[32][29]);
void DeplacementIAFUITE(Entity *chasseur, Entity *cible, char coef[32][29]);
void DeplacementPac(Entity *pac, char coef[32][29]);

void arrondiBout(int x, int y, int taille, int orientation);
void arrondiAngle(int x, int y, int taille, int orientation);

void Manger(Entity pac, GameStat *stat, int taille, char coef[32][29]);
int VulFantome(Entity pac, Entity fantome);

void AffichageScore(int x, int y, GameStat stat);
void AfficheVie(int x, int y, GameStat stat);

void cerise(float x, float y, float taille);
void orange(float x, float y, float taille);
void banane(float x, float y, float taille);
void fraise(float x, float y, float taille);
void grain(float x, float y, int coefx, int coefy, float taille, int divx,
           int divy, int fruit);
