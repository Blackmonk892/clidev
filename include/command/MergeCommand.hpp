#pragma once

#include "ICommand.hpp"

#include <string>

class MergeCommand : public ICommand
{
public:
    std::string name() const override;

    void execute(
        const std::vector<std::string> &arguments) override;
};