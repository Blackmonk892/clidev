#pragma once
#include <string>

class CLI
{
public:
    void run();

private:
    void printBanner();
    void printHelp();
    void clearScreen();
};