#pragma once

#include <raylib.h>
#include <tetromino.h>

#include <stdlib.h>

#define PLAYFIELD_WIDTH 10
#define PLAYFIELD_HEIGHT 24

#define BLOCK_SIZE 20

// Data structure which contains the playfield's cells and (will) contain the next pieces sequence.
typedef struct Playfield
{
	int cells[PLAYFIELD_WIDTH * PLAYFIELD_HEIGHT];
	
	int current_bag[7];
	int next_bag[7];

	Tetromino active_tetromino;
	Tetromino hold_tetromino;

} Playfield;

extern const int playfield_width;
extern const int playfield_height;

extern const int playfield_area;

extern const Color tetromino_color[7];
extern Playfield playfield;

void init_playfield(void);

void draw_playfield(void);

void generate_bag(int bag[7]);