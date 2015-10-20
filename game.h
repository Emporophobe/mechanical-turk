#ifndef _GAME_H_
#define _GAME_H_

#include "sfio.h"

#include <string>

class Game
{
public:
    Game(); 
    
    // TODO: constructor for FEN string positions

    // TODO: validate moves, find checks/checkmates

    void makeMove(const std::string &move); // add a move to the movelist and get a response

    void readUserInput(); // main loop for shell-type user interface

private:
    SFIO SF; // handles Stockfish i/o

    std::string moveList; // game state is simply all previous moves
    std::string moveTime; // time to let SF think
    std::string userInput; // move/command/etc
    std::string response; // SF response move
};

#endif
