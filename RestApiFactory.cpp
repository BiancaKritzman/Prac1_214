#include "RestApiFactory.h"

Connector* RestApiFactory::createConnector(){
    return new RestApiConnector();
}#include "RestApiFactory.h"

Connector* RestApiFactory::createConnector(){
    return new RestApiConnector();
}