cmake_minimum_required(VERSION 3.10)
project(minishell-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cmi main.cpp
        src/Interpreter.cpp
        src/CommandFactory.cpp
        src/InputProcessor.cpp
        src/LineParser.cpp
        src/commands/EchoCommand.cpp
        src/commands/TimeCommand.cpp
        src/commands/DateCommand.cpp
        src/commands/TouchCommand.cpp
        src/commands/WcCommand.cpp
        src/commands/PromptCommand.cpp
        src/commands/TruncateCommand.cpp
        src/commands/rmCommand.cpp
        src/commands/trCommand.cpp
        src/commands/HeadCommand.cpp
        src/commands/BatchCommand.cpp)

target_include_directories(cmi PRIVATE include include/Commands)
