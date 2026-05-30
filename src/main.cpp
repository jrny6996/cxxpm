#include <iostream>
#include "include\thirdparty\termcolor.hpp"
#include "include\thirdparty\nlohmann\json.hpp"
#include <set>
#include "include/CLI.hpp"
#include "include/TUI.hpp"
int main(int argc, char *argv[])
{
    enableANSI();
    clearScreen();
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <your_argument>\n";

        return 1;
    }
    else
    {
        bool captureNext = false;
        for (int i = 1; i < argc; ++i)
        {
            if(captureNext){
                captureNext = false;
                continue;
            }
            if (auto *cmd = findCommand(argv[i]))
            {
            
                std::cout << cmd->name << std::endl;
                if (cmd->takesValue)
                    captureNext = true;
                    
                continue;
            }
            else
            {
                std::cout << termcolor::red << "Error parsing command line arg " << i << " :\"" << argv[i] << "\"" << termcolor::reset << "\n";
            }
            captureNext = false;

            // std::cout << "argv[" << i << "]: " << argv[i] << "\n";
        }
    }
}