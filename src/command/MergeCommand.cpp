#include "../../include/command/MergeCommand.hpp"

#include <iostream>

void MergeCommand::execute(const std::vector<std::string> &arguments)
{
    if (arguments.size() < 3)
    {
        std::cout
            << "Usage:\n"
            << "merge input1.pdf input2.pdf output.pdf\n";

        return;
    }

    std::cout << "\n";
    std::cout << "========== Merge Command ==========\n";

    std::cout << "Input 1 : " << arguments[0] << '\n';
    std::cout << "Input 2 : " << arguments[1] << '\n';
    std::cout << "Output  : " << arguments[2] << '\n';

    if (arguments.size() > 3)
    {
        std::cout << "\nAdditional PDFs:\n";

        for (size_t i = 3; i < arguments.size(); ++i)
        {
            std::cout << " - " << arguments[i] << '\n';
        }
    }

    std::cout << "\n(Real PDF merging will be added using qpdf.)\n\n";
}