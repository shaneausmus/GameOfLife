//
// Created by Shane Ausmus on 5/2/20.
//

#include "GameOfLife.h"


GameOfLife::GameOfLife() {
    selectPreset();
}


void GameOfLife::selectPreset() {
    std::cout << "Welcome to the Game of Life!"<< std::endl << std::endl;
    std::cout << "Our preset structures are:"<< std::endl;
    std::cout << "\t0. No preset\n";
    std::cout << "\t1. Glider\n";
    std::cout << "\t2. Spaceship\n";
    std::cout << "\t3. Quadpole\n";
    std::cout << "\t4. Pulsar\n";
    std::cout << "\t5. Figure Eight\n";

    std::cout << std::endl << "Select your game mode:"<< std::endl;

    int userInput;
    std::cin >> userInput;
    while ((userInput != 1) && (userInput != 2) && (userInput != 3) && (userInput != 4) && (userInput != 5)) {
        std::cout << "That is not a valid preset. Please select again." << std::endl;
        std::cin >> userInput;
    }
    std::cout << std::endl;
    init(userInput);
}

void GameOfLife::init(int userInput) {
    for (int row = 0; row < (int)ENV_SIZE; ++row) {
        for (int col = 0; col < (int)ENV_SIZE; ++col) {
            env[row][col] = envCopy[row][col] = ' ';
        }
    }

    std::vector<std::pair<int, int>> arr;
    if (userInput == 0) {
    } else if (userInput == 1) {
        arr = makeGlider();
    } else if (userInput == 2) {
        arr = makeSpaceship();
    } else if (userInput == 3) {
        arr = makeQuadpole();
    } else if (userInput == 4) {
        arr = makePulsar();
    } else {
        arr = makeFigureEight();
    }

    for (auto & i : arr) {
        env[i.first][i.second] = envCopy[i.first][i.second] = '#';
    }

    std::cout << "Are there any spaces you want to be alive? (enter -1, -1 to stop)" << std::endl;
    int userInput1, userInput2;

    std::cout << "Enter in x-coordinate: \n";
    std::cin >> userInput1;
    std::cout << "Enter in y-coordinate: \n";
    std::cin >> userInput2;

    while ((userInput1 >= 0) && ((userInput1 < (int)ENV_SIZE) && (userInput2 >= 0) && (userInput2 < (int)ENV_SIZE))) {
        if (env[userInput1][userInput2] == '#') {
            std::cout << "That space is already alive!\n";
        } else {
            env[userInput1][userInput2] = envCopy[userInput1][userInput2] = '#';
        }

        std::cout << "Enter in another x-coordinate: \n";
        std::cin >> userInput1;
        std::cout << "Enter in another y-coordinate: \n";
        std::cin >> userInput2;

    }


    for (int gen = 0; gen <= 100; ++gen) {
        printEnv();
        updateEnv();
        std::cout << "Generation " << gen << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << std::flush;
    }

}

int GameOfLife::getNeighborCount(int x, int y) {
    size_t count = 0, xTmp, yTmp;
    for (xTmp = x - 1; (int)xTmp <= x + 1; ++xTmp) {
        for (yTmp = y - 1; (int)yTmp <= y + 1; ++yTmp) {
            size_t row = ((xTmp) + ENV_SIZE) % ENV_SIZE;
            size_t col = ((yTmp) + ENV_SIZE) % ENV_SIZE;
            if ((int)row == x && (int)col == y) {
            } else {
                if (env[row][col] == '#') {
                    ++count;
                }
            }
        }
    }
    return count;
}

void GameOfLife::updateEnv() {
    for (int row = 0; row < (int)ENV_SIZE; ++row) {
        for (int col = 0; col < (int) ENV_SIZE; ++col) {
            int numNeighbors = getNeighborCount(row, col); // decides fate of cell
            if (((numNeighbors < 2) || (numNeighbors > 3)) && (env[row][col] == '#')) {
                envCopy[row][col] = ' ';
            } else if ((numNeighbors == 3) || (numNeighbors == 2)) {
                if ((envCopy[row][col] == '#')
                    || ((numNeighbors == 3) && (env[row][col] == ' '))) {
                    envCopy[row][col] = '#';
                }
            }
        }
    }

    for (int row = 0; row < (int)ENV_SIZE; ++row) {
        for (int col = 0; col < (int)ENV_SIZE; ++col) {
            env[row][col] = envCopy[row][col];
        }
    }
}

void GameOfLife::printEnv() {
    for (auto & row : env) {
        std::cout << '|';
        for (char col : row) {
            std::cout << (char)col;
        }
        std::cout << "|\n";
    }
    std::cout << "\n\n";
}

std::vector<std::pair<int, int>> GameOfLife::makeGlider() {
    std::vector<std::pair<int, int>> arr;
    arr.emplace_back(9, 8);
    arr.emplace_back(9, 10);
    arr.emplace_back(10, 9);
    arr.emplace_back(10, 10);
    arr.emplace_back(11, 9);


    return arr;
}

std::vector<std::pair<int, int>> GameOfLife::makeSpaceship() {
    std::vector<std::pair<int, int>> arr;

    arr.emplace_back(9, 7);
    arr.emplace_back(9, 8);
    arr.emplace_back(10, 6);
    arr.emplace_back(10, 7);
    arr.emplace_back(10, 8);
    arr.emplace_back(10, 9);
    arr.emplace_back(11, 6);
    arr.emplace_back(11, 7);
    arr.emplace_back(11, 9);
    arr.emplace_back(11, 10);
    arr.emplace_back(12, 8);
    arr.emplace_back(12, 9);


    return arr;
}

std::vector<std::pair<int, int>> GameOfLife::makeQuadpole() {
    std::vector<std::pair<int, int>> arr;
    arr.emplace_back(7, 7);
    arr.emplace_back(8, 7);
    arr.emplace_back(7, 8);
    arr.emplace_back(8, 9);
    arr.emplace_back(10, 9);
    arr.emplace_back(10, 11);
    arr.emplace_back(12, 11);
    arr.emplace_back(12, 13);
    arr.emplace_back(13, 13);
    arr.emplace_back(13, 12);

    return arr;

}

std::vector<std::pair<int, int>> GameOfLife::makePulsar() {
    std::vector<std::pair<int, int>> arr;

    arr.emplace_back(5, 3);
    arr.emplace_back(6, 3);
    arr.emplace_back(7, 3);
    arr.emplace_back(11, 3);
    arr.emplace_back(12, 3);
    arr.emplace_back(13, 3);
    arr.emplace_back(3, 5);
    arr.emplace_back(8, 5);
    arr.emplace_back(10, 5);
    arr.emplace_back(15, 5);
    arr.emplace_back(3, 6);
    arr.emplace_back(8, 6);
    arr.emplace_back(10, 6);
    arr.emplace_back(15, 6);
    arr.emplace_back(3, 7);
    arr.emplace_back(8, 7);
    arr.emplace_back(10, 7);
    arr.emplace_back(15, 7);
    arr.emplace_back(5, 8);
    arr.emplace_back(6, 8);
    arr.emplace_back(7, 8);
    arr.emplace_back(11, 8);
    arr.emplace_back(12, 8);
    arr.emplace_back(13, 8);
    arr.emplace_back(5, 10);
    arr.emplace_back(6, 10);
    arr.emplace_back(7, 10);
    arr.emplace_back(11, 10);
    arr.emplace_back(12, 10);
    arr.emplace_back(13, 10);
    arr.emplace_back(5, 15);
    arr.emplace_back(6, 15);
    arr.emplace_back(7, 15);
    arr.emplace_back(11, 15);
    arr.emplace_back(12, 15);
    arr.emplace_back(13, 15);
    arr.emplace_back(3, 11);
    arr.emplace_back(8, 11);
    arr.emplace_back(10, 11);
    arr.emplace_back(15, 11);
    arr.emplace_back(3, 12);
    arr.emplace_back(8, 12);
    arr.emplace_back(10, 12);
    arr.emplace_back(15, 12);
    arr.emplace_back(3, 13);
    arr.emplace_back(8, 13);
    arr.emplace_back(10, 13);
    arr.emplace_back(15, 13);

    return arr;

}

std::vector<std::pair<int, int>> GameOfLife::makeFigureEight() {
    std::vector<std::pair<int, int>> arr;
    arr.emplace_back(7, 6);
    arr.emplace_back(8, 6);
    arr.emplace_back(9, 6);
    arr.emplace_back(7, 7);
    arr.emplace_back(8, 7);
    arr.emplace_back(9, 7);
    arr.emplace_back(7, 8);
    arr.emplace_back(8, 8);
    arr.emplace_back(9, 8);
    arr.emplace_back(10, 9);
    arr.emplace_back(11, 9);
    arr.emplace_back(12, 9);
    arr.emplace_back(10, 10);
    arr.emplace_back(11, 10);
    arr.emplace_back(12, 10);
    arr.emplace_back(10, 11);
    arr.emplace_back(11, 11);
    arr.emplace_back(12, 11);

    return arr;

}

