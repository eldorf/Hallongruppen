#ifndef _COMMANDLOOKUP_H_
#define _COMMANDLOOKUP_H_
#include <string>

class Connector
{
    public:
    virtual std::string on() = 0;
    virtual std::string off() = 0;
    virtual std::string getName() = 0;
};

class CommandLookup
{
    private:
    class ConnectorA : public Connector
    {
        public:
        std::string on() { return "llllllllllkkklklklklklkkk"; }
        std::string off() {return "llllllllllkkklklklklkkklk"; }
        std::string getName() { return "Connector A"; }
    };
    class ConnectorD : public Connector
    {
        public:
        std::string on() { return "lllllllllllklklklkkklklkkk"; }
        std::string off() {return "lllllllllllklklklkkklkkklk"; }
        std::string getName() { return "Connector D"; }
    };
    class ConnectorE : public Connector
    {
        public:
        std::string on() { return "lllllllllllklklklklkkklkkk"; }
        std::string off() {return "lllllllllllklklklklkkkkklk"; }
        std::string getName() { return "Connector E"; }
    };
    ConnectorA connectorA;
    ConnectorD connectorD;
    ConnectorE connectorE;
     public:
        Connector* getConnectorA() { return &connectorA; }
        Connector* getConnectorD() { return &connectorD; }
        Connector* getConnectorE() { return &connectorE; }
};
#endif
