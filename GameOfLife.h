//
// Created by Shane Ausmus on 5/2/20.
//

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

const size_t ENV_SIZE = 20;

class GameOfLife {
public:
    GameOfLife();
private:
    char env[ENV_SIZE][ENV_SIZE];
    char envCopy[ENV_SIZE ][ENV_SIZE ];

    // called in GameOfLife constructor to enable user to select a preset
    void selectPreset();

    // fills up board based on presets
    void init(int userInput);

    // make a method for each of the different presets that'll load the
    // map w/ int pairs

    int getNeighborCount(int x, int y);

    void updateEnv();

    void printEnv();
    // making preset structures based on returning a pointer to an array
    std::vector<std::pair<int, int>> makeGlider();

    std::vector<std::pair<int, int>> makeSpaceship();

    std::vector<std::pair<int, int>> makeQuadpole();

    std::vector<std::pair<int, int>> makePulsar();

    std::vector<std::pair<int, int>> makeFigureEight();

};


#endif //GAMEOFLIFE_GAMEOFLIFE_H
