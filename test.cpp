//pipes.cc
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int parentToChild[2];
    int childToParent[2];
    int enginePID; // process ID for stockfish

    pipe(parentToChild);
    pipe(childToParent);

    enginePID = fork();

    dup2(parentToChild[0], 0);
    close(parentToChild[0]);
    close(parentToChild[1]);

    dup2(childToParent[1], 1);
    close(childToParent[0]);
    close(childToParent[1]);

    std::string engine = "ls";
    std::string cmd = "uci";

    int nbytes = cmd.length();

    write(parentToChild[1], cmd.c_str(), nbytes);

    close(parentToChild[1]);

    std::cout << cmd << " written to " << engine << std::endl;

    char readBuffer[2];
    std::string out = "";

    while(true)
    {
        int bytesRead = read(childToParent[2], readBuffer, sizeof(char));

        if (readBuffer[0] == '\n')
            break;

        readBuffer[bytesRead] = '\0';

        out += readBuffer;
    }

    std::cout << out << std::endl;

    return 0;
}