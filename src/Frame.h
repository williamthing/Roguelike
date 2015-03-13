
#ifndef FRAME_H
#define FRAME_H
#include <ncurses.h>

class Character;

class Frame {
	// Frame dimensions
	int _height, _width;
	// Frame position
	int _row, _col;
	// Boolean - FALSE for a window and TRUE for a subwindow (viewport)
	bool _has_super;
	// Pointer to an ncurses WINDOW
	WINDOW *_w;
	// Pointer to an ncurses WINDOW, this will be NULL for a window and will point to the parent window
	// for a subwindow
	WINDOW *_super;
public:
	// Get the window
	WINDOW *win() const;
	// Get the parent window
	WINDOW *super() const;
	// Initialize a main window (no parent)
	Frame(int nr_rows, int nr_cols, int row_0, int col_0);
	// Initialize a subwindow (viewport) with a parent window
	Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0);
	~Frame();
	// Get window type, if TRUE we have a subwindow, if FALSE we have a main window
	bool has_super() const;
	// Get the height of the window
	int height() const;
	// Get the width of the window
	int width() const;
	// Get the row (y) position of the window
	int row() const;
	// Get the row (y) position of the window
	int col() const;
	// Fill a window with numbers - the window is split in four equal regions,
	// each region is filled with a single number, so 4 regions and 4 numbers.
	// This is a suggestion of how this will look:
	//         0 | 1
	//         -----
	//         2 | 3 
	// This function is used only for debugging purposes.	
	void fill_window();
	// Refresh the window
	void refresh();
	// Move a window in a new position (r, c)
	void move(int r, int c);
	// Add a character to the window
	void add(Character &x);
	// Define the "erase" character, use an empty character for cleaning a cell or a
	// visible character for showing the trace of a game character	
	void erase(Character &x);
	// Add a character at a specific position to the window
	void add(Character &x, int row_0, int col_0);
	// Center the viewport around a character
	void center(const Character &x);
	// Generate a game map using a Perlin noise function
	void gen_Perlin(const unsigned int &seed);
	// Check if the target position is free
	bool target_position(int row_0, int col_0) const;	
  // Get the element at the target position
  char at_position(int row_0, int col_0) const;

  void char_move(Character& c, int dir);
  void get_new_pos(const Character& c, int dir, int& row, int& col) const;
};

#endif
