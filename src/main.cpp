#include "raylib.h"

#define BACKGROUND_GREEN CLITERAL (Color) {166, 178, 139, 255}
#define OFFWHITE CLITERAL (Color){249, 246, 243, 255}

const int windowHeight = 450;
const int windowWidth = 800;


Vector2 ballPosition = {(float)windowWidth/2, (float)windowHeight/2};
Vector2 ballVelocity = {2, 2};
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

Vector2 CollisionCheck(Vector2 pos, Vector2 vel){
  if(pos.y >= windowHeight - 15/2)
  {
    vel.y =  -(vel.y);
  };
  if(pos.y <= 15/2)
  {
    vel.y =  -(vel.y);
  };

  if(pos.x >= windowWidth - 15/2)
  {
    vel.x =  -(vel.x);
  };
  if(pos.x <= 15/2)
  {
    vel.x =  -(vel.x);
  };
  return vel;
}

int main() {

  InitWindow(windowWidth, windowHeight, "Ping Pong");
  SetTargetFPS(120);

  float dt = 0;

  while(!WindowShouldClose())
  {
    dt = GetFrameTime();

    ballVelocity = CollisionCheck(ballPosition, ballVelocity);

    ballPosition.x +=  ballVelocity.x;
    ballPosition.y +=  ballVelocity.y;

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


