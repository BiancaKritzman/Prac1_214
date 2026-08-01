#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <string>
#include <vector>

using namespace std;

class Connector {
protected:
    string source;
public:
    Connector(string);
    string getSource();
    virtual vector<string> extract() = 0;
    virtual ~Connector();
};

#endif