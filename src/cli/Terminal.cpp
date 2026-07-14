#include "../../include/cli/Terminal.hpp"

#include <cstdlib>
#include <iostream>

void Terminal::showBanner()
{
    std::cout
        << "=========================================\n"
        << "             PDFX CLI v0.1\n"
        << "=========================================\n\n";

    std::cout
        << "Type 'help' to begin.\n\n";
}

void Terminal::run()
{
    std::string command;

    while (true)
    {
        printPrompt();

        std::getline(std::cin, command);

        if (!processCommand(command))
            break;
    }
}

void Terminal::printPrompt()
{
    std::cout << "pdfx > ";
}

bool Terminal::processCommand(const std::string &command)
{
    if (command == "exit")
    {
        std::cout << "Goodbye!\n";
        return false;
    }

    if (command == "help")
    {
        std::cout
            << "\nAvailable Commands\n"
            << "------------------\n"
            << "help\n"
            << "clear\n"
            << "exit\n\n";

        return true;
    }

    if (command == "clear")
    {
        clear();
        return true;
    }

    if (command.empty())
        return true;

    std::cout
        << "Unknown command: "
        << command
        << "\n";

    return true;
}

void Terminal::clear()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}