#pragma once

typedef struct Tetromino
{
	int blocks[16];
	
	int x;
	int y;
} Tetromino;

extern const Tetromino tetrominos_reference[7];