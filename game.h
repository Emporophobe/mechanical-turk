#ifndef _GAME_H_
#define _GAME_H_

#include <string>

class Game
{
private:
    std::string moveList;
    //char currentPlayer; // w or b

public:
    Game(); // TODO: FEN string positions

    void makeMove(std::string);
    std::string getMoves();
    void readInput(std::string);
};

#endif