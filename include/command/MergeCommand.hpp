#pragma once
#include "ICommand.hpp"

class MergeCommand : public ICommand
{
public:
    void execute(const std::vector<std::string> &arguments) override;
};