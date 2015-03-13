
CSE 374, Winter 2015, HW7
--------------------------
__Due: Thursday, March 12, 2015, 11pm__

Synopsis
========
In this assignment you will supply the implementation of pieces of a C++ turn-based map game. You should do this assignment alone. We will supply you with most of the game engine. You can use this to experiment with and test your implementation. But your only job is to implement the pieces specified below.

Running rgame
=============
```bash
make
./rgame [num_monsters [num_treasures [rand seed]]]
```
The game is a 2D map of cells, where each cell is:
* @ player (controlled by arrow keys)
* M monster
* $ treasure
* . plains (characters can walk on it)
* #, S, ~ (terrain that characters cannot walk on)

The game is quit by pressing 'q' or 'Q', then scores are printed. The score is equal to the number of treasures captured.

Monsters will chase the player and treasure. Both the player and monsters can collect treasures.

After finishing the assignment the game will run, but it is a very rudimentary game. For example, when the player gets eaten by a monster, the game does not stop.

The code
========
* Frame.h: defines the game board. You just need to inspect this to do part 1.
* rgame.cpp: Main game loop. You don't need to understand most of this file, but you must fix it in part 1 and inspect it for one question in part 3.
* Directions.h: defines the four directions characters can move
* Character.h: declares the Character class, from which Player, Monster, and Treasure are derived.
* Scorecard.h: declares the Scorecard class, which keeps track of scores.
* BabyMonster.{h,cpp}: skeleton class that you must fill in
  
1. Lines 25, 29, 48, 55, 58 in rgame.cpp are all passing a character to a Frame method. They all have the same bug. Fix those lines.

2. Make a version of the Monster, called BabyMonster, that has symbol 'm' and moves at half the speed (once every two times get_move is called). BabyMonster should be a derived class of Monster and have as little code duplication as possible. Once you implement this class you should be able to compile and run the program.

3. Answer the following questions about the code in a file called answers.txt:
  1. What is the difference between the _pure_ virtual functions Character::get_move/Character::symbol and the virtual function Character::score?
  2. Describe how the get_move() method of Player/Monster/BabyMonster gets called during the game loop.
  3. Why could Character::get_move not be a const method (hint: inspect each of the classes derived directly or indirectly from Character.
  4. Why is the destructor for Character class defined explicitly in our code? 
  5. Why didn't BabyMonster class have to override the destructor from Character?

Submission instructions
=======================
You should upload exactly 1 file to the HW7 catalyst dropbox.
* keep all your files in the base directory and run `make build-submit`
* This creates a tar file hw7-soln.tar for you to upload.

The hw7-soln.tar file contains the following:
* rgame.cpp (with your modifications in part 1)
* BabyMonster.h (filled in part 2)
* BabyMonster.cpp (filled in part 2)
* answers.txt (filled in part 3)
