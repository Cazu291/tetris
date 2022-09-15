#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_thread.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL2/SDL_test_common.h>
#include <time.h>
#include <unistd.h>

static const int width = 800;
static const int height = 600;

int main(int argc, char** argv){
  //initialisation 
    SDL_Init(SDL_INIT_VIDEO);

  //créé la fenêtre
  SDL_Window *window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

  //créé un renderer (ce dans quoi on va tout afficher. il est relié à un "window" bligatoirement
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  bool running = true;
  SDL_Event event;
  
  // différence de tps pour savoir si il faut lancer nouvelle pièce
  //int temps_init_piece = SDL_GetTicks();
  
  
  //lancement de la boucle principale, maintient le jeu lancé
  while(running)
    {
      //if temps
      //tant que tous les évènements ne sont pas traités on les rajoute à un tableau appelé "poll"
      while (SDL_PollEvent(&event))
	{
	  //interprète chaque event dans la poll
	  if (event.type == SDL_QUIT)
	    {
	      running = false;
	    }
	}
      //fait la transition de l'acien etat du renderer au nouvel etat
      SDL_RenderClear(renderer);
      SDL_RenderPresent(renderer);
    }
  
  //close everything
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
