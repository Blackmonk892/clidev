#pragma once
#include "../command/CommandRegistry.hpp"
#include <string>
#include "../parser/CommandParser.hpp" // Required for CommandParser member

class Terminal
{
public:
    explicit Terminal(CommandRegistry &registry);

    void showBanner();

    void run();

private:
    void printPrompt();

    void clear();

    bool executeInput(const std::string &input); // Renamed from processCommand

    void showHelp();

    void unknownCommand(const std::string &command);

private:
    CommandRegistry &registry_;
    CommandParser parser_; // CommandParser is now a member
};