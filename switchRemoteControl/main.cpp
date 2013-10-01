#include "commandLookup.h"
#include "commandHandler.h"
#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char** argv)
{
    CommandLookup lookup;
    std::string command;
    if (argc == 3)
    {
        Connector* connector = 0;
        if (strncmp(argv[1], "A", sizeof("A")) == 0)
        {
           connector = lookup.getConnectorA(); 
        }
        else if (strncmp(argv[1], "D", sizeof("D")) == 0)
        {
           connector = lookup.getConnectorD(); 
        }
        else if (strncmp(argv[1], "E", sizeof("E")) == 0)
        {
           connector = lookup.getConnectorE(); 
        }
        else
        {
            std::cout << "Unknown connector type \"" << argv[1] <<"\"" << std::endl;
            return 1;
        }

        if (strncmp(argv[2], "on", sizeof("on")) == 0)
        {
            std::cout << "Turning on " << connector->getName() << std::endl;
            command = connector->on();
        }
        else if (strncmp(argv[2], "off", sizeof("off")) == 0)
        {
            std::cout << "Turning off " << connector->getName() << std::endl;
            command = connector->off();
        }
        else
        {
            std::cout << "unknown command\n";
            std::cout << "argv[0] " << argv[0] << " argv[1] " << argv[1];
        }
    }
    else
    {
        std::cout << "usage: command A|B|C on|off\n";
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
