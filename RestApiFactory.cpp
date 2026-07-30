#include "RestApiFactory.h"

Connector* RestApiFactory::createConnector(){
    return new RestApiConnector();
}