#include <iostream>
#include <stdio.h>
//#include <io.h>
#include <unistd.h> // for _isatty()
#include <FarmScript.h>

#define EXIT_USAGE 64

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        std::cout << "Usage: FarmScript [script]" << std::endl;
        return EXIT_USAGE;
    }
    else if (argc == 2)
    {
        FarmScript::runFile(argv[1]);
    }
    else
    {
        if (isatty(fileno(stdin)))
        {
            FarmScript::runPrompt();
        }
        else
        {
            FarmScript::runPipe();
        }
    }
    return EXIT_SUCCESS;
}
