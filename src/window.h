#pragma once

#define WINDOW_NAME "Tetris"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define WINDOW_FPS 60

typedef struct Window
{
	int width;
	int height;
	int fps;
} Window;

extern Window window;	// Window global variable.

void init_window(void);
void close_window(void);
