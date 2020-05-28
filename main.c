#include "h/fonctions_menu.h"
#include "h/mes_fonctions.h"

int main(int argc, char **argv) {

    srand(time(NULL));
    initialiseGfx(argc, argv);
    prepareFenetreGraphique("PAC-BOY", LargeurFenetre, HauteurFenetre);
    lanceBoucleEvenements();

    return 0;
}

void gestionEvenement(EvenementGfx evenement) {
    static int mode = 0;
    static char map[32][29];
    int taille = min(largeurFenetre(), hauteurFenetre()) / 32;
    static Entity pac;
    static Entity fantomes[NB_F];
    static GameStat stat;
    switch (evenement) {
    case Initialisation: {
        //////////////////////////////////
        printf("Initialisation\n");

        FILE *ptrfile = fopen("file/save", "r");
        if (ptrfile != NULL) {
            fscanf(ptrfile, "%d\n", &stat.point);
            fscanf(ptrfile, "%d\n", &stat.vie);
            fscanf(ptrfile, "%d\n", &stat.etat);
            fscanf(ptrfile, "%d\n", &stat.vul);
            fscanf(ptrfile, "%d\n", &stat.pos[0][0]);
            fscanf(ptrfile, "%d\n", &stat.pos[0][1]);
            InitEntity(&pac, stat.pos[0][0], stat.pos[0][1], 4, 0, stat.vie);
            fclose(ptrfile);
            FillMap(map, "file/mapsave");
            printf("\n\n");

        } else {
            FillMap(map, "file/map");
            InitEntity(&pac, 1.5 * taille, 2.5 * taille, 4, 0, 3);
        }

        for (int i = 0; i < NB_F; i++) {

            InitEntity(&fantomes[i], 255, 333, 4, 4, 1);
        }

        demandeAnimation_ips(20);
        ////////////////////////////////////
    } break;
    case Affichage:
        effaceFenetre(0, 0, 0);

        if (mode == 1) {
            Map(map, 50, 50);
            DrawPac(pac.x, pac.y, 50, 50, pac.d);
            DeplacementPac(&pac, map);
            Manger(pac, &stat, taille, map);
            dessinePAUSE(LargeurFenetre, HauteurFenetre);

            AffichageScore(90, 10, stat);
            AfficheVie(5, 10, stat);

            for (size_t i = 0; i < NB_F; i++) {
                if (fantomes[i].state != 0) {
                    if (stat.vul) {
                        DeplacementIAFUITE(&fantomes[i], &pac, map);
                        DrawFantome(fantomes[i].x, fantomes[i].y, 50, 50, 0, 0,
                                    255);
                        fantomes[i].state = VulFantome(pac, fantomes[i]) == 1
                                                ? 0
                                                : fantomes[i].state;
                    } else {
                        switch (i) {
                        case 0:
                            DeplacementIA1(&fantomes[0], &pac, map);
                            DrawFantome(fantomes[i].x, fantomes[i].y, 50, 50,
                                        255, 0, 0);
                            break;
                        case 1:
                            DeplacementIA0(&fantomes[1], &pac, map);
                            DrawFantome(fantomes[i].x, fantomes[i].y, 50, 50, 0,
                                        255, 0);
                            break;
                        case 2:
                            DeplacementIA0(&fantomes[2], &pac, map);
                            DrawFantome(fantomes[i].x, fantomes[i].y, 50, 50,
                                        255, 255, 0);
                            break;
                        case 4:
                            DeplacementIA0(&fantomes[3], &pac, map);
                            DrawFantome(fantomes[i].x, fantomes[i].y, 50, 50, 0,
                                        255, 255);
                            break;

                        default:
                            break;
                        }
                    }
                }
            }

            for (int i = 0; i < NB_F; i++) {
                if (!stat.vul && VulFantome(fantomes[i], pac) == 1) {
                    fantomes[i].x = 255;
                    fantomes[i].y = 333;
                    pac.state--;
                }
            }

            if(pac.state==0){
                system("clear");
                remove("file/save");
                remove("file/mapsave");
                char login2[10];
                printf("\n entre ton pseudo :");
                scanf("%s",login2);
                //saveHighScore(stat,login2); 
                exit(0);
            }

            stat.vie = pac.state;
            stat.pos[0][0] = pac.x;
            stat.pos[0][1] = pac.y;
            /*printf("POINT:%d , VIE:%d , X:%d , Y:%d\n", stat.point, stat.vie,
                       stat.pos[0][0], stat.pos[0][1]);
                       */

        } else if (mode == 2) {
            afficheHighscore(LargeurFenetre, HauteurFenetre);
        }

        else if (mode == 3) {
            affichePause(LargeurFenetre, HauteurFenetre);
        } else if (mode == 0) {
            menu(LargeurFenetre, HauteurFenetre);
        }
        break;

    case Clavier: // Une touche du clavier a ete pressee
        switch (caractereClavier()) {

            break;
        case 'q':
        case 'Q':
            SaveGame(stat, map);
            char login2[10];
            printf("\n entre ton pseudo :");
            scanf("%s",login2);
            saveHighScore(stat,login2);   
            exit(0);
            break;
        case 'k':
        case 'K':
            pac.d = 1;
            break;
        case 'l':
        case 'L':
            pac.d = 2;
            break;
        case 'm':
        case 'M':
            pac.d = 3;
            break;
        case 'o':
        case 'O':
            pac.d = 4;
            break;

            break;
        }
        break;
    case BoutonSouris:
        switch (etatBoutonSouris()) {
        case GaucheAppuye:
            // cas menu début
            if (mode == 0) {

                // Bouton Play appuyé
                if (((abscisseSouris() > 35 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 65 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 32 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 40 * HauteurFenetre / 100))) {
                    mode = 1;
                }

                // Bouton Quit appuyé
                if (((abscisseSouris() > 60 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 90 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 17 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 25 * HauteurFenetre / 100))) {
                    system("clear");
                    remove("file/save");
                    remove("file/mapsave");
                    exit(0);
                }

                // Bouton Highscore appuyé
                if (((abscisseSouris() > 10 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 40 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 17 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 25 * HauteurFenetre / 100))) {
                    mode = 2;
                }
            }

            // cas highscore
            if (mode == 2) {

                // Bouton Retour appuyé
                if (((abscisseSouris() > 35 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 65 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 15 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 23 * HauteurFenetre / 100))) {
                    mode = 0;
                }
            }

            // cas in game
            if (mode == 1) {

                // Bouton Pause appuyé
                if (((abscisseSouris() > 70 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 90 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 90 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 95 * HauteurFenetre / 100))) {
                    mode = 3;
                }
            }

            // cas pause
            if (mode == 3) {

                // Bouton Quit appuyé
                if (((abscisseSouris() > 35 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 65 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 17 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 25 * HauteurFenetre / 100))) {
                    system("clear");
                    remove("file/save");
                    remove("file/mapsave");
                    exit(0);
                }

                // Bouton Reprendre appuyé
                if (((abscisseSouris() > 30.5 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 70.5 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 37 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 45 * HauteurFenetre / 100))) {
                    mode = 1;
                }

                // Bouton Retour menu appuyé
                if (((abscisseSouris() > 20.5 * LargeurFenetre / 100) &&
                     (abscisseSouris() < 80.5 * LargeurFenetre / 100)) &&
                    ((ordonneeSouris() > 57 * HauteurFenetre / 100) &&
                     (ordonneeSouris() < 65 * HauteurFenetre / 100))) {
                    mode = 0;
                }
            }

            break;
        case DroiteAppuye:

            break;
        case GaucheRelache:

            break;
        case DroiteRelache:

            break;
        }
    case Inactivite:
    case Souris:
    case Redimensionnement:
    case ClavierSpecial:
        break;
    }
}
