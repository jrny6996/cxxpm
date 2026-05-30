#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <your_argument>\n";

        return 1;
    }
    else
    {
        for (int i = 0; i < argc; ++i)
        {
            std::cout << "argv[" << i << "]: " << argv[i] << "\n";
        }
    }
}