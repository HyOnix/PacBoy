#include "../h/mes_fonctions.h"
#include <math.h>
#include <time.h>

double vabs(double val) { return val >= 0 ? val : val * -1; }

int rand_a_b(int a, int b)
{
    b++;
    return rand() % (b - a) + a;
}

void GenMap()
{
    FILE *ptrfile = fopen("file/genmap", "w+");
    char coef[32][29];
    // debut
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            coef[i][j] = 'v';
        }
    }
    // debut random
    int direc = 0;
    int y = 0;
    int x = 0;
    int i = 0;

    // au moins un horizontale et un verticale
    x = rand_a_b(3, 11);
    for (int i = 1; i < 15; i++)
    {
        coef[x][i] = '.';
        coef[x + 1][i] = '*';
    }
    y = rand_a_b(3, 11);
    for (int i = 1; i < 15; i++)
    {
        coef[i][y] = '*';
        coef[i][y + 1] = '.';
        coef[1][y] = '.';
    }
    while (i < 2)
    {
        direc = rand_a_b(1, 2);
        switch (direc)
        {
        case 1: // verti

            y = rand_a_b(3, 11);
            for (int i = 1; i < 15; i++)
            {
                coef[i][y] = '*';
                coef[i][y + 1] = '.';
                coef[1][y] = '.';
            }
            break;
        case 2: // hori
            x = rand_a_b(3, 11);
            for (int i = 1; i < 15; i++)
            {
                coef[x][i] = '.';
                coef[x + 1][i] = '*';
            }
            break;
        }

        i++;
    }
    // copie des 1/4

    for (int i = 1; i < 14; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            coef[i][j + 14] = coef[i][j];
        }
    }
    for (int i = 1; i < 14; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            coef[i + 14][j] = coef[i][j];
        }
    }
    for (int i = 1; i < 14; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            coef[i + 14][j + 14] = coef[i][j];
        }
    }

    // bande horizontale tj presente
    for (int i = 0; i < 29; i++)
    {
        coef[14][i] = '.';
        coef[15][i] = '*';
    }
    coef[15][10] = '.';

    // bande verticale tj presente
    for (int i = 0; i < 32; i++)
    {
        coef[i][14] = '*';
        coef[i][15] = '.';
    }
    coef[17][14] = '.';
    coef[1][14] = '.';

    // definition boite a phantome qui ne change pas
    for (int i = 13; i < 17; i++)
    {
        for (int j = 11; j < 18; j++)
        {
            coef[i][j] = '0';
        }
    }
    for (int i = 14; i < 16; i++)
    {
        for (int j = 12; j < 17; j++)
        {
            coef[i][j] = '8';
        }
    }
    coef[16][14] = '8';

    // definition mur qui ne change pas
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            if ((i == 0 || j == 0 || i == 31 || j == 28) &&
                (i != 14 && i != 15))
            {
                coef[i][j] = '0';
            }
        }
    }

    // on finit par emplir tout les murs manquant
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            if (coef[i][j] == 'v')
            {
                coef[i][j] = '0';
            }
        }
    }

    // on copie dans le fichier
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            fprintf(ptrfile, "%c ", coef[i][j]);
        }
        fprintf(ptrfile, "\n");
    }
    fclose(ptrfile);
}

void SaveGame(GameStat stat, char map[32][29])
{
    FILE *ptrfile = fopen("file/save", "w+");
    fprintf(ptrfile, "%d\n", stat.point);
    fprintf(ptrfile, "%d\n", stat.vie);
    fprintf(ptrfile, "%d\n", stat.etat);
    fprintf(ptrfile, "%d\n", stat.vul);
    fprintf(ptrfile, "%d\n", stat.pos[0][0]);
    fprintf(ptrfile, "%d\n", stat.pos[0][1]);
    fclose(ptrfile);
    SaveMap(map);
}

void saveHighScore(GameStat stat, char *login)
{
    Score tab[10];
    memset(&tab, 0x00, sizeof(tab));
    int i = 0;
    char *ptrtok = malloc(10 * sizeof(char));
    char *part = "";
    char *line = NULL;
    size_t len = 0;
    //ssize_t read;

    FILE *ptrfile = fopen("file/highscore", "r");

    if (ptrfile != NULL)
    {
        //lecture fichier et mise dans le tableau
        while (i < 10)
        {
            memset(&line, 0x00, sizeof(line));
            memset(&part, 0x00, sizeof(part));
            getline(&line, &len, ptrfile);

            part = strtok_r(line, ":", &ptrtok);
            tab[i].classement = atoi(part);

            part = strtok_r(NULL, ":", &ptrtok);
            tab[i].login = part;

            part = strtok_r(NULL, ":", &ptrtok);
            part[strlen(part) - 1] = '\0';
            tab[i].score = atoi(part);
            i++;
        }
        fclose(ptrfile);
    }
    int score2look = stat.point;
    for (int d = 0; d < 10; d++)
    {
        if (score2look > tab[d].score)
        {
            for (int i = 9; i >= d; i--)
            {
                tab[i].login = tab[i - 1].login;
                tab[i].score = tab[i - 1].score;
            }
            tab[d].score = score2look * 10;
            tab[d].login = login;
            break;
        }
    }
    FILE *ptrfile2 = fopen("file/highscore", "w+");
    for (int d = 0; d < 10; d++)
    {
        fprintf(ptrfile2, "%i:%s:%i\n", d + 1, tab[d].login, tab[d].score);
    }
    fclose(ptrfile2);
}

int min(int a, int b) { return (a < b) ? a : b; }

void FillMap(char coef[32][29], char *file)
{
    FILE *ptrfile = fopen(file, "r");
    char init;
    // printf("\n\n");
    // system("clear");
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            fscanf(ptrfile, "%c ", &init);
            coef[i][j] = init;
            // printf("%c ", coef[i][j]);
        }
        // printf("\n");
    }
    fclose(ptrfile);
}

void Map(char map[32][29], int x, int y)
{
    Color color;
    color.blue = 255; // rand_a_b(0, 255);
    color.red = 0;    // rand_a_b(0, 255);
    color.green = 0;  // rand_a_b(0, 255);

    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;
    int decx = (largeurFenetre() - 29 * taille) * x / 100;
    int decy = (hauteurFenetre() - 32 * taille) * y / 100;
    int cmp = 0, pos;
    int g = 0, b = 0, h = 0, d = 0;
    int list[4];
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 29; j++)
        {
            cmp = 0;
            g = 0;
            b = 0;
            h = 0;
            d = 0;
            switch (map[i][j])
            {
            case '0':
                if (i + 1 <= 32 && map[i + 1][j] == '0')
                {
                    g = 1;
                }
                if (i - 1 >= 0 && map[i - 1][j] == '0')
                {
                    d = 1;
                }
                if (j + 1 <= 29 && map[i][j + 1] == '0')
                {
                    b = 1;
                }
                if (j - 1 >= 0 && map[i][j - 1] == '0')
                {
                    h = 1;
                }
                // printf("%i\n",cmp);
                list[0] = g;
                list[1] = b;
                list[2] = d;
                list[3] = h;
                cmp = list[0] + list[1] + list[2] + list[3];
                switch (cmp)
                {
                case 1:
                    couleurCourante(color.red, color.green, color.blue);

                    if (g)
                    {
                        arrondiBout(j * taille + decx + taille / 2,
                                    i * taille + decy + taille / 2, taille, 3);
                    }
                    if (d)
                    {
                        arrondiBout(j * taille + decx + taille / 2,
                                    i * taille + decy + taille / 2, taille, 1);
                    }
                    if (h)
                    {
                        arrondiBout(j * taille + decx + taille / 2,
                                    i * taille + decy + taille / 2, taille, 2);
                    }
                    if (b)
                    {
                        arrondiBout(j * taille + decx + taille / 2,
                                    i * taille + decy + taille / 2, taille, 4);
                    }

                    break;
                case 3:
                    // printf("%i\n",cmp);
                    /*couleurCourante(255, 0, 255);
                                  rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                                  couleurCourante(0, 0, 0);
                                  rectangle(j*taille+decx+2,i*taille+decy,(j+1)*taille+decx-2,(i+1)*taille+decy);//+2-2
                       en x pour la verticale et +2-2 en y
                       pour l'horizontale*/
                    for (pos = 0; list[pos] == 2; pos++)
                        ;

                    if (list[(pos + 1) % 4] && list[(pos + 3) % 4])
                    {
                        couleurCourante(color.red, color.green, color.blue);
                        rectangle(j * taille + decx, i * taille + decy,
                                  (j + 1) * taille + decx,
                                  (i + 1) * taille + decy);
                        couleurCourante(0, 0, 0);
                        rectangle(j * taille + decx, i * taille + decy + 2,
                                  (j + 1) * taille + decx,
                                  (i + 1) * taille + decy - 2);
                    }
                    if (list[(pos + 2) % 4] && list[(pos + 4) % 4])
                    {
                        couleurCourante(color.red, color.green, color.blue);
                        rectangle(j * taille + decx, i * taille + decy,
                                  (j + 1) * taille + decx,
                                  (i + 1) * taille + decy);
                        couleurCourante(0, 0, 0);
                        rectangle(j * taille + decx + 2, i * taille + decy,
                                  (j + 1) * taille + decx - 2,
                                  (i + 1) * taille + decy);
                    }

                    break;
                case 2:
                    couleurCourante(color.red, color.green, color.blue);
                    if (map[i + 1][j] == '0' && map[i - 1][j] == '0')
                    {
                        couleurCourante(color.red, color.green, color.blue);
                        rectangle(j * taille + decx, i * taille + decy,
                                  (j + 1) * taille + decx,
                                  (i + 1) * taille + decy);
                        couleurCourante(0, 0, 0);
                        rectangle(j * taille + decx + 2, i * taille + decy,
                                  (j + 1) * taille + decx - 2,
                                  (i + 1) * taille + decy);
                        break;
                    }
                    if (map[i][j + 1] == '0' && map[i][j - 1] == '0')
                    {
                        couleurCourante(color.red, color.green, color.blue);
                        rectangle(j * taille + decx, i * taille + decy,
                                  (j + 1) * taille + decx,
                                  (i + 1) * taille + decy);
                        couleurCourante(0, 0, 0);
                        rectangle(j * taille + decx, i * taille + decy + 2,
                                  (j + 1) * taille + decx,
                                  (i + 1) * taille + decy - 2);
                        break;
                    }

                    for (pos = 0; list[pos] == 1; pos++)
                        ;
                    // printf("%i\n",pos);
                    if (list[(pos + 1) % 4])
                    {
                        switch ((pos + 1) % 4)
                        {
                        case 0:
                            // arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,
                            // 4);
                            break;
                        case 1:

                            arrondiAngle(j * taille + decx + taille / 2,
                                         i * taille + decy + taille / 2, taille,
                                         1);
                            break;
                        case 2:
                            // arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,
                            // 4);
                            break;
                        case 3:
                            // arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,
                            // 2);
                            break;
                        }
                    }
                    if (list[(pos + 3) % 4])
                    {
                        switch ((pos + 3) % 4)
                        {
                        case 0:
                            arrondiAngle(j * taille + decx + taille / 2,
                                         i * taille + decy + taille / 2, taille,
                                         2);
                            break;
                        case 1:
                            arrondiAngle(j * taille + decx + taille / 2,
                                         i * taille + decy + taille / 2, taille,
                                         4);
                            break;
                        case 2:
                            // arrondiAngle(j*taille+decx+taille/2,i*taille+decy+taille/2,taille,
                            // 3);
                            break;
                        case 3:
                            arrondiAngle(j * taille + decx + taille / 2,
                                         i * taille + decy + taille / 2, taille,
                                         3);
                            break;
                        }
                    }

                    break;
                case 0:
                    couleurCourante(255, 255, 255);

                    rectangle(j * taille + decx, i * taille + decy,
                              (j + 1) * taille + decx, (i + 1) * taille + decy);
                    break;
                }
                if (cmp >= 4 || cmp < 0)
                {
                    // printf("%i", cmp);
                    couleurCourante(255, 0, 0);
                    rectangle(j * taille + decx, i * taille + decy,
                              (j + 1) * taille + decx, (i + 1) * taille + decy);

                    for (pos = 0; list[pos] == 1; pos++)
                        ;
                    if (list[(pos + 1) % 4] && list[(pos + 3) % 4])
                    {
                        couleurCourante(0, 0, 0); // changer le test
                        // couleurCourante(0, 255, 255);
                        rectangle(j * taille + decx, i * taille + decy,
                                  (j + 1) * taille + decx,
                                  (i + 1) * taille + decy);
                        couleurCourante(0, 0, 0);
                        rectangle(j * taille + decx + 2, i * taille + decy,
                                  (j + 1) * taille + decx - 2,
                                  (i + 1) * taille + decy);
                    }
                }

                break;
            case '.':
                couleurCourante(150, 150, 150);
                // rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                break;
            case '*':
                couleurCourante(255, 255, 0);
                epaisseurDeTrait(mini / 100);
                point((j + 1) * taille + decx, i * taille + decy);
                // point((j)*taille+decx,i*taille+decy);
                break;
            case '#':
                switch ((j + 1) % 5)
                {

                case 1:
                    cerise((j + 1) * taille + decx, i * taille + decy,
                           mini * 2 / 80);
                    break;

                case 2:
                    fraise((j + 1) * taille + decx, i * taille + decy,
                           mini * 2 / 80);
                    break;
                case 3:
                    banane((j + 1) * taille + decx, i * taille + decy,
                           mini * 2 / 80);
                    break;
                case 4:
                    orange((j + 1) * taille + decx, i * taille + decy,
                           mini * 2 / 80);
                    break;
                }

                break;
            case '-':
                couleurCourante(color.red, color.green, color.blue);
                // rectangle(j*taille+decx,i*taille+decy,(j+1)*taille+decx,(i+1)*taille+decy);
                break;
            }
        }
    }
}

void DrawPac(float x, float y, int dx, int dy, int direction)
{
    int r = 2;
    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;
    static int count = 0;
    static int state = 0;

    dx = (largeurFenetre() - 29 * taille) * dx / 100;
    dy = (hauteurFenetre() - 32 * taille) * dy / 100;

    x += dx + 1 * taille / 2;
    y += dy - 1 * taille / 2;

    taille = mini / 25;
    // dessine le cercle qui est toujours présent
    couleurCourante(249, 255, 21);
    epaisseurDeTrait(taille);
    point(x, y);
    couleurCourante(0, 0, 0);
    taille--;
    switch (count)
    {
    case 0:
        tri_angle(x, y, 8, direction, taille);
        break;

    case 1:
        tri_angle(x, y, 4, direction, taille);
        break;
    case 2:
        tri_angle(x, y, 2, direction, taille);
        break;
    }

    state = (state + 1) % (r * 3);
    count = state / r;
}

void tri_angle(float x, float y, int ouverture, int direction, float taille)
{

    switch (direction)
    {
    case 1: // left
        triangle(x, y, x - (taille / 2), y - (taille / ouverture),
                 x - (taille / 2), y + (taille / ouverture));
        break;

    case 2: // down
        triangle(x, y, x + (taille / ouverture), y - (taille / 2),
                 x - (taille / ouverture), y - (taille / 2));
        break;

    case 3: // right
        triangle(x, y, x + (taille / 2), y + (taille / ouverture),
                 x + (taille / 2), y - (taille / ouverture));
        break;

    case 4: // up
        triangle(x, y, x - (taille / ouverture), y + (taille / 2),
                 x + (taille / ouverture), y + (taille / 2));
        break;
    }
}

void InitEntity(Entity *ent, int x, int y, int v, int d, int s)
{
    ent->x = x;
    ent->y = y;
    ent->v = v;
    ent->d = d;
    ent->state = s;
}

int isOK(int x, int y, char coef[32][29])
{
    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;
    y /= taille;
    x /= taille;
    if (coef[y][x] == ' ' || coef[y][x] == '*' || coef[y][x] == '#' ||
        coef[y][x] == 'o')
    {
        return 1;
        // printf("ok");
    }
    // printf("ERREUR x:%i y:%i %c\n", x,y,coef[y][x]);
    return 0;
}

void DeplacementPac(Entity *pac, char coef[32][29])
{
    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;
    taille = 2 + 5;
    // printf("X= %d , Y=%d\n", pac->x, pac->y);
    switch (pac->d)
    {
    case 1:
    case 3:
        if (pac->x + (pac->d - 2) * (pac->v + taille) <= 0 ||
            pac->x + (pac->d - 2) * (pac->v + taille) >= 495)
        {
            if (pac->x + (pac->d - 2) * (pac->v + taille) <= 0)
            {
                pac->x = 495;
            }
            else
            {
                pac->x = 0;
            }

            // printf("TP\n");
        }
        if (isOK(pac->x + (pac->d - 2) * (pac->v + taille), pac->y, coef))
        {
            pac->x += (pac->d - 2) * (pac->v);
        }
        break;
    case 2:
    case 4:
        if (isOK(pac->x, pac->y + (pac->d - 3) * (pac->v + taille), coef))
        {
            pac->y += (pac->d - 3) * (pac->v);
        }
        break;
    }
}

void DeplacementIA0(Entity *chasseur, Entity *cible, char coef[32][29])
{
    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;
    taille = 2 + 5;
    int test;

    /*
    int dx, dy, distance;

    dx = chasseur->x - cible->x;
    dy = chasseur->y - cible->y;
    distance = sqrt(vabs(dx * dx - dy * dy));
    */

    do
    {
        switch (chasseur->d)
        {
        case 1:
        case 3:
            test =
                isOK(chasseur->x + (chasseur->d - 2) * (chasseur->v + taille),
                     chasseur->y, coef);
            if (test == 1)
            {
                chasseur->x += (chasseur->d - 2) * (chasseur->v);
            }
            else
            {
                chasseur->d = rand_a_b(1, 4);
            }
            break;
        case 2:
        case 4:
            test = isOK(
                chasseur->x,
                chasseur->y + (chasseur->d - 3) * (chasseur->v + taille), coef);
            if (test == 1)
            {
                chasseur->y += (chasseur->d - 3) * (chasseur->v);
            }
            else
            {
                chasseur->d = rand_a_b(1, 4);
            }
            break;
        }

        // printf("{ CHASSEUR X:%d Y:%d }  { CIBLE X:%d Y:%d } DX:%d
        // DY:%d
        // DTOTAL:%d\n", chasseur->x, chasseur->y, cible->x, cible->y,
        // dx, dy,
        // distance);

    } while (test != 1);
}

void DeplacementIA1(Entity *chasseur, Entity *cible, char coef[32][29])
{
    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;
    taille = 2 + 5;
    int test = 0;

    int dx, dy, distance = 0, base = 0;
    dx = chasseur->x - cible->x;
    dy = chasseur->y - cible->y;
    base = sqrt(vabs(dx * dx + dy * dy));
    int direction = chasseur->d;

    for (size_t i = 1; i <= 4; i++)
    {
        if (i % 2)
        {
            test = isOK(chasseur->x + (i - 2) * (chasseur->v + taille),
                        chasseur->y, coef);
            dx = chasseur->x + (i - 2) * (chasseur->v + taille) - cible->x;
        }
        else
        {
            test = isOK(chasseur->x,
                        chasseur->y + (i - 3) * (chasseur->v + taille), coef);
            dy = chasseur->y + (i - 3) * (chasseur->v + taille) - cible->y;
        }

        distance = sqrt(vabs(dx * dx + dy * dy));

        if (distance <= base)
        {
            base = distance;
            if (test)
                direction = i;
        }
    }

    if (direction % 2)
    {
        test = isOK(chasseur->x + (direction - 2) * (chasseur->v + taille),
                    chasseur->y, coef);
    }
    else
    {
        test =
            isOK(chasseur->x,
                 chasseur->y + (direction - 3) * (chasseur->v + taille), coef);
    }

    if (test == 1)
    {

        if (direction % 2)
            chasseur->x += (direction - 2) * (chasseur->v);
        else
            chasseur->y += (direction - 3) * (chasseur->v);

        // printf("%d , %d , %d\n", direction, distance, base);
        chasseur->d = direction;
    }
}

void DeplacementIAFUITE(Entity *chasseur, Entity *cible, char coef[32][29])
{
    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;
    taille = 2 + 5;
    int test = 0;

    int dx, dy, distance = 0, base = 0;
    dx = chasseur->x - cible->x;
    dy = chasseur->y - cible->y;
    base = sqrt(vabs(dx * dx + dy * dy));
    int direction = chasseur->d;

    for (size_t i = 1; i <= 4; i++)
    {
        if (i % 2)
        {
            test = isOK(chasseur->x + (i - 2) * (chasseur->v + taille),
                        chasseur->y, coef);
            dx = chasseur->x + (i - 2) * (chasseur->v + taille) - cible->x;
        }
        else
        {
            test = isOK(chasseur->x,
                        chasseur->y + (i - 3) * (chasseur->v + taille), coef);
            dy = chasseur->y + (i - 3) * (chasseur->v + taille) - cible->y;
        }

        distance = sqrt(vabs(dx * dx + dy * dy));

        if (distance > base)
        {
            base = distance;
            if (test)
                direction = i;
        }
    }

    if (direction % 2)
    {
        test = isOK(chasseur->x + (direction - 2) * (chasseur->v + taille),
                    chasseur->y, coef);
    }
    else
    {
        test =
            isOK(chasseur->x,
                 chasseur->y + (direction - 3) * (chasseur->v + taille), coef);
    }

    if (test == 1)
    {

        if (direction % 2)
            chasseur->x += (direction - 2) * (chasseur->v);
        else
            chasseur->y += (direction - 3) * (chasseur->v);

        // printf("%d , %d , %d\n", direction, distance, base);
        chasseur->d = direction;
    }
}

void AfficheVie(int x, int y, GameStat stat)
{
    char buf[10] = "VIE:";
    epaisseurDeTrait(2);
    int mini = min(largeurFenetre(), hauteurFenetre()) / 20;
    afficheChaine(buf, mini, largeurFenetre() * y / 100,
                  hauteurFenetre() * x / 100);
    sprintf(buf, "%d", stat.vie);
    afficheChaine(buf, mini, 2 * mini + largeurFenetre() * y / 100,
                  hauteurFenetre() * x / 100);
}

void AffichageScore(int x, int y, GameStat stat)
{
    char buf[10] = "SCORE:";
    epaisseurDeTrait(2);
    int mini = min(largeurFenetre(), hauteurFenetre()) / 20;
    afficheChaine(buf, mini, largeurFenetre() * y / 100,
                  hauteurFenetre() * x / 100);
    sprintf(buf, "%d", stat.point * 10);
    afficheChaine(buf, mini, 4 * mini + largeurFenetre() * y / 100,
                  hauteurFenetre() * x / 100);
}

void Manger(Entity pac, GameStat *stat, int taille, char coef[32][29])
{
    static time_t cooldown = 0;
    static time_t valcool;

    if (cooldown != 0)
    {
        if (vabs(difftime(cooldown, time(NULL))) != valcool)
        {
            // printf("%ld\n", valcool);
            valcool = vabs(difftime(cooldown, time(NULL)));
        }

        if (valcool >= 10)
        {
            stat->vul = 0;
            cooldown = 0;
            // printf("C'est FINI\n");
        }
    }

    int mini = min(largeurFenetre(), hauteurFenetre());
    taille = mini / 32;
    int decx = (largeurFenetre() - 29 * taille) * 50 / 100;
    int decy = (hauteurFenetre() - 32 * taille) * 80 / 100;

    int x = ((pac.x) / taille);
    int y = ((pac.y) / taille);

    x *= taille;
    y *= taille;
    x += decx;
    y += decy;

    if (coef[(y - decy) / taille][(x - decx) / taille] == '*')
    {
        coef[(y - decy) / taille][(x - decx) / taille] = 'o';
        stat->point++;
    }
    else if (coef[(y - decy) / taille][(x - decx) / taille] == '#')
    {
        coef[(y - decy) / taille][(x - decx) / taille] = 'o';
        stat->point += 5;
        stat->vul = 1;
        cooldown = time(NULL);
        // printf("C'est MIAM\n");
    }

    couleurCourante(255, 0, 0);
    epaisseurDeTrait(taille);
    // point(x, y);
}

void arrondiBout(int x, int y, int taille, int orientation)
{
    epaisseurDeTrait(taille + 1);
    point(x, y);
    switch (orientation)
    {
    case 1: // haut
        rectangle(x - (taille / 2), y, x + (taille / 2), y - (taille / 2));
        couleurCourante(0, 0, 0);
        rectangle(x - (taille / 2) + 2, y, x + (taille / 2) - 2,
                  y - (taille / 2));
        break;
    case 2: // droit
        couleurCourante(0, 0, 255);
        rectangle(x, y + (taille / 2), x - (taille / 2), y - (taille / 2));
        couleurCourante(0, 0, 0);
        rectangle(x, y + (taille / 2) - 2, x - (taille / 2),
                  y - (taille / 2) + 2);
        break;

    case 3: // bas
        rectangle(x - (taille / 2), y, x + (taille / 2), y + (taille / 2));
        couleurCourante(0, 0, 0);
        rectangle(x - (taille / 2) + 2, y, x + (taille / 2) - 2,
                  y + (taille / 2));
        break;

    case 4: // gauche
        rectangle(x, y - (taille / 2), x + (taille / 2), y + (taille / 2));
        couleurCourante(0, 0, 0);
        rectangle(x, y - (taille / 2) + 2, x + (taille / 2),
                  y + (taille / 2) - 2);
        break;
    }
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(taille - 3);
    point(x, y);
}

void arrondiAngle(int x, int y, int taille, int orientation)
{
    epaisseurDeTrait(taille + 1);
    point(x, y);
    switch (orientation)
    {
    case 1:
        // bas/gauche
        rectangle(x, y - (taille / 2), x + (taille / 2),
                  y + (taille / 2));                         // horizontale
        rectangle(x, y - (taille / 2), x - (taille / 2), y); // verticlae
        couleurCourante(0, 0, 0);
        rectangle(x, y - (taille / 2) + 2, x + (taille / 2),
                  y + (taille / 2) - 2);
        rectangle(x - (taille / 2) + 2, y, x + (taille / 2) - 2,
                  y - (taille / 2) - 2); // bas

        break;

    case 2:
        // haut/gauche
        rectangle(x, y + (taille / 2), x - (taille / 2), y - (taille / 2));
        rectangle(x, y + (taille / 2), x + (taille / 2), y);
        couleurCourante(0, 0, 0);
        rectangle(x - (taille / 2) + 2, y, x + (taille / 2) - 2,
                  y + (taille / 2));
        rectangle(x, y + (taille / 2) - 2, x - (taille / 2) - 2,
                  y - (taille / 2) + 2);

        break;

    case 3:
        // bas/droite
        rectangle(x, y - (taille / 2), x + (taille / 2), y);
        rectangle(x, y - (taille / 2), x - (taille / 2), y + (taille / 2));
        couleurCourante(0, 0, 0);
        rectangle(x - (taille / 2) + 2, y, x + (taille / 2) - 2,
                  y - (taille / 2));
        rectangle(x, y + (taille / 2) - 2, x - (taille / 2) - 2,
                  y - (taille / 2) + 2);
        break;

    case 4:
        // droite/haut
        rectangle(x, y + (taille / 2), x + (taille / 2), y - (taille / 2));
        rectangle(x, y + (taille / 2), x - (taille / 2), y);
        couleurCourante(0, 0, 0);
        rectangle(x - (taille / 2) + 2, y, x + (taille / 2) - 2,
                  y + (taille / 2)); // haut
        rectangle(x, y - (taille / 2) + 2, x + (taille / 2),
                  y + (taille / 2) - 2);

        break;
    }
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(taille - 3);
    point(x, y);
}

int VulFantome(Entity pac, Entity fantome)
{
    int dx, dy;
    double distance;

    int mini = min(largeurFenetre(), hauteurFenetre());
    int taille = mini / 32;

    dx = fantome.x - pac.x;
    dy = fantome.y - pac.y;
    distance = sqrt(vabs(dx * dx + dy * dy));
    if (distance < taille)
    {
        // memset(&fantomes[NB_F], 0, sizeof(fantomes[0]));
        printf("miam fantome\n");
        printf("DX: %d , DY: %d , DISTANCE : %f\n", dx, dy, distance);
        return 1;
    }

    return 0;
    // printf("{ CHASSEUR X:%d Y:%d }  { CIBLE X:%d Y:%d } DX:%d DY:%d
    // DTOTAL:%d\n", chasseur->x, chasseur->y, cible->x, cible->y, dx, dy,
    // distance);
}

int SaveMap(char map[32][29])
{
    FILE *ptrfile = fopen("file/mapsave", "w+");
    if (ptrfile != NULL)
    {
        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < 29; j++)
            {
                fprintf(ptrfile, "%c ", map[i][j]);
            }
            fprintf(ptrfile, "\n");
        }
        fclose(ptrfile);
        return 1;
    }
    return 0;
}

void cerise(float x, float y, float taille)
{
    // utiliser switch pour les bonus suivant le niveau
    couleurCourante(255, 0, 0);
    epaisseurDeTrait(taille / 2);
    point(x - 3 * (taille / 8), y - (taille / 8));
    point(x + (taille / 8), y - 3 * (taille / 8));

    couleurCourante(200, 163, 72);
    epaisseurDeTrait(taille / 18);
    ligne(x - (taille / 4), y, x + 3 * (taille / 8), y + 3 * taille / 8);
    ligne(x + (taille / 8), y - (taille / 4), x + 3 * (taille / 8),
          y + 3 * taille / 8);

    couleurCourante(8, 184, 0);
    rectangle(x + (taille / 4), y + (taille / 2), x + (taille / 2),
              y + 3 * (taille / 8));
    rectangle(x + (taille / 2), y + 3 * (taille / 8), x + 3 * (taille / 8),
              y + (taille / 4));
}
void orange(float x, float y, float taille)
{
    couleurCourante(238, 156, 12);
    epaisseurDeTrait(taille * 0.95);
    point(x, y);

    couleurCourante(233, 170, 60);
    rectangle(x - taille / 4, y, x - taille / 8, y + taille / 8);

    couleurCourante(10, 230, 20);
    rectangle(x - taille / 8, y + taille / 4, x + taille / 8,
              y + 3 * taille / 8);
    rectangle(x - taille / 8, y + 3 * taille / 8, x + taille / 4,
              y + taille / 2);
}
void banane(float x, float y, float taille)
{
    couleurCourante(244, 237, 10);
    epaisseurDeTrait(taille * 0.95);
    point(x - taille / 8, y - taille / 8);

    couleurCourante(0, 0, 0);
    epaisseurDeTrait(taille);
    point(x + taille / 8, y + taille / 8);

    couleurCourante(10, 230, 20);
    rectangle(x - taille / 4, y + taille / 8, x - 4 * taille / 8,
              y + 3 * taille / 8);
}
void grain(float x, float y, int coefx, int coefy, float taille, int divx,
           int divy, int fruit)
{

    int redExt, greenExt, blueExt, redInt, greenInt, blueInt, epaisInt;
    float epaisExt;

    if (fruit == 1)
    {
        // raisin
        redExt = 185;
        greenExt = 18;
        blueExt = 234;
        redInt = 195;
        greenInt = 70;
        blueInt = 233;
        epaisExt = 1.5;
        epaisInt = 2;
    }
    else if (fruit == 2)
    {
        // fraise
        redExt = 255;
        greenExt = 20;
        blueExt = 20;
        redInt = 0;
        greenInt = 0;
        blueInt = 0;
        epaisExt = 2;
        epaisInt = 19;
    }
    couleurCourante(redExt, greenExt, blueExt); // couleur exterieur
    epaisseurDeTrait(taille / epaisExt);
    point(x + coefx * (taille / divx), y + coefy * (taille / divy));
    couleurCourante(redInt, greenInt, blueInt); // couleur intérieur
    epaisseurDeTrait(taille / epaisInt);
    point(x + coefx * (taille / divx), y + coefy * (taille / divy));
}

void fraise(float x, float y, float taille)
{

    grain(x, y, -1, -3, taille, 8, 8, 2);  // 3
    grain(x, y, -1, -1, taille, 4, 8, 2);  // 2
    grain(x, y, -3, 1, taille, 8, 8, 2);   // 1
    grain(x, y, -2, 1, taille, 16, 16, 2); // 6

    grain(x, y, 1, -1, taille, 16, 8, 2); // 4
    grain(x, y, 1, 0, taille, 4, 1, 2);   // 5

    couleurCourante(20, 230, 20);
    triangle(x, y + taille / 4, x + taille / 4, y + taille / 4,
             x + 3 * (taille / 8), y + 3 * (taille / 8));
    triangle(x, y + taille / 4, x + taille / 4, y + taille / 4,
             x - 2 * (taille / 8), y + 2 * (taille / 4));
}
