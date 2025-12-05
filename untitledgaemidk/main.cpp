#ifdef _WIN32
    #include "win32/include/raylib.h"
#else
    #include <raylib.h>
#endif

#define SW 800
#define SH 600
#include <string>

int main(void) {
    int ScreenHeight = GetScreenHeight();
    int ScreenWidth = GetScreenWidth();
    Image img = LoadImage("png.png");
    Image ico = LoadImage("assets/gameicon.png");
    InitWindow(ScreenWidth, ScreenHeight, "UGI version 1.1");
    SetWindowIcon(ico);
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    Vector3 cubepos = { 0.0f, 0.0f, 0.0f };
    Vector3 twocubepos = { 0.7f, 0.0f, 0.0f };
    DisableCursor();
    int cammode = CAMERA_FREE;
    SetTargetFPS(120);
    

    while(!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);
        
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode3D(camera);
        

        DrawCube(cubepos, 2.0f, 1.0f, 1.0f, BLUE);
   //     DrawCircle3D(twocubepos, 2.0f, {1.0f, 0.0f, 0.0f}, 1.0f, RED);
        DrawCubeWires(cubepos, 2.0f, 1.0f, 1.0f, BLUE);
        DrawGrid(15, 1.0f);
        
        if (cammode == CAMERA_FIRST_PERSON) {
            DrawCube(camera.target, 0.5f, 0.5f, 0.5f, RED);
        }


        EndMode3D();
        DrawText("PROTOTYP", 10, 40, 20, GRAY);
        DrawText("Untitled Gaem Idk - Wersja 1.2", 10, 60, 10, GRAY);
        DrawText("Zrobione przez @gruntcom na discordzie", 10, 80, 10, GRAY);
        DrawFPS(10, 10);
        EndDrawing();


    }

    CloseWindow();
    return 0;

}