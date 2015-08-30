#include "stockfishio.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <stdio.h>

std::string SFIO::exec(char* cmd) // runs a command on the command line
{
    FILE* pipe = popen(cmd, "r");
    
    if(!pipe) return "ERROR";

    char buffer[128];
    std::string result = "";
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL)
        {
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

std::string SFIO::getBestMove(std::string text) //takes stockfish output and searches for the move after bestmove
{
    std::string target = "bestmove";
    std::stringstream Stream(text);
    
    std::string word = "";
    do
    {
        Stream >> word;
    } while(strcmp(target.c_str(), word.c_str()) != 0);

    Stream >> word;
    return word;
}