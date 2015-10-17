#ifndef _SFIO_H_
#define _SFIO_H_

#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

class SFIO
{
public:
    SFIO();

    std::string makeMove(const std::string &moveList, const std::string &moveTime) const;

private:
    std::string exec(char* cmd) const; // run a console command and return output
    std::string getBestMove(const std::string &text) const; // takes a move list and returns a new move
};

#endif

