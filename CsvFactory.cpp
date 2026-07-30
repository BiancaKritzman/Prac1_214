#include "CsvFactory.h"

Connector* CsvFactory::createConnector(){
    return new CsvConnector();
}