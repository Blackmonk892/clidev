#pragma once
#include "../command/CommandRegistry.hpp"
#include <string>

class Terminal
{
public:
    explicit Terminal(CommandRegistry &registry);

    void showBanner();

    void run();

private:
    void printPrompt();

    void clear();

    bool processCommand(const std::string &command);

    void showHelp();

    void unknownCommand(const std::string &command);

private:
    CommandRegistry &registry_;
};