#include "raylib.h"

#define BACKGROUND_GREEN CLITERAL (Color) {166, 178, 139, 255}
#define OFFWHITE CLITERAL (Color){249, 246, 243, 255}

const int windowHeight = 450;
const int windowWidth = 800;


Vector2 ballPosition = {(float)windowWidth/2, (float)windowHeight/2};
Vector2 p1Position = {(float)0, (float)windowHeight/2  - 30};
Vector2 p2Position = {(float)windowWidth - 10, (float)windowHeight/2  - 30};

int p1Input(float posY){
  if(posY >= 5){
    if(IsKeyDown(KEY_W))
      posY -= 2;
  }
  if(posY <= windowHeight - 60){
    if(IsKeyDown(KEY_S))
      posY += 2;
  }
    
  return posY;
}

int p2Input(float posY){
  if(posY >= 5){
    if(IsKeyDown(KEY_UP))
      posY -= 2;
  }
  if(posY <= windowHeight - 60){
    if(IsKeyDown(KEY_DOWN))
      posY += 2;
  }
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

      DrawCircleV(ballPosition, 15, OFFWHITE);

      p1Position.y = p1Input(p1Position.y);
      p2Position.y = p2Input(p2Position.y);
      DrawRectangleV(p1Position, (Vector2){10, 60}, OFFWHITE);
      DrawRectangleV(p2Position, (Vector2){10, 60}, OFFWHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}


