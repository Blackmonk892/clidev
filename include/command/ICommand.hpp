#pragma once

#include <string>
#include <vector>

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual std::string name() const = 0;

    virtual void execute(
        const std::vector<std::string> &arguments) = 0;
};