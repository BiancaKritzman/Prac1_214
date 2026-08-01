#include "Connector.h"
#include <string>
#include <vector>
using namespace std;

Connector::Connector(string source) : source(source) {}

string Connector::getSource(){
    return source;
}

Connector::~Connector(){}