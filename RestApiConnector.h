#ifndef RESTAPICONNECTOR_H
#define RESTAPICONNECTOR_H

#include "Connector.h"


class RestApiConnector : public Connector {
public:
    RestApiConnector(string source) : Connector(source) {}
    vector<string> extract();
};

#endif