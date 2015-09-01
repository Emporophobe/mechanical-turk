//#include "game.h"
#include "stockfishio.h"

#include <iostream>
#include <fstream>

int main(void)
{
    // Game G = Game(); //create a new Game object
    // G.makeMove("e2e4");
    // std::cout << G.getMoves() << std::endl;

    SFIO SF = SFIO(); 

    // FILE* 

    // std::string moveOutput = SF.exec("stockfish go movetime 2000"); // search for best move for 2 seconds
    // //std::cout << SF.exec("go movetime 2000");
    // std::string move = SF.getBestMove(moveOutput); // parse the returned string for the suggested move
    // G.makeMove(move); // add that move to the move list
    // std::cout << G.getMoves() << std::endl;

    //std::cout << SF.makeMove("e2e4", "5000") << std::endl;

    //std::cout <<"done" <<std::endl;

    std::string movelist = "";

    for (int moves = 0; moves < 10; moves++)
    {
        std::string move = SF.makeMove(movelist, "5000");
        std::cout << "moves = " << movelist << std::endl;
        std::cout << move << std::endl;
        movelist.append(" ");
        movelist.append(move);
    }

    return 0;
}