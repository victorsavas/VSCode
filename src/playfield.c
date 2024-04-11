#include <playfield.h>
#include <window.h>

const int playfield_width = PLAYFIELD_WIDTH;
const int playfield_height = PLAYFIELD_HEIGHT;

const Color tetromino_color[7] = {SKYBLUE, DARKBLUE, ORANGE, YELLOW, GREEN, PURPLE, RED};
Playfield playfield;

// Sets all the cells in the playfield to zero.
void init_playfield(void)
{
	for (int i = 0; i < playfield_width * playfield_height; i++)
		playfield.cells[i] = 0;

	generate_bag(playfield.current_bag);
	generate_bag(playfield.next_bag);
}


void generate_bag(int bag[7])
{
	int options[7] = {0, 1, 2, 3, 4, 5, 6};

	// Shuffle the options array and copy it unto bag[7].

	for (int i = 0; i < 7; i++)
	{
		// Choose one of the avaliable numbers 

		int chosen_index = rand() % (7 - i);

		bag[i] = options[chosen_index];

		// Eliminate the chosen number from the selection

		for (int j = chosen_index; j < 6 - i; j++)
			options[j] = options[j + 1];
	}
}

static int block_size = BLOCK_SIZE;

static Rectangle playfield_rect = {(WINDOW_WIDTH - playfield_width * BLOCK_SIZE) / 2, (WINDOW_HEIGHT - playfield_height * BLOCK_SIZE) / 2, playfield_width * BLOCK_SIZE, playfield_height * BLOCK_SIZE};

// Draws the playfield, bounded by playfield_rect, whose blocks side lengths are block_size.
void draw_playfield(void)
{
	Rectangle block = {playfield_rect.x, playfield_rect.y, block_size, block_size};
	int block_index = 0;

	for (int y = 0; y < playfield_height; y++)
	{
		for (int x = 0; x < playfield_width; x++)
		{
			int color_index = playfield.cells[block_index];

			if (color_index != 0)
				DrawRectangleRec(block, tetromino_color[color_index - 1]);
			
			block.x += block_size;
			block_index++;
		}
	
		block.x = playfield_rect.x;
		block.y += block_size;
	}
}