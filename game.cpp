#include "game.h"
#include "board.h"
#include <string>
#include <iostream>
#include <regex>

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
    Board B;
    std::string in; // user input
    while (true)
    {
        std::cout << ">>> ";
        std::cin >> in;

        if (std::regex_match(in, std::regex("[a-h][1-8][a-h][1-8]"))) // if input matches move format
        {
            B.moveOnBoard(in);
            makeMove(in);
            B.moveOnBoard(response);
            std::cout << response << std::endl;
            std::cout << B << std::endl;
        }

        else if (in == "board")
        {
            std::cout << B << std::endl;
        }

        else if (in == "moves")
        {
            std::cout << moveList << std::endl;
        }

        else if (in == "quit")
        {
            break;
        }

        else
        {
            std::cout << "Bad input, try again." << std::endl;
        } 
   }
}
