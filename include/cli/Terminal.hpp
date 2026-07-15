#pragma once

#include <string>

class Terminal
{
public:
    void showBanner();

    void run();

private:
    void printPrompt();

    void clear();

    bool processCommand(const std::string &command);

    void showHelp();

    void unknownCommand(const std::string &command);
};