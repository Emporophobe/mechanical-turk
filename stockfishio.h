#ifndef _STOCKFISHIO_H_
#define _STOCKFISHIO_H_

#include <string>
#include <iostream>
#include <stdio.h>

// http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
class SFIO
{
public:
    std::string exec(char* cmd);
    std::string getBestMove(std::string text);
};

#endif