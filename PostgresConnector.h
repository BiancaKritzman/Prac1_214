#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H

#include "Connector.h"

class PostgresConnector : public Connector {
public:
    PostgresConnector(string source) : Connector(source) {}
    vector<string> extract();
};

#endif