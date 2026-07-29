#ifndef RESTAPICONNECTOR_H
#define RESTAPICONNECTOR_H

#include "Connector.h"


class RestApiConnector : public Connector {
public:
    vector<string> extract();
};

#endif