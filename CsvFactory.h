#ifndef CSVFACTORY_H
#define CSVFACTORY_H

#include "ConnectorFactory.h"
#include "CsvConnector.h"

class CsvFactory : public ConnectorFactory {
public:
    Connector* createConnector();
};

#endif