#include <iostream>

#include "GameOfLife.h"


int main() {

    GameOfLife testGame;
    return 0;
}

/* structure of GoL:
 *
 * menu to start off with presets for different structures (enter different integers
 * to start with different structures
 *
 * allow user to enter in point pairs that are additional 'life' structures
 *
 * GoL rules:
 * 1. Any live cell with fewer than two live neighbours dies (referred to as
 * underpopulation or exposure[1]).
 * 2. Any live cell with more than three live neighbours dies (referred to as
 * overpopulation or overcrowding).
 * 3. Any live cell with two or three live neighbours lives, unchanged, to the next generation
 * 4. Any dead cell with exactly three live neighbours will come to life.
 *
 * if structure goes over brink of graph, have structure pop out the other side
 *
 * Every 10 periods, loop over the grid to see if any cells are still living
 * If there are no living cells, end program
 *
 */

