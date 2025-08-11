#include "raylib.h"

#define BACKGROUND_GREEN CLITERAL (Color) {166, 178, 139, 255}
#define OFFWHITE CLITERAL (Color){249, 246, 243, 255}

const int windowHeight = 450;
const int windowWidth = 800;


Vector2 ballPosition = {(float)windowWidth/2, (float)windowHeight/2};
Vector2 p1Position = {(float)0, (float)windowHeight/2  - 15};

int Input(float posY){
  if(IsKeyDown(KEY_DOWN))
    posY += 2;
  if(IsKeyDown(KEY_UP))
    posY -= 2;
  return posY;
}

int main() {

  InitWindow(windowWidth, windowHeight, "Ping Pong");
  SetTargetFPS(120);

  while(!WindowShouldClose())
  {
    BeginDrawing();
      ClearBackground(BACKGROUND_GREEN);
      DrawText("Let's Play Ping Pong", windowWidth/2 - 100,  windowHeight/2 + 50, 20, OFFWHITE);

      DrawCircleV(ballPosition, 20, OFFWHITE);

      p1Position.y = Input(p1Position.y);
      DrawRectangleV(p1Position, (Vector2){10, 30}, OFFWHITE);
      

    EndDrawing();
  }

  CloseWindow();

  return 0;
}


