#include "../../include/parser/CommandParser.hpp"

#include <sstream>

ParsedCommand CommandParser::parse(const std::string &input) const
{
    ParsedCommand command;

    std::istringstream stream(input);

    stream >> command.name;

    std::string token;

    while (stream >> token)
    {
        command.arguments.push_back(token);
    }

    return command;
}