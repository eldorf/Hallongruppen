#include "commandHandler.h"
#include <wiringPi.h>
#include <string>
#include <iostream>

const unsigned int CommandHandler::shortDelay = 105;
const unsigned int CommandHandler::longDelay = 365;

CommandHandler::CommandHandler() : pin(23), repeat(10)
{
}

bool CommandHandler::init()
{
    if (wiringPiSetupGpio() == -1)
        return false;

    pinMode(pin, OUTPUT);
    digitalWrite(pin, 1);
    digitalWrite(pin, 0);
    return true;
}

void CommandHandler::sendCommand(std::string command)
{
    std::string::iterator it; 
    for (unsigned int i = 0; i < repeat; i++)
    {
        for(it = command.begin(); it != command.end(); it++)
        {
            switch (*it)
            {
                case 'l':
                    sendLongBit();
                    break;
                case 'k':
                    sendShortBit();
                break;
                default:
                    std::cout << "Unknown command!\n";
            }
        }
        delayMicroseconds(3*longDelay);
    }
}

void CommandHandler::sendLongBit()
{
    digitalWrite(pin, 1);
    delayMicroseconds(longDelay);
    digitalWrite(pin, 0);
    delayMicroseconds(shortDelay);
}
void CommandHandler::sendShortBit()
{
    digitalWrite(pin, 1);
    delayMicroseconds(shortDelay);
    digitalWrite(pin, 0);
    delayMicroseconds(longDelay);
}
