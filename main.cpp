#include "game.h"
#include "stockfishio.h"

#include <iostream>

int main(void)
{
    Game G = Game(); //create a new Game object
    // G.makeMove("e2e4");
    // std::cout << G.getMoves() << std::endl;

    SFIO SF = SFIO(); 

    std::string moveOutput = SF.exec("stockfish go movetime 2000"); // search for best move for 2 seconds
    //std::cout << SF.exec("go movetime 2000");
    std::string move = SF.getBestMove(moveOutput); // parse the returned string for the suggested move
    G.makeMove(move); // add that move to the move list
    std::cout << G.getMoves() << std::endl;

    return 0;
}