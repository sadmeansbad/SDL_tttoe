#include <iostream>
#include <SDL2/SDL.h>
#include "SDLP.h"
#include <time.h>

int bRED=200, bGREEN=200, bBLUE=200;

SDL_Window* window;
SDL_Renderer* renderer;

int main(){
  initiation();
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout<<SDL_GetError();
    return 1;
  }

  window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 601,601, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, 0);

  while(true){
    if(check(2)) {
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      SDL_RenderClear(renderer);
      SDL_RenderPresent(renderer);
      SDL_Delay(1000);
      initiation();
    }
    SDL_Delay(40);
    SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    Draw.Field(renderer);
    Draw.Cir(renderer, 0, 0);
    PlayerPointer(renderer, playerX, playerY);
    DrawPOS(renderer);
    SDL_RenderPresent(renderer);
    SDL_Event event; //start event loop
    if(SDL_PollEvent(&event)){ //handle event
      if(event.type == SDL_KEYDOWN){ //checks if any key is being pressed
        if(event.key.keysym.sym == SDLK_DOWN && playerY!=3){
          playerY++;
        }
        else if(event.key.keysym.sym == SDLK_UP&&playerY!=1){
          playerY--;
        }
        else if(event.key.keysym.sym == SDLK_RIGHT&&playerX!=3){
          playerX++;
        }
        else if(event.key.keysym.sym == SDLK_LEFT&&playerX!=1){
          playerX--;
        }
        else if(event.key.keysym.sym == SDLK_SPACE&&field[playerX-1][playerY-1]==0){
          field[playerX-1][playerY-1] = 1;
          move++;
          if(check(1)){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            initiation();
            }
          else if(move == 9){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            initiation();
          }
          else {
            move++;
            bot(3);
            }
          }

      }
    }
    while(SDL_PollEvent(&event)){ //Closing the app
      if(event.type == SDL_QUIT){
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
