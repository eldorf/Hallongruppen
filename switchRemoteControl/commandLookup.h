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
    class ConnectorB : public Connector
    {
        public:
        std::string on() { return "llllllllllklkkklklklklkkk"; }
        std::string off() {return "llllllllllklkkklklklkkklk"; }
        std::string getName() { return "Connector B"; }
    };
    class ConnectorC : public Connector
    {
        public:
        std::string on() { return "llllllllllklklkkklklklkkk"; }
        std::string off() {return "llllllllllklklkkklklkkklk"; }
        std::string getName() { return "Connector C"; }
    };
    class ConnectorD : public Connector
    {
        public:
        std::string on() { return "llllllllllklklklkkklklkkk"; }
        std::string off() {return "llllllllllklklklkkklkkklk"; }
        std::string getName() { return "Connector D"; }
    };
    class ConnectorE : public Connector
    {
        public:
        std::string on() { return "llllllllllklklklklkkklkkk"; }
        std::string off() {return "llllllllllklklklklkkkkklk"; }
        std::string getName() { return "Connector E"; }
    };
    ConnectorA connectorA;
    ConnectorB connectorB;
    ConnectorC connectorC;
    ConnectorD connectorD;
    ConnectorE connectorE;
     public:
        Connector* getConnectorA() { return &connectorA; }
        Connector* getConnectorB() { return &connectorB; }
        Connector* getConnectorC() { return &connectorC; }
        Connector* getConnectorD() { return &connectorD; }
        Connector* getConnectorE() { return &connectorE; }
};
#endif
