// .h necessaires a l'application
#ifndef MES_FONCTIONS_H
#define MES_FONCTIONS_H
#include "GfxLib.h"
#include "ESLib.h"
/* Largeur et hauteur par defaut d'une fenetre correspondant a nos criteres */

/* Les prototypes des fonctions que nous aurons a ecrire */

/**
 * \fn void menu(int Largeur, int Hauteur)
 * \brief affichage graphique du menu principal, avec apparition progressive des éléments
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void menu(int Largeur, int Hauteur);

/**
 * \fn void dessineJOUER(int Largeur, int Hauteur)
 * \brief affichage graphique d'un bouton PLAY
 *
 * \param[in] Largeur:largeur de la fenetre graphique
  * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void dessineJOUER(int Largeur, int Hauteur);

/**
 * \fn void dessineBox(float x1, float x2, float y1, float y2)
 * \brief affichage graphique d'une boite qui fera guise de bouton
 *
 * \param[in] x1:abscisse minimal de la boite
 * \param[in] x2:abscisse maximal de la boite
 * \param[in] y1:ordonnee minimal de la boite
 * \param[in] y2:ordonnee maximal de la boite
 */
void dessineBox(float x1, float x2, float y1, float y2);

/**
 * \fn void dessineTITRE(int Largeur, int Hauteur)
 * \brief affichage graphique du titre du jeu
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void dessineTITRE(int Largeur, int Hauteur);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique du bouton Highscore dans le menu principal
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void dessineHIGHSCORE(int Largeur, int Hauteur);

/**
 * \fn void fantomeDraw(float x, float y, float taille, int red, int green, int blue)
 * \brief affichage graphique d'un fantome dans le menu principal
 *
 * \param[in] x:abscisse
 * \param[in] y:ordonnee
 * \param[in] taille:taille du fantome
 * \param[in] red: taux rgb de rouge
 * \param[in] green: taux rgb de vert
 * \param[in] blue: taux rgb de bleu
 */
void fantomeDraw(float x, float y, float taille, int red, int green, int blue);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique du menu des highscore
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void afficheHighscore(int Largeur, int Hauteur);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique d'un bouton retour
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 * \param[in] y:hauteur du bouton 
 */
void dessineRETOUR(int Largeur, int Hauteur, int y);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique d'un bouton pause dans le menu principal
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void dessinePAUSE(int Largeur, int Hauteur);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique du menu de pause
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void affichePause(int Largeur, int Hauteur);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique du menu de choix de mode de jeu
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void affichePlay(int Largeur, int Hauteur);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique des fantomes pendant les phases de jeu
 *
 * \param[in] x:abscisse 
 * \param[in] y:ordonnee
 * \param[in] dx:abscisse suivante
 * \param[in] dy:ordonnee suivante
 * \param[in] red: taux rgb de rouge
 * \param[in] green: taux rgb de vert
 * \param[in] blue: taux rgb de bleu
 */
void DrawFantome(float x, float y, int dx, int dy, int red, int green, int blue);

/**
 * \fn void dessineHIGHSCORE(int Largeur, int Hauteur)
 * \brief affichage graphique du menu de gameover
 *
 * \param[in] Largeur:largeur de la fenetre graphique
 * \param[in] Hauteur:hauteur de la fenetre graphique
 */
void afficheGameover(int Largeur, int Hauteur, int score);


#endif
