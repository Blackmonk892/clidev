#pragma once

#include "../cli/Terminal.hpp"

class Application
{
public:
    Application();

    int run();

private:
    void initialize();
    void shutdown();

private:
    Terminal terminal_;
};