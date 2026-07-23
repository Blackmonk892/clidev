#include "../../include/command/CommandRegistry.hpp"

void CommandRegistry::registerCommand(
    std::unique_ptr<ICommand> command)
{
    commands_[command->name()] = std::move(command);
}

bool CommandRegistry::execute(
    const std::string &name,
    const std::vector<std::string> &arguments)
{
    auto it = commands_.find(name);

    if (it == commands_.end())
    {
        return false;
    }

    it->second->execute(arguments);

    return true;
}