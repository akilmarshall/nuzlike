#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#include "data.hxx"
#include "raylib.h"

int main(int argc, char *argv[]) {
    InitWindow(data::width, data::height, "NuzLike");

#if defined(PLATFORM_WEB)
    /* emscripten_set_main_loop(, FPS, 1); */
#else
    SetTargetFPS(data::fps);

    // Main game loop
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(GREEN);
        EndDrawing();
    }
#endif
    // De-Initialization
    CloseWindow();  // Close window and OpenGL context
    return 0;
}
