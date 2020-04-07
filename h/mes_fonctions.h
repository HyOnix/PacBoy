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

<<<<<<< HEAD
void GenMap();
=======
<<<<<<< Updated upstream


/**
 * \fn void AffichageG(int largeurF,int hauteurF)
 * \brief Permet d'afficher les différents éléments sur la fenêtre 
 *
 * \param[in]  largeurF:largeur de la fenetre voulue.
 * \param[in]  hauteurF:hauteur de la fenetre voulue.
 */
void AffichageG(int largeurF,int hauteurF);

/**
 * \fn void Map(**map, int x,int y)
 * \brief Affiche la carte (Mur + Piece)
 *
 * \param[in] x:position x de la carte sur la map.
 * \param[in] y:position y de la carte sur la map.
 * \param[in] **map:tableau qui contient les données de la map.
 */
void Map(**map, int x,int y);

/**
 * \fn void DrawEntities(list *entities)
 * \brief Permet d'afficher une liste d'entité
 *
 * \param[in] *entities:la liste d'entités a dessiner.
 */
void DrawEntities(list *entities);

/**
 * \fn void DrawPac(entity Pac)
 * \brief Affiche le Pac-Boy
 *
 * \param[in] Pac:l'entité Pac-Boy a dessiner.
 */
void DrawPac(entity Pac);

/**
 * \fn void Tri_Angle(int x, int y, int dir, int ouv, int taille)
 * \brief Dessine un triangle avec une taille et un "angle" particulier
 *
 * \param[in] x:postion x ou dessiner le triangle.
 * \param[in] y:postion y ou dessiner le triangle.
 * \param[in] dir:sens du triangle.
 * \param[in] ouv:valeur de l'angle ou la hauteur arrive .
 * \param[in] taille:hauteur du triangle
 */
void Tri_Angle(int x, int y, int dir, int ouv, int taille);

/**
 * \fn void DrawPhantoms(entity *list)
 * \brief Afficher les Phantoms
 *
 * \param[in] *list:Tableau de variables de type entity.
 */
void DrawPhantoms(entity *list);

/**
 * \fn void DrawPhantoms(entity *list)
 * \brief Afficher les Phantomes
 *
 * \param[in] *list:Tableau de phantomes a dessiner de type entity.
 */
void DrawPhantoms(entity *list);

/**
 * \fn void DrawPhantom(entity list)
 * \brief Afficher le Phantome
 *
 * \param[in] :entité phantome a dessiner.
 */
void DrawPhantom(entity phantome);

/**
 * \fn void DeplacementEntities(entity *list)
 * \brief Fais appel aux fonctions de déplacement des différentes entités 
 *
 * \param[in] *list:Tableau d'entite a dessiner.
 */
void DeplacementEntities(entity *list);

/**
 * \fn void LaunchGame()
 * \brief Lance une partie 
 *
 */
void LaunchGame();

/**
 * \fn void Pac(entity Pac)
 * \brief Déplace Pac-Boy
 *
 * \param[in] pac:entité a deplacer.
 */
void Pac(entity Pac);

/**
 * \fn void FillMap(char *tab)
 * \brief Initialise le tableau de caractère de la carte en lisant un fichier correspondant à la carte
 *
 * \param[in] *tab:tableau qui va etre remplie en accord avec le fichier.
 */
void FillMap(char *tab);

/**
 * \fn void IsOk(int x, int y, int vx, int vy, char *map)
 * \brief Vérifie si le déplacement est possible 
 *
 * \param[in] x:postion x .
 * \param[in] y:postion y .
 * \param[in] vx:vitesse en x.
 * \param[in] vy:vitesse en y.
 * \param[in] *map:tableau qui contient le jeu
 */
void IsOk(int x, int y, int vx, int vy, char *map);

/**
 * \fn void InitStat(GameStats stats, entity *list)
 * \brief Initialise le jeu en fonction des données d'une variable GameStats et des variables de type entity   
 *
 * \param[in] stats:contient les statiques du jeu .
 * \param[in] *list:Tableau d'entite
 */
void InitStat(GameStats stats, entity *list);

/**
 * \fn void InitEntities(entity *list)
 * \brief Initialise les variables de type entity     
 *.
 * \param[in] *list:Tableau d'entite
 */
void InitEntities(entity *list);

/**
 * \fn void Enregistrement(FILE *FileMap, FILE *FileScore, GameStats stats, entity *list )
 * \brief Enregistre dans deux fichiers l'état du jeu, les positions des entités statiques et non statiques       
 *.
 * \param[in] stats:contient les statiques du jeu .
 * \param[in] *list:Tableau d'entite
 * \param[in] *FileScore : FIchier ou enregistrer le score
 * \param[in] FileMap : FIchier ou enregistrer la carte
 */
void Enregistrement(FILE *FileMap, FILE *FileScore, GameStats stats, entity *list );

/**
 * \fn void NewScore(int score, FILE *FileScore)
 * \brief Enregistre dans deux fichiers l'état du jeu, les positions des entités statiques et non statiques       
 *.
 * \param[in] score:le score du joueur.
 * \param[in] *FileScore : Fichier ou enregistrer le score
 */
void NewScore(int score, FILE *FileScore)
=======
void GenMap();
int rand_a_b(int a, int b);
>>>>>>> ab50734d9af911d4bc1a2931f7c6f842e4c16313

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
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
>>>>>>> ab50734d9af911d4bc1a2931f7c6f842e4c16313
