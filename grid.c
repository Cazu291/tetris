#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct piece{
  int* tab;
  int id;
};
  
typedef struct carre carre;
typedef struct piece piece;
  
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
  int*** grid = malloc(sizeof(int**) * 22); //tetris en 10c x 20l, rajoute 1 ligne au dessus au cas où 2e ligne pleine et 1 ligne au dessous pour toujours pouvoir reprendre le pointeur vers 0
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
  printf("\n");

  //affiche le n de ligne
  for (int i=0; i<21; i++){
    printf("%d ", i);
    if (i < 10){
      printf(" ");
    }

    //affiche la valeur en i j
    for (int j=0; j<10; j++){
      printf("%d ", m[i][j][0]);
    }
    printf("\n");
  }
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

void decalle_gauche (piece* p, int*** m){
  int min = 10;
  for (int i = 0; i < 4; i++){
    if (p->tab[2 * i] < min){
      min = p->tab[2*i];
    }
  }
  if (min > 0){
    int* temp = m[p->tab[0]][p->tab[1]];
    for (int i = 0; i < 4; i++){
      m[p->tab[2 * i]][p->tab[2 * i + 1]] = m[21][0];
      p->tab[2 * i + 1] = p->tab[2 * i + 1] - 1;
    }
    for (int i = 0; i < 4; i++){
      m[p->tab[2*i]][p->tab[2*i+1]] = temp;
    }
  }
}

void decalle_droite (piece* p, int*** m){
  int max = 0;
  for (int i = 0; i < 4; i++){
    if (p->tab[2 * i] > max){
      max = p->tab[2*i];
    }
  }
  if (max < 10){
    int* temp = m[p->tab[0]][p->tab[1]];
    for (int i = 0; i < 4; i++){
      m[p->tab[2 * i]][p->tab[2 * i + 1]] = m[21][0];
      p->tab[2 * i + 1] = p->tab[2 * i + 1] + 1;
    }
    for (int i = 0; i < 4; i++){
      m[p->tab[2*i]][p->tab[2*i+1]] = temp;
    }
  }
}

int main(){
  //initialise la grille et affiche son contenu (id des pieces dedans)
  int*** g = grille();
  srand(time(NULL));
  printf("matrice init\n\n");
  print_matrix (g);

  //créé la piece actuelle
  piece* p_actuelle = malloc(sizeof(piece));
  int* coor = malloc(sizeof(int)*8);
  p_actuelle->id = 8;
  p_actuelle->tab = coor;

  //affiche la grille apres l'ajout d'une pièce random
  genere_piece(p_actuelle, g);
  printf("\nmatrice avec nouvelle piece\n\n");
  print_matrix(g);

  //affiche le contenu de la piece actuelle (id, corrdonnées des cases)
  printf("\nid: %d\n", p_actuelle->id);
  printf("case 1: %d %d\n", p_actuelle->tab[0], p_actuelle->tab[1]);
  printf("case 2: %d %d\n", p_actuelle->tab[2], p_actuelle->tab[3]);
  printf("case 3: %d %d\n", p_actuelle->tab[4], p_actuelle->tab[5]);
  printf("case 4: %d %d\n\n", p_actuelle->tab[6], p_actuelle->tab[7]);

  //affiche après avoir descenu une pièce
  for (int i = 0; i < 19; i++){
    descente(p_actuelle, g);
  }
  printf("\nmatrice avec pièce descendue\n\n");
  print_matrix(g);

  printf("\ndescente jusqu'a générer la nouvelle piece et la descendre d'une case\n\n");
  descente(p_actuelle, g);
  descente(p_actuelle, g);
  print_matrix(g);

  printf("\nrotation vers la droite de la pièce avec la place\n\n");
  rotation_droite(p_actuelle, g);
  print_matrix(g);

  printf("\n 3 rotation vers la droite de la pièce\n\n");
  rotation_droite(p_actuelle, g);
  rotation_droite(p_actuelle, g);
  rotation_droite(p_actuelle, g);
  print_matrix(g);
  
  printf("\nrotation vers la gauche de la pièce\n\n");
  rotation_gauche(p_actuelle, g);
  print_matrix(g);

  printf("\ndécallage vers la gauche de la pièce\n\n");
  decalle_gauche(p_actuelle, g);
  print_matrix(g);

  printf("\ndécallage vers la droite de la pièce\n\n");
  decalle_droite(p_actuelle, g);
  print_matrix(g);
}
