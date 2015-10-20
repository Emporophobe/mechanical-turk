#include "board.h"

#include <iostream>
#include <string.h>

Board::Board()
{
    board = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'-', '-', '-', '-', '-', '-', '-', '-'}, 
            {'-', '-', '-', '-', '-', '-', '-', '-'}, 
            {'-', '-', '-', '-', '-', '-', '-', '-'}, 
            {'-', '-', '-', '-', '-', '-', '-', '-'}, 
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
            };
}

void Board::moveOnBoard(const std::string &move)
{
    // slice string into two board coordinates
    std::string from = move.substr(0, 2);
    std::string to = move.substr(2, 2);

    // convert string (eg a3) into indices (eg 0 4)

    char fromColChar = move.at(0);
    char fromRowChar = move.at(1);
    char toColChar = move.at(2);
    char toRowChar = move.at(3);    

    int fromColNum = (int)fromColChar - 'a';
    int fromRowNum = 7 - ((int)fromRowChar - '1'); // subtraction flips matrix so first row is on bottom
    int toColNum = (int)toColChar - 'a';
    int toRowNum = 7 - ((int)toRowChar - '1');

    char onFrom = board[fromRowNum][fromColNum]; // get the char representing the piece that will move


    putChar('-', fromColNum, fromRowNum);
    putChar(onFrom, toColNum, toRowNum);
}

void Board::putChar(const char &c, const int &col, const int &row)
{
    board[row][col] = c;
}


std::ostream& operator<<(std::ostream &os, const Board &rhs)
{
    for(unsigned int i = 0; i < rhs.board.size(); i++)
    {
        os << 8 - i << "| ";
        for (unsigned int j = 0; j < rhs.board[0].size(); j++)
        {
            os << rhs.board[i][j] << " ";
        }
        os << std::endl;
    }
    os << "   ---------------" << std::endl;
    os << "   A B C D E F G H" << std::endl;
    return os;
}

