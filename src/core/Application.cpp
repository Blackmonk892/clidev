#include "../../include/core/Application.hpp"

Application::Application() = default;

int Application::run()
{
    initialize();

    terminal_.showBanner();

    terminal_.run();

    shutdown();

    return 0;
}

void Application::initialize()
{
    // Future:
    // Logger
    // Config
    // Plugin Manager
    // Command Registry
}

void Application::shutdown()
{
    // Future cleanup
}