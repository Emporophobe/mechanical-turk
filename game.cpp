#include "game.h"
#include <string>
#include <iostream>

Game::Game()
{
    moveList = "position startpos moves ";
}

void Game::makeMove(std::string move)
{
    moveList.append(move);
    moveList.append(" ");
}

std::string Game::getMoves()
{
    return moveList;
}

void Game::readInput(std::string in)
{

}