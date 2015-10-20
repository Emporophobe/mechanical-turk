#include "game.h"
#include "board.h"

#include <iostream>
#include <regex>
#include <string>

Game::Game()
{
    moveList = "";
    moveTime = "3000"; // in ms
}

void Game::makeMove(const std::string &move)
{
    moveList.append(move); 
    moveList.append(" ");
        
    response = SF.makeMove(moveList, moveTime);
 
    moveList.append(response);
    moveList.append(" ");
}

void Game::readUserInput()
{
    Board B; // initial board
    std::cout << B << std::endl; // display start position
    std::string in; // user input
    
    while (true)
    {
        std::cout << ">>> ";
        std::cin >> in;

        if (std::regex_match(in, std::regex("[a-h][1-8][a-h][1-8]"))) // if input matches move format
        {
            // make player move on board
            B.moveOnBoard(in);
            std::cout << B << std::endl;
 
            // process move and get response
            makeMove(in);
 
            // make computer move on board and print to console
            B.moveOnBoard(response);
            std::cout << response << std::endl;
            std::cout << B << std::endl;
        }

        else if (in == "board")
        {
            std::cout << B << std::endl; // print board to console
        }

        else if (in == "moves")
        {
            std::cout << moveList << std::endl; // output all moves in game
        }

        else if (in == "quit")
        {
            break; // exit
        }

        else // catch all other inputs
        {
            std::cout << "Bad input, try again." << std::endl;
        } 
   }
}
