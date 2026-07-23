#pragma once

#include "ICommand.hpp"

#include <memory>
#include <string>
#include <unordered_map>

class CommandRegistry
{
public:
    void registerCommand(
        const std::string &name,
        std::unique_ptr<ICommand> command);

    bool execute(
        const std::string &name,
        const std::vector<std::string> &arguments);

private:
    std::unordered_map<
        std::string,
        std::unique_ptr<ICommand>>
        commands_;
};