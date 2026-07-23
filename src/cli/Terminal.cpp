#include "../../include/cli/Terminal.hpp"
#include "../../include/cli/Theme.hpp"

// test
#include "../../include/parser/CommandParser.hpp"

#include <cstdlib>
#include <iostream>

Terminal::Terminal(CommandRegistry &registry)
    : registry_(registry)
{
}

void Terminal::showBanner()
{
    std::cout
        << Theme::primary();

    std::cout <<
        R"(

╔══════════════════════════════════════════════════════╗
║                                                      ║
║   ██████╗ ██████╗ ███████╗██╗  ██╗                   ║
║   ██╔══██╗██╔══██╗██╔════╝╚██╗██╔╝                   ║
║   ██████╔╝██║  ██║█████╗   ╚███╔╝                    ║
║   ██╔═══╝ ██║  ██║██╔══╝   ██╔██╗                    ║
║   ██║     ██████╔╝██║     ██╔╝ ██╗                   ║
║   ╚═╝     ╚═════╝ ╚═╝     ╚═╝  ╚═╝                   ║
║                                                      ║
║            PDF Toolkit for Developers                ║
╚══════════════════════════════════════════════════════╝

)";

    std::cout
        << Theme::reset();

    std::cout
        << Theme::success()
        << "Ready.\n"
        << Theme::reset();

    std::cout
        << "Type 'help' to begin.\n\n";
}

void Terminal::run()
{
    std::string command;

    while (true)
    {
        printPrompt();

        std::getline(std::cin, command); // Read user input

        if (!executeInput(command)) // Process the input
            break;                  // Exit loop if executeInput returns false (e.g., "exit" command)
    }
}

void Terminal::printPrompt()
{
    std::cout
        << Theme::primary()
        << "pdfx"
        << Theme::reset()
        << " > ";
}

void Terminal::showHelp()
{
    std::cout <<

        R"(

Available Commands

 help      Show help

 clear     Clear terminal

 exit      Exit PDFX

)";
}

void Terminal::unknownCommand(const std::string &command)
{
    std::cout
        << Theme::error()
        << "Unknown command: "
        << command
        << Theme::reset()
        << "\n";
}

bool Terminal::executeInput(const std::string &input)
{
    if (input.empty())
        return true;

    if (input == "exit")
    {
        std::cout
            << Theme::success()
            << "Goodbye!\n"
            << Theme::reset();

        return false;
    }

    if (input == "help")
    {
        showHelp();
        return true;
    }

    if (input == "clear")
    {
        clear();
        return true;
    }

    ParsedCommand command = parser_.parse(input); // Parse the user input

    if (registry_.execute(command.name, command.arguments)) // Attempt to execute the parsed command
    {
        return true;
    }

    unknownCommand(command.name);

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