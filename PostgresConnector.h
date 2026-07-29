#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H

#include "Connector.h"

class PostgresConnector : public Connector {
public:
    vector<string> extract();
};

#endif