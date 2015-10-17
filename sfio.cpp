#include "sfio.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <fstream>

 SFIO::SFIO()
 {

 }

std::string SFIO::exec(char* cmd) const// runs a command on the command line
{
    FILE* pipe = popen(cmd, "r");
    
    if(!pipe) return "ERROR";

    char buffer[128];
    std::string result = "";

    // read pipe into result, in buffered chunks
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

std::string SFIO::getBestMove(const std::string &text) const //takes stockfish output and searches for the move after bestmove
{
    std::string target = "bestmove";
    std::stringstream stream(text);
    
    std::string word = "";
    do
    {
        stream >> word;
    } while(target != word);

    stream >> word;
   
    return word;
}

std::string SFIO::makeMove(const std::string &moveList, const std::string &moveTime) const
{
    std::ofstream sfcmds;
    sfcmds.open("sfcmds.txt");
    sfcmds << "position startpos moves " << moveList << "\n";
    sfcmds << "go movetime " << moveTime << "\n\n";

    sfcmds.close();

    std::string response = exec("stockfish < sfcmds.txt");

    return getBestMove(response);
}
