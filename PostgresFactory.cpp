#include "PostgresFactory.h"

Connector* PostgresFactory::createConnector(){
    return new PostgresConnector();
}