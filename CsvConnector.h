#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H

#include "Connector.h"

class CsvConnector : public Connector {
public:
    CsvConnector(string source) : Connector(source) {}
    vector<string> extract();
};

#endif