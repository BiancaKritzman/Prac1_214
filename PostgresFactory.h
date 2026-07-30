#ifndef POSTGRESFACTORY_H
#define POSTGRESFACTORY_H

#include "ConnectorFactory.h"
#include "PostgresConnector.h"

class PostgresFactory : public ConnectorFactory {
public:
    Connector* createConnector();
};

#endif