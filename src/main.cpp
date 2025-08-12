#include "raylib.h"
#include "raymath.h"

#define BACKGROUND_GREEN CLITERAL (Color) {166, 178, 139, 255}
#define OFFWHITE CLITERAL (Color){249, 246, 243, 255}

const int windowHeight = 450;
const int windowWidth = 800;

Vector2 ballPosition = {(float)windowWidth/2, (float)windowHeight/2};
Vector2 ballVelocity = {2, 2};
Vector2 p1Position = {(float)0, (float)windowHeight/2  - 30};
float p1Velocity = 0;
float p2Velocity = 0;
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
  if(pos.y >= windowHeight - 15.0/2)
    vel.y =  -(vel.y);
  if(pos.y <= 15.0/2)
    vel.y =  -(vel.y);
  if(pos.x >= windowWidth - 15.0/2)
      vel.x =  -(vel.x);
  if(pos.x <= 15.0/2)
      vel.x =  -(vel.x);
  
  //if(pos.x <= p1Position.x);

  return vel;
}

Vector2 p1CollisionCheck(Vector2 p1Position, Vector2 pos, Vector2 vel){
  if(pos.x <=  12 + (15.0/2))
  {
    if(pos.y >= p1Position.y && pos.y <= p1Position.y + 60){
      vel.x = -(vel.x);
      vel.y = -(vel.y);
    }
  }
  return vel;
}

Vector2 p2CollisionCheck(Vector2 p2Position, Vector2 pos, Vector2 vel){
  if(pos.x >= windowWidth - 12 - (15.0/2))
  {
    if(pos.y >= p2Position.y && pos.y <= p2Position.y + 60){
      vel.x = -(vel.x);
      vel.y = -(vel.y);
    }
  }
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
    ballVelocity = p1CollisionCheck(p1Position, ballPosition, ballVelocity);
    ballVelocity = p2CollisionCheck(p2Position, ballPosition, ballVelocity);

    ballPosition = Vector2Add(ballPosition, ballVelocity);

    BeginDrawing();
      ClearBackground(BACKGROUND_GREEN);
      DrawText("Let's Play Ping Pong", windowWidth/2 - 100,  windowHeight/2 + 50, 20, OFFWHITE);
      
      DrawCircleV(ballPosition, 15, OFFWHITE);

      p1Position.y = p1Input(p1Position.y);
      p2Position.y = p2Input(p2Position.y);
      DrawRectangleV(p1Position, (Vector2){10, 60}, OFFWHITE);
      DrawRectangleV(p2Position, (Vector2){1, 60}, OFFWHITE);

    EndDrawing();
  }

  
  CloseWindow();

  return 0;
}


