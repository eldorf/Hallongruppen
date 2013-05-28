#include "commandLookup.h"
#include "commandHandler.h"
#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char** argv)
{
    CommandLookup lookup;
    std::string command;
    if (argc == 2)
    {
        if (strncmp(argv[1], "on", sizeof("on")) == 0)
        {
            std::cout << "Turning on\n";
            command = lookup.tableA.on;
        }
        else if (strncmp(argv[1], "off", sizeof("off")) == 0)
        {
            std::cout << "Turning off\n";
            command = lookup.tableA.off;
        }
        else
        {
            std::cout << "unknown command\n";
            std::cout << "argv[0] " << argv[0] << " argv[1] " << argv[1];
        }
    }
    else
    {
        std::cout << "usage: command on|off\n";
    }


    CommandHandler commandHandler;
    if (!commandHandler.init())
    {
        std::cout << "Unable to init the wiringPi-library...\n";
        return 1;
    };
    commandHandler.sendCommand(command);
    
    return 0;
}
