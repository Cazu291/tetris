#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

struct piece{
  int* tab;
  int id;
};

typedef struct piece piece;

void affiche_piece (piece* p){
  for (int i = 0; i < 4; i++){
    printf("i, j: %d, %d\n\r", p->tab[2*i], p->tab[2*i+1]);
  }
}

//genere une nouvelle piece dans la grille 
void genere_piece (piece* p_actuelle, int*** plateau){
  int hasard = rand()%7;
  
  //7 pieces difference de tetris
  if (hasard == 0){

    
    int* p1 = malloc(sizeof(int));
    //si = 0 alors la piece est invisible
    p1[0] = 1;
    
    //ce qui sera dans les infos de p1, infos de la case

    //mettre a jour les données de p_actuelle
    p_actuelle->id = 1;
    //cas particulier de rotation
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 5;
    
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 3;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 4;
    p_actuelle->tab[6] = 1;
    p_actuelle->tab[7] = 6;

    //mettre a jour le plateau
    plateau[1][3] = p1;
    plateau[1][4] = p1;
    plateau[1][5] = p1;
    plateau[1][6] = p1;
    
  } else if (hasard == 1){
    p_actuelle->id = 2;

    int* p2 = malloc(sizeof(int));
    p2[0] = 2;
    
    //piece centrale pour la rotation
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 4;
    
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 3;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 5;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 3;
    plateau[1][3] = p2;
    plateau[1][4] = p2;
    plateau[1][5] = p2;
    plateau[0][3] = p2;
  } else if (hasard == 2){
    p_actuelle->id = 3;

    int* p3 = malloc(sizeof(int));
    p3[0] = 3;
    
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 4;
    
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 3;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 5;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 5;
    plateau[1][3] = p3;
    plateau[1][4] = p3;
    plateau[1][5] = p3;
    plateau[0][5] = p3;
  } else if (hasard == 3){

    int* p4 = malloc(sizeof(int));
    p4[0] = 4;
    
    //cas particulier de rotation
    p_actuelle->id = 4;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 4;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 5;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 4;
    p_actuelle->tab[4] = 0;
    p_actuelle->tab[5] = 5;
    plateau[1][4] = p4;
    plateau[1][5] = p4;
    plateau[0][5] = p4;
    plateau[0][4] = p4;
  } else if (hasard == 4){
    p_actuelle->id = 5;

    int* p5 = malloc(sizeof(int));
    p5[0] = 5;
    
    p_actuelle->tab[0] = 0;
    p_actuelle->tab[1] = 4;
    
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 3;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 4;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 5;
    plateau[1][3] = p5;
    plateau[1][4] = p5;
    plateau[0][5] = p5;
    plateau[0][4] = p5;
  } else if (hasard == 5){
    p_actuelle->id = 6;

    int* p6 = malloc(sizeof(int));
    p6[0] = 6;
    
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 4;
    
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 3;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 5;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 4;
    plateau[1][3] = p6;
    plateau[1][4] = p6;
    plateau[1][5] = p6;
    plateau[0][4] = p6;
  } else if (hasard == 6){
    p_actuelle->id = 7;

    int* p7 = malloc(sizeof(int));
    p7[0] = 7;
    
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 4;
    
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 5;
    p_actuelle->tab[4] = 0;
    p_actuelle->tab[5] = 3;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 4;
    plateau[0][3] = p7;
    plateau[0][4] = p7;
    plateau[1][5] = p7;
    plateau[1][4] = p7;
  }
}

//creation de grille de tetris 10 * 20
int*** grille(){
  int* p = malloc(sizeof(int));
  p[0] = 0;
  int*** grid = malloc(sizeof(int**) * 22); //tetris en 10c x 20l, rajoute 1 ligne au dessus au cas où la 2e ligne est pleine et 1 ligne au dessous pour toujours pouvoir reprendre le pointeur vers 0
  for (int i = 0; i < 22; i++){
    int** c = malloc(sizeof(int*) * 10);
    grid[i] = c;
    for (int j = 0; j < 10; j++){
      grid[i][j] = p;    //tjrs le même pointeur pour une case avec 0, evite de free a chaque fois
    }
  }
  return grid;
}

void print_matrix (int*** m){
  printf("ij ");
  // affiche le n des colonnes
  for (int j=0; j<10; j++){
    printf("%d ", j);
  }
  printf("\n\r");

  //affiche le n de ligne
  for (int i=0; i<21; i++){
    printf("%d ", i);
    if (i < 10){
      printf(" ");
    }

    //affiche la valeur en i j
    for (int j=0; j<10; j++){
      char c = m[i][j][0] == 0? '-' : '0';
      printf("%c ", c);
    }
    printf("\n\r");
  }
}


void percole_bas(piece* p, int*** m, int l){ // descend toutes les lignes au dessus de l de un cran sauf la piece actuelle
  int* temp = m[p->tab[0]][p->tab[1]];
  for (int h = l; h > 0; h--){
    for (int i = 0; i < 10; i++){
      m[h][i] = m[h-1][i];
      m[h-1][i] = m[21][0];
    }
  }
  for (int i = 3; i >= 0; i--){
    m[p->tab[2*i] + 1][p->tab[2*i+1]] = m[21][0];
    m[p->tab[2*i]][p->tab[2*i+1]] = temp;
  }
}

bool ligne_pleine(int*** m, int l){ //verifie si une ligne est remplie
  int total = 0;
  for (int i = 0; i < 10; i++){
    if (*m[l][i] != 0){
      total++;
    }
  }
  return total == 10;
}

void update(piece* p, int*** m, int l){
  if (ligne_pleine(m, l)){
    percole_bas(p, m, l);
  }
  printf("update ligne %d\n\r", l);
}


void descente (piece* p, int*** m){ //fait descendre la piece actuelle 1 fois et si besoin créé une nouvelle pièce
  int total = 0; //fais le total des pièces pouvant être descendues, si tot = 4 alors le tout descend
  for (int i = 0; i < 4; i++){
    int x = p->tab[2*i];
    int y = p->tab[2*i+1];
    if (x < 20){
      if ((m[x+1][y][0] == 0)||(m[x+1][y] == m[x][y])){ // verifie que la piece a la place de descendre
	total++;
      }
    }
  }
  if (total == 4){
    //sauvegarde la precedente valeur
    int* temp = m[p->tab[0]][p->tab[1]];
    //clean la matrice
    m[p->tab[0]][p->tab[1]] = m[21][0];
    m[p->tab[2]][p->tab[3]] = m[21][0];
    m[p->tab[4]][p->tab[5]] = m[21][0];
    m[p->tab[6]][p->tab[7]] = m[21][0];
    //remet la valeur dans les nouvelles cases
    m[p->tab[0] + 1][p->tab[1]] = temp;
    m[p->tab[2] + 1][p->tab[3]] = temp;
    m[p->tab[4] + 1][p->tab[5]] = temp;
    m[p->tab[6] + 1][p->tab[7]] = temp;
    //actualise les coordonnees de p actuelle
    p->tab[0] = p->tab[0] + 1;
    p->tab[2] = p->tab[2] + 1;
    p->tab[4] = p->tab[4] + 1;
    p->tab[6] = p->tab[6] + 1;
  } else {
    int max = 0;
    int min = 20;
    for (int i = 0; i < 4; i++){ // regarde pour quelles lignes il faut vérifier si elle est pleine
      if (p->tab[2*i] > max){
	max = p->tab[2*i];
      } else if (p->tab[2*i] < min){
	min = p->tab[2*i];
      }
    }
    for (int i = max; i < min; i++){
      printf("%d %d\n\r", min, max);
      update(p, m, i); //update toutes les lignes entre la plus haute et la plus basse des lignes
    }
    genere_piece(p, m);
  }
}

void rotation_droite (piece* p, int*** m){

  //enleve la piece temporairement et stocke sa valeur en attendant
  int* temp = m[p->tab[0]][p->tab[1]];
  m[p->tab[0]][p->tab[1]] = m[21][0];
  m[p->tab[2]][p->tab[3]] = m[21][0];
  m[p->tab[4]][p->tab[5]] = m[21][0];
  m[p->tab[6]][p->tab[7]] = m[21][0];

  //garde les valeurs centrales
  int i = p->tab[0];
  int j = p->tab[1];
  if ((p->tab[0] < 20 && p->tab[1] < 9 && p->tab[0] > 0 && p->tab[1] > 0) || (p->id == 1 && p->tab[0] > 1 && p->tab[1] > 1 && p->tab[0] < 20 && p->tab[1] < 9)){
    //si la piece est autre que la barre et le carre alors il lui faut un carré de 3x3 autour de la piece centrale pour tourner, toujours
    //si la piece est la barre alors il lui faut 2 carres libres a gauche et en haut et 1 a droite et en bas
    for (int k = 0; k < 4; k++){
      //calcule la distance entre x et i et y et j
      int dist_x = p->tab[k *2] - i;
      int dist_y = p->tab[k *2 +1] - j;
      //formule trouvée pour tourner la pièce a gauche ou a droite
      if (p->id == 1){
	p->tab[2 *k] = i + dist_y;
	p->tab[2 *k +1] = j + dist_x;
      } else if (p->id != 4){
	p->tab[2 *k] = i + dist_y;
	p->tab[2 *k +1] = j - dist_x;
      }
    }
    for (int k = 0; k < 4; k++){
      m[p->tab[2 *k]][p->tab[2 *k +1]] = m[21][0];
    }
  }
  
  //replace la piece dans le tableau, a sa nouvelle place
  m[p->tab[0]][p->tab[1]] = temp;
  m[p->tab[2]][p->tab[3]] = temp;
  m[p->tab[4]][p->tab[5]] = temp;
  m[p->tab[6]][p->tab[7]] = temp;
}


void rotation_gauche (piece* p, int*** m){

  //enleve la piece temporairement et stocke sa valeur en attendant
  int* temp = m[p->tab[0]][p->tab[1]];
  m[p->tab[0]][p->tab[1]] = m[21][0];
  m[p->tab[2]][p->tab[3]] = m[21][0];
  m[p->tab[4]][p->tab[5]] = m[21][0];
  m[p->tab[6]][p->tab[7]] = m[21][0];
  
  int max_height = 22;
  int max_left = 10;
  bool vertical = true;
  vertical = vertical && (p->tab[1] != p->tab[3]);
    
  for (int i = 0; i < 4; i++){
    if (p->tab[2*i+1]< max_height){
      max_height = p->tab[2*i+1];
    }
    if (max_left < p->tab[2*i]){
      max_left = p->tab[2*i];
    }
  }
  
  //garde les valeurs centrales
  int i;
  int j;
  i = p->tab[0];
  j = p->tab[1];
  // la rotation de la grande barre envoie le carré en trop (la barre ne rentre pas dans un bloc 3x3, un carré sort) soit à gauchedu carré, soit en haut, il faut vérifier que cela ne sort pas du cadre.
  bool b1 = (p->tab[0] < 20 && p->tab[1] < 9 && p->tab[0] > 0 && p->tab[1] > 0) || (p->id == 1 && p->tab[0] > 1 && p->tab[1] > 1 && p->tab[0] < 20 && p->tab[1] < 9); // savoir si la piece peut tourner
  bool b2 = (p->id == 1 && ((vertical && max_left > 1) || (!vertical && max_height > 1))) || (p->id != 1);
  bool peut_tourner;
  if (p->id == 1){
    for (int k = 0; k < 4; k++){
      int dist_x = p->tab[k *2] - i;
      int dist_y = p->tab[k *2 +1] - j;
      // sans ça, le cas de base où la pièce de 4 en longueur est en haut donne dist_y négatif et dist_y + y négatif, donc le programme renvoie une seg fault. D'où on verifie que toutes les valeurs sont > 0
      peut_tourner = peut_tourner && (p->tab[2 *k] > -(i + dist_y));
      peut_tourner = peut_tourner && (p->tab[2 *k +1] > -(j + dist_x));
    }
  }   
  if (b1 && b2 && peut_tourner){
    //si la piece est autre que la barre et le carre alors il lui faut un carré de 3x3 autour de la piece centrale pour tourner, toujours
    //si la piece est la barre alors il lui faut 2 carres libres a gauche et en haut et 1 a droite et en bas
    for (int k = 0; k < 4; k++){
      //calcule la distance entre x et i et y et j
      int dist_x = p->tab[k *2] - i;
      int dist_y = p->tab[k *2 +1] - j;
      //formule trouvée pour tourner la pièce a gauche ou a droite
      if (p->id == 1){
	p->tab[2 *k] = i + dist_y;
	p->tab[2 *k +1] = j + dist_x;
      } else if (p->id != 4){
	p->tab[2 *k] = i - dist_y;
	p->tab[2 *k +1] = j + dist_x;
      }
    }
    for (int k = 0; k < 4; k++){
      m[p->tab[2 *k]][p->tab[2 *k +1]] = m[21][0];
    }
  }
  
  //replace la piece dans le tableau, a sa nouvelle place
  m[p->tab[0]][p->tab[1]] = temp;
  m[p->tab[2]][p->tab[3]] = temp;
  m[p->tab[4]][p->tab[5]] = temp;
  m[p->tab[6]][p->tab[7]] = temp;
}

void decalle_gauche (piece* p, int*** m){ // decalle piece a gauche
  int min = 10;
  for (int i = 0; i < 4; i++){
    if (p->tab[2*i+1] < min){
      min = p->tab[2*i+1];
    }
  }
  if (min > 0){
    int* temp = m[p->tab[0]][p->tab[1]];
    for (int i = 0; i < 4; i++){
      m[p->tab[2*i]][p->tab[2*i+1]] = m[21][0];
      p->tab[2*i+1] = p->tab[2*i+1] - 1;
    }
    for (int i = 0; i < 4; i++){
      m[p->tab[2*i]][p->tab[2*i+1]] = temp;
    }
  }
}

void decalle_droite (piece* p, int*** m){ // decalle piece a droite
  int max = 0;
  for (int i = 0; i < 4; i++){
    if (p->tab[2*i+1] > max){
      max = p->tab[2*i+1]; //verifie si chaque case de la piece peut aller a droite
    }
  }
  if (max < 9){
    int* temp = m[p->tab[0]][p->tab[1]];
    for (int i = 0; i < 4; i++){
      m[p->tab[2*i]][p->tab[2*i+1]] = m[21][0];
      p->tab[2*i+1] = p->tab[2*i+1] + 1;
    }
    for (int i = 0; i < 4; i++){
      m[p->tab[2*i]][p->tab[2*i+1]] = temp;
    }
  }
}

void chute(piece* p, int*** m){ //fait tomber la piece instantannement
  int* temp = m[p->tab[0]][p->tab[1]];
  int max_coor = 0;
  //on efface les pièces du plateau
  for (int i = 0; i < 4; i++){
    m[p->tab[2*i]][p->tab[2*i+1]] = m[21][0];
  }
  int hauteur = 20;
  for (int i = 0; i < 4; i++){
    //on cherche quelle piece est la plus basse (donc de coordonnée maximale)
    if  (p->tab[2*i] > max_coor){
      max_coor = p->tab[2*i];
    }
    //on cherche pour chaque x le plus haut y tel que la case de coordonnées x, y est libre
    int h = 0;
    while (h < 20 && *m[h+1][p->tab[2*i+1]] == 0){
      h++;
    }
    //après avoir calculé le y de chaque x, on cherche le plus petit de tous (le plus haut)
    if (h - p->tab[2*i+1] < hauteur){ // on calcule h - y (si deux pieces peuvent s'imbriquer l'une dans l'autre parfaitement, on peut pas simplement calculer le max et le  min deux deux pieces, sinon il est possible que le x du plus haut de celle du bas ne corresponde pas avec le x du plus bas de celle du haut) (exmple superposer un t et un u, ça marche pas sinon)
      hauteur = h - p->tab[2*i+1];
    }
  }
  int distance = hauteur - max_coor; // la distance entre le pt le plus bas et la plus haute case libre
  for (int i = 0; i < 4; i++){
    p->tab[2*i] = p->tab[2*i] + distance;
    m[p->tab[2*i]][p->tab[2*i+1]] = temp;
  }
}

void entree(piece* p, int*** m, int clavier){
  switch(clavier){
  case 'q':
    decalle_gauche(p, m);
    break;
  case 'd':
    decalle_droite(p, m);
    break;
  case ' ':
    chute(p, m);
    break;
  case 'z':
    rotation_gauche(p, m);
    break;
  case 's':
    descente(p, m);
    break;
  }
  //system("clear");
  print_matrix(m);
}

int max_height(piece* p){
  int max = 0;
  for (int i = 0; i<4; i++){
    if (p->tab[2*i] > max){
      max = p->tab[2*i];
    }
  }
  return max;
}

int main(){
  //initialise la grille et affiche son contenu (id des pieces dedans)
  
  int*** g = grille();
  srand(time(NULL));
  initscr();
  nodelay(stdscr, 1);
  bool game = true;

  //créé la piece actuelle
  piece* p_actuelle = malloc(sizeof(piece));
  int* coor = malloc(sizeof(int)*8);
  p_actuelle->id = 8;
  p_actuelle->tab = coor;

  int new_timer = time(NULL);
  int old_timer = time(NULL);
  char c;

  genere_piece(p_actuelle, g);
  
  while(game){
    c = getch();
    if (c != ERR){
      entree(p_actuelle, g, c);
    }
    new_timer = time(NULL);
    if (new_timer - old_timer > 1){
      old_timer = new_timer;
      descente(p_actuelle, g);
      int l = max_height(p_actuelle);
      update(p_actuelle, g, l);
      //system("clear");
      print_matrix(g);
    }
  }
}
