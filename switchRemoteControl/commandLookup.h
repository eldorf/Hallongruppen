#ifndef _COMMANDLOOKUP_H_
#define _COMMANDLOOKUP_H_
#include <string>

class CommandLookup
{
    private:
    class TableA
    {
        public:
        const std::string on;
        const std::string off; 
        TableA(): on("llllllllllkkklklklklklkkk"), 
                 off("llllllllllkkklklklklkkklk")
        {}

    };
    public:
    TableA tableA;
};
#endif
