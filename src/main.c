#include <raylib.h>
#include <window.h>
#include <playfield.h>

#include <time.h>

int main()
{
    srand((unsigned)time(NULL));

    init_window();
    init_playfield();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        draw_playfield();
        
        EndDrawing();
    }

    close_window();

    return 0;
}