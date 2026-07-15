#include <cli/Theme.hpp>

namespace Theme
{
    std::string reset()
    {
        return "\033[0m";
    }

    std::string primary()
    {
        return "\033[36m"; // Cyan
    }

    std::string success()
    {
        return "\033[32m"; // Green
    }

    std::string warning()
    {
        return "\033[33m"; // Yellow
    }

    std::string error()
    {
        return "\033[31m"; // Red
    }

    std::string accent()
    {
        return "\033[1m"; // Bold
    }
}