#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct piece{
  int* tab;
  int* id;
};
  
typedef struct carre carre;
typedef struct piece piece;
  
//genere une nouvelle piece dans la grille 
void genere_piece (piece* p_actuelle, int*** plateau){
  int hasard = rand()%7;

  //7 pieces difference de tetris
  if (hasard == 0){

    //ce qui sera dans les infos de p1, infos de la case
    int* p1 = malloc(sizeof(int));
    // dans aucun cas mettre p[0] = 0 sinon la piece est simplement invisible
    p1[0] = 1;

    //mettre a jour les données de p_actuelle
    p_actuelle->id[0] = 1;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 3;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 4;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 5;
    p_actuelle->tab[6] = 1;
    p_actuelle->tab[7] = 6;

    //mettre a jour le plateau
    plateau[1][3] = p1;
    plateau[1][4] = p1;
    plateau[1][5] = p1;
    plateau[1][6] = p1;
    
  } else if (hasard == 1){
    int* p2 = malloc(sizeof(int));
    p2[0] = 2;
    p_actuelle->id[0] = 2;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 3;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 4;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 5;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 3;
    plateau[1][3] = p2;
    plateau[1][4] = p2;
    plateau[1][5] = p2;
    plateau[0][3] = p2;
  } else if (hasard == 2){
    int* p3 = malloc(sizeof(int));
    p3[0] = 3;
    p_actuelle->id[0] = 3;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 3;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 4;
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
    p_actuelle->id[0] = 4;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 4;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 5;
    p_actuelle->tab[4] = 0;
    p_actuelle->tab[5] = 5;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 4;
    plateau[1][4] = p4;
    plateau[1][5] = p4;
    plateau[0][5] = p4;
    plateau[0][4] = p4;
  } else if (hasard == 4){
    int* p5 = malloc(sizeof(int));
    p5[0] = 5;
    p_actuelle->id[0] = 5;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 3;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 4;
    p_actuelle->tab[4] = 0;
    p_actuelle->tab[5] = 4;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 5;
    plateau[1][3] = p5;
    plateau[1][4] = p5;
    plateau[0][5] = p5;
    plateau[0][4] = p5;
  } else if (hasard == 5){
    int* p6 = malloc(sizeof(int));
    p6[0] = 6;
    p_actuelle->id[0] = 6;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 3;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 4;
    p_actuelle->tab[4] = 1;
    p_actuelle->tab[5] = 5;
    p_actuelle->tab[6] = 0;
    p_actuelle->tab[7] = 4;
    plateau[1][3] = p6;
    plateau[1][4] = p6;
    plateau[1][5] = p6;
    plateau[0][4] = p6;
  } else if (hasard == 6){
    int* p7 = malloc(sizeof(int));
    p7[0] = 7;
    p_actuelle->id[0] = 7;
    p_actuelle->tab[0] = 1;
    p_actuelle->tab[1] = 5;
    p_actuelle->tab[2] = 1;
    p_actuelle->tab[3] = 4;
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
  int*** grid = malloc(sizeof(int**) * 21); //tetris en 10c x 20l, rajoute 1 ligne au cas ou 2e ligne pleine
  for (int i = 0; i < 21; i++){
    int** c = malloc(sizeof(int*) * 10);
    grid[i] = c;
    for (int j = 0; j < 10; j++){
      int* p = malloc(sizeof(int));
      p[0] = 0;
      grid[i][j] = p;
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
      if ((m[x+1][y][0] == 0)||(m[x+1][y] == m[x][y])){
	total++;
      }
    }
  }
  if (total == 4){
      for (int i = 0; i<4; i++){
	int x = p->tab[2*i];
	int y = p->tab[2*i+1];
	m[x+1][y] = m[x][y];
	p->tab[2*i] = x + 1;
	int* c = malloc(sizeof(int));
	c[0] = 0;
	m[x][y] = c;
      }
  } else {
    genere_piece(p, m);
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
  int* identifiant = malloc(sizeof(int));
  p_actuelle->id = identifiant;
  p_actuelle->tab = coor;

  //affiche la grille apres l'ajout d'une pièce random
  genere_piece(p_actuelle, g);
  printf("\nmatrice avec nouvelle piece\n\n");
  print_matrix(g);

  //affiche le contenu de la piece actuelle (id, corrdonnées des cases)
  printf("\nid: %d\n", p_actuelle->id[0]);
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

  printf("\ndescente jusqu'a bloquer la piece\n\n");
  descente(p_actuelle, g);
  print_matrix(g);
}
