#pragma once

#include <string>
#include <vector>

struct ParsedCommand
{
    std::string name;
    std::vector<std::string> arguments;
};

class CommandParser
{
public:
    ParsedCommand parse(const std::string &input) const;
};