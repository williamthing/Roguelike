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
