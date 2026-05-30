#pragma once
#include <iostream>

class TUI
{
private:
    /* data */
public:
    TUI(/* args */);
    ~TUI() =default;
};




#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#else
void enableANSI() {
    // macOS and Linux have ANSI enabled by default
}
#endif

void clearScreen() {
    std::cout << "\033[3J\033[H\033[2J" << std::flush;
}