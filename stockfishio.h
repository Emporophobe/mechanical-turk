#ifndef _STOCKFISHIO_H_
#define _STOCKFISHIO_H_

#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

// http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
class SFIO
{
private:
    std::string exec(char* cmd);
    std::string getBestMove(std::string text);

    //std::ofstream sfcmds;
public:
    std::string makeMove(std::string moveList, std::string moveTime);
    void playGame();
};

#endif