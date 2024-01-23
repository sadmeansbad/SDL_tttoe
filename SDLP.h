#include "SDL2/SDL.h"

int field[3][3];
int playerX =  1, playerY = 1, move = 0, symbol = 1;

class SDLDraw{
public:
void Field(SDL_Renderer * renderer){
  SDL_SetRenderDrawColor(renderer, 20,20,20,255);
  SDL_RenderDrawLine(renderer,199, 0, 199, 599);
  SDL_RenderDrawLine(renderer,200, 0, 200, 599);
  SDL_RenderDrawLine(renderer,201, 0, 201, 599);
  SDL_RenderDrawLine(renderer,399, 0, 399, 599);
  SDL_RenderDrawLine(renderer,400, 0, 400, 599);
  SDL_RenderDrawLine(renderer,401, 0, 401, 599);
  SDL_RenderDrawLine(renderer,0,199,599,199);
  SDL_RenderDrawLine(renderer,0,200,599,200);
  SDL_RenderDrawLine(renderer,0,201,599,201);
  SDL_RenderDrawLine(renderer,0,399,599,399);
  SDL_RenderDrawLine(renderer,0,400,599,400);
  SDL_RenderDrawLine(renderer,0,401,599,401);
}

void Cir(SDL_Renderer * renderer, int x, int y){
  SDL_SetRenderDrawColor(renderer, 255,255,255,255);
  SDL_RenderDrawLine(renderer,200*x-100, 200*y-200, 200*x, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x, 200*y-100, 200*x-100, 200*y);
  SDL_RenderDrawLine(renderer,200*x-100, 200*y, 200*x-200, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-200, 200*y-100, 200*x-100, 200*y-200);

  SDL_RenderDrawLine(renderer,200*x-100, 200*y-199, 200*x-1, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-1, 200*y-100, 200*x-100, 200*y-1);
  SDL_RenderDrawLine(renderer,200*x-100, 200*y-1, 200*x-199, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-199, 200*y-100, 200*x-100, 200*y-199);

  SDL_RenderDrawLine(renderer,200*x-100, 200*y-198, 200*x-2, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-2, 200*y-100, 200*x-100, 200*y-2);
  SDL_RenderDrawLine(renderer,200*x-100, 200*y-2, 200*x-198, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-198, 200*y-100, 200*x-100, 200*y-198);

  SDL_RenderDrawLine(renderer,200*x-100, 200*y-197, 200*x-3, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-3, 200*y-100, 200*x-100, 200*y-3);
  SDL_RenderDrawLine(renderer,200*x-100, 200*y-3, 200*x-197, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-197, 200*y-100, 200*x-100, 200*y-197);

  SDL_RenderDrawLine(renderer,200*x-100, 200*y-196, 200*x-4, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-4, 200*y-100, 200*x-100, 200*y-4);
  SDL_RenderDrawLine(renderer,200*x-100, 200*y-4, 200*x-196, 200*y-100);
  SDL_RenderDrawLine(renderer,200*x-196, 200*y-100, 200*x-100, 200*y-196);
}

void Cross(SDL_Renderer * renderer,int x,int y){
  SDL_SetRenderDrawColor(renderer, 255,255,255,255);
  SDL_RenderDrawLine(renderer,200*x-200, 200*y-200, 200*x, 200*y);
  SDL_RenderDrawLine(renderer,200*x, 200*y-200, 200*x-200, 200*y);
}
};
SDLDraw Draw;

void PlayerPointer(SDL_Renderer * renderer, int x, int y){
  SDL_SetRenderDrawColor(renderer, 255,255,0,255);
  SDL_RenderDrawLine(renderer,200*x-200, 200*y-200, 200*x, 200*y-200);
  SDL_RenderDrawLine(renderer,200*x, 200*y-200, 200*x, 200*y);
  SDL_RenderDrawLine(renderer,200*x,200*y, 200*x-200, 200*y);
  SDL_RenderDrawLine(renderer,200*x-200, 200*y, 200*x-200, 200*y-200);
}

void initiation()
{
  move = 0;
  srand(time(NULL));
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            field[y][x] = 0;
        }
    }
}


void DrawPOS(SDL_Renderer * renderer){
  for (int y = 0; y < 3; y++)
  {
      for (int x = 0; x < 3; x++)
      {
          if(field[x][y] == 1){
            Draw.Cir(renderer, x+1, y+1);
          }
          else if(field[x][y]==2){
            Draw.Cross(renderer, x+1, y+1);
          }
      }
  }
}


void bot(int symbol)
{
  int botX, botY;
    do
    {
        botX = rand() % 3;
        botY = rand() % 3;
    } while (field[botY][botX] != 0);
    field[botY][botX] = symbol-1;
}


bool check(int symbol)
{
    if ((field[0][0] == symbol && field[0][1] == symbol && field[0][2] == symbol) ||
        (field[1][0] == symbol && field[1][1] == symbol && field[1][2] == symbol) ||
        (field[2][0] == symbol && field[2][1] == symbol && field[2][2] == symbol) ||
        (field[0][2] == symbol && field[1][1] == symbol && field[2][0] == symbol) ||
        (field[0][0] == symbol && field[1][0] == symbol && field[2][0] == symbol) ||
        (field[0][1] == symbol && field[1][1] == symbol && field[2][1] == symbol) ||
        (field[0][2] == symbol && field[1][2] == symbol && field[2][2] == symbol) ||
        (field[0][0] == symbol && field[1][1] == symbol && field[2][2] == symbol))
    {
        return true;
    }
    else return false;
}
