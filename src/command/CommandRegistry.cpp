#include "../../include/command/CommandRegistry.hpp"

void CommandRegistry::registerCommand(
    const std::string &name,
    std::unique_ptr<ICommand> command)
{
    commands_[name] = std::move(command);
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