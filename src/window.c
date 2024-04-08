#include <window.h>
#include<raylib.h>

Window window;

// Initializes the window.
void init_window(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	SetTargetFPS(WINDOW_FPS);

	window.width = WINDOW_WIDTH;
	window.height = WINDOW_HEIGHT;
	window.fps = WINDOW_FPS;
}

// Closes the window.
void close_window(void)
{
	CloseWindow();
}