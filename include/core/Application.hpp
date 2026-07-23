#pragma once

#include "../cli/Terminal.hpp"
#include "../command/CommandRegistry.hpp"

class Application
{
public:
    Application();

    int run();

private:
    void initialize();
    void shutdown();

private:
    CommandRegistry registry_;
    Terminal terminal_;
};