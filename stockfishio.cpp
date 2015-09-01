#include "stockfishio.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <fstream>

// SFIO::SFIO()
// {

// }

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

std::string SFIO::makeMove(std::string moveList, std::string moveTime)
{
    std::ofstream sfcmds;
    sfcmds.open("sfcmds.txt");
    sfcmds << "position startpos moves " << moveList << "\n";
    sfcmds << "go movetime " << moveTime << "\n\n";

    sfcmds.close();

    std::string response = exec("stockfish < sfcmds.txt");

    return getBestMove(response);
}