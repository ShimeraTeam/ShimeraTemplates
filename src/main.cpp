#include "raylib.h"
#include "raymath.h"
#include <GL/glew.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Shimeras - Raylib Template");
    // When using Shimera, don't forget to initialize GLEW
    /*if (glewInit() != GLEW_OK)
    {
        CloseWindow();
        return -1;
    }*/

    Camera3D camera = { 0 };
    camera.position = { 10.0f, 6.0f, 10.0f };
    camera.target   = { 0.0f, 0.0f, 0.0f };
    camera.up       = { 0.0f, 1.0f, 0.0f };
    camera.fovy     = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float angle = 0.0f;
    float radius = 10.0f;
    float height = 6.0f;
    float rotationSpeed = 0.5f;

    bool paused = false;

    SetTargetFPS(60);

    // Create a backend

    // Create a framebuffer

    // Create a new instance of EffectPipeline

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            paused = !paused;
        }

        if (!paused)
        {
            angle += rotationSpeed * GetFrameTime();

            camera.position.x = cosf(angle) * radius;
            camera.position.z = sinf(angle) * radius;
            camera.position.y = height;
        }

        // You need to render the scene outside of BeginDrawing()/EndDrawing(), and between the framebuffer bind and unbind calls. Otherwise the shader effects won't be applied to the scene.
        // sceneFramebuffer->clear(shimera::Color{0, 0, 0, 1}); // Don't forget to clear the framebuffer before rendering the scene to it.

        BeginDrawing();
            ClearBackground(GRAY);

            BeginMode3D(camera);

                DrawSphere({ 0.0f, 0.0f, 0.0f }, 2.0f, RED);
                DrawSphereWires({ 0.0f, 0.0f, 0.0f }, 2.0f, 16, 16, BLACK);

            EndMode3D();

            DrawText("ESPACE : pause / reprise", 10, 10, 20, DARKGRAY);
            DrawFPS(screenWidth - 90, 10);

            // Add the EffectPipeline render

        EndDrawing();
    }

    CloseWindow();
    // Don't forget to delete any dynamically allocated resources here if you have any.

    return 0;
}