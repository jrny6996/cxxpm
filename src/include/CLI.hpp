#pragma once

#include <string_view>

enum class Command
{
    UNKNOWN,
    SCAFFOLD,
    GET,
    RUN
};

enum class Option
{
    HELP,
};

struct CommandSpec
{
    std::string_view name;
    Command Command;
    bool takesValue;
};

constexpr CommandSpec commands[] = {
    {"scaffold", Command::SCAFFOLD, true},
    {"get", Command::GET, true},
    {"run", Command::RUN, true},
};

constexpr const CommandSpec *findCommand(std::string_view arg)
{
    for (const auto &opt : commands)
    {
        if (opt.name == arg)
            return &opt;
    }
    return nullptr;
}