#ifndef _COMMANDHANDLER_H_ 
#define _COMMANDHANDLER_H_ 
#include <string>

class CommandHandler
{
    private:
    static const unsigned int shortDelay;
    static const unsigned int longDelay;
    unsigned int pin;
    unsigned int repeat;

    private:
    void sendLongBit();
    void sendShortBit();
    

    public:
    CommandHandler();
    bool init();
    void sendCommand(std::string command);
};

#endif
