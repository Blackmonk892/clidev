#include "CLI.hpp"
#include <cstdlib>
#include <iostream>

void CLI::printBanner()
{
    std::cout << "==========================================\n";
    std::cout << "          LovePDF CLI v0.1\n";
    std::cout << "==========================================\n\n";

    std::cout << "Type 'help' for available commands.\n\n";
}

void CLI::printHelp()
{
    std::cout << "\nAvailable commands\n";
    std::cout << "------------------\n";
    std::cout << "hello\n";
    std::cout << "help\n";
    std::cout << "clear\n";
    std::cout << "exit\n\n";
}

void CLI::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void CLI::run()
{
    printBanner();

    std::string command;

    while (true)
    {
        std::cout << "pdfx > ";

        std::getline(std::cin, command);

        if (command == "hello")
        {
            std::cout << "Hello User!\n\n";
        }
        else if (command == "help")
        {
            printHelp();
        }
        else if (command == "clear")
        {
            clearScreen();
            printBanner();
        }
        else if (command == "exit")
        {
            std::cout << "\nGoodbye bruh\n";
            break;
        }
        else if (command.empty())
        {
            continue;
        }
        else
        {
            std::cout << "Unknown command.\n\n";
        }
    }
}
