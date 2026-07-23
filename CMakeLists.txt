cmake_minimum_required(VERSION 3.20)

project(
    PDFX
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(pdfx

    src/main.cpp

    src/core/Application.cpp

    src/cli/Terminal.cpp
    src/cli/Theme.cpp

    src/parser/CommandParser.cpp

    src/command/CommandRegistry.cpp
    src/command/MergeCommand.cpp
)