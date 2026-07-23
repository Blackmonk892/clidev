#include "../../include/command/MergeCommand.hpp"
#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

std::string MergeCommand::name() const
{
    return "merge";
}

void MergeCommand::execute(const std::vector<std::string> &arguments)

{
    if (arguments.size() < 3)
    {
        std::cout
            << "Usage:\n"
            << "merge input1.pdf input2.pdf output.pdf\n";

        return;
    }

    std::vector<fs::path> inputFiles;
    for (size_t i = 0; i < arguments.size() - 1; i++)
    {
        inputFiles.emplace_back(arguments[i]);
    }
    fs::path outputFile = arguments.back();

    for (const auto &file : inputFiles)
    {
        if (!fs::exists(file))
        {
            std::cout << "\n Error: File not found: " << file << "\n";
            return;
        }

        if (file.extension() != ".pdf")
        {
            std::cout << "\n Error: Not a PDF file: " << file << "\n";
            return;
        }
    }

    if (outputFile.extension() != ".pdf")
    {
        std::cout << "\n Error: Output file must have a .pdf extension: " << outputFile << "\n";
        return;
    }

    std::cout << "\n";
    std::cout << "Input PDFs\n";
    std::cout << "----------\n";
    for (const auto &file : inputFiles)
    {
        std::cout << "✓ " << file << '\n';
    }
    std::cout << "\n";
    std::cout
        << "Output : "
        << outputFile
        << "\n\n";
    std::cout
        << "Validation successful.\n";
    std::cout
        << "(Actual merging will be implemented in Phase 3.2)\n\n";
}