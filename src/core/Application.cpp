#include "../../include/core/Application.hpp"

#include "../../include/command/MergeCommand.hpp"

#include <memory>

Application::Application() : terminal_(registry_)
{
}

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
    registry_.registerCommand(
        "merge",
        std::make_unique<MergeCommand>());
}

void Application::shutdown()
{
    // Future cleanup
}