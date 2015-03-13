#include <ncurses.h>
#include <cstdlib>
#include <fstream>

#include "Screen.h"
#include "Frame.h"
#include "Character.h"
#include "Sense.h"
#include "Monster.h"
#include "Player.h"
#include "Scorecard.h"
#include "Treasure.h"
#include "Directions.h"
#include "BabyMonster.h"

static const int DEFAULT_MONSTERS=10;
static const int DEFAULT_TREASURES=100;
static const int DEFAULT_RSEED=257;

void game_loop(Frame &game_map, Frame &viewport, Character* characters[], int num_chars, Scorecard& score) {
  // character[0] is assumed to be the player

  // Add characters to the game_map
  for (int i=0; i<num_chars; i++) {
    game_map.add(*characters[i]);
  }

  // center on the player
	viewport.center(*characters[0]);
	viewport.refresh();

	while(1) {
    // one game step for all characters
    for (int i=0; i<num_chars; i++) {
      int dir = characters[i]->get_move_logged();
      if (dir == Directions::NONE) {
        // character makes no move
        continue;
      } 
      if (dir == Directions::QUIT) {
        // character forced game over
        return;
      }

      // check collisions
      int nrow, ncol;
      Treasure t;
      game_map.get_new_pos(*characters[i], dir, nrow, ncol);
      char obstruction = game_map.at_position(nrow, ncol);
      if (obstruction == t.symbol()) {
        characters[i]->score(score);
      }

      // move the character
      game_map.char_move(*characters[i], dir);

      // center on the player
      viewport.center(*characters[0]);
      viewport.refresh();
    }
	}
}

// Entry function for game
int main(int argc, char** argv) {
  int num_monsters = DEFAULT_MONSTERS;
  int num_treasures = DEFAULT_TREASURES;
  int seed = DEFAULT_RSEED;
  switch( argc ) {
    case 4:
      seed = atoi(argv[3]);
    case 3:
      num_treasures = atoi(argv[2]);
    case 2:
      num_monsters = atoi(argv[1]);
    case 1:
      break;
    default:
      fprintf(stderr, "usage: [monsters [treasures [rseed]]]\n");
      exit(1);
  }
  srand(seed);

	// Initialize ncurses
	Screen scr;

	// Print a welcome message on screen
	scr.add("Welcome to the RR game.\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

	// Wait until the user press a key
	int ch = getch();

	// Create an ncurses window to store the game map. This will be twice the size
	// of the screen and it will be positioned at (0,0) in screen coordinates
	Frame game_map(2*scr.height(), 2*scr.width(), 0, 0);

	// Create an ncurses subwindow of the game map. This will have the size 
	// of the user screen and it will be initially postioned at (0, 0)
	Frame viewport(game_map, scr.height(), scr.width(), 0, 0);
  
  Character** characters = new Character*[num_monsters+1];

	// Initialize the main character. We are going to put this in the middle of 
	// the game map (for now)
	Player main_char(game_map.height()/2, game_map.width()/2);
  characters[0] = &main_char;
  
  
  // initialize treasures
  Treasure** ts = new Treasure*[num_treasures];
  for (int i=0; i<num_treasures; i++) {
    Treasure* t = new Treasure(rand() % game_map.height(), rand() % game_map.width());
    ts[i] = t;
  }

	// Add a dummy monster to the game (we start with a hard coded monster position 
	// relative to the main character position)
  Sense monster_sense(&game_map);
  for (int i=0; i<num_monsters; i++) { 
    Monster* monster;
    int mrow = rand() % game_map.height();
    int mcol = rand() % game_map.width();
    if (rand() < RAND_MAX/2) {
      monster = new BabyMonster(mrow, mcol, &monster_sense, &main_char);
    } else {
      // prey on player or treasures
      Character* prey;
      if (rand() < RAND_MAX/2) {
        int tid = rand() % num_treasures;
        prey = ts[tid];
      } else {
        prey = &main_char;
      }
      monster = new Monster(mrow, mcol, &monster_sense, prey); 
    }
    characters[i+1] = monster;
  }

	// Fill the game map with lakes, plains, mountains and snow using a Perlin noise function
	game_map.gen_Perlin(seed);

  // add treasures to game map
  for (int i=0; i<num_treasures; i++) {
    game_map.add(*(ts[i]), ts[i]->row(), ts[i]->col());
  }


  // Initialize score
  Scorecard score;
  
  // Check if the user wishes to play the game
	if(ch != 'q' && ch !='Q') {
    // Start the game loop
    game_loop(game_map, viewport, characters, num_monsters+1, score);
  }

  // clean up

  std::ofstream fd;
  fd.open("game.log");
  characters[0]->print_log(fd);
  for (int i=0; i<num_monsters; i++) {
    characters[i+1]->print_log(fd);
    delete characters[i+1];
  }
  fd.close();
  delete[] characters;


  // print score to screen
	scr.add(score.get_score());
  // press any key to quit
  getch();

	return 0;
}
