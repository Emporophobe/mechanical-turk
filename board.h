#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <iostream>
#include <vector>

class Board
{
public:
    Board();

    void moveOnBoard(const std::string &move); // changes board given move string

    friend std::ostream& operator<<(std::ostream &os, const Board &rhs);

private:
    std::vector<std::vector<char>> board; // matrix to hold piece positions
    void putChar(const char &c, const int &col, const int &row); // puts a char on the board at the specified square coordinate
};

#endif

