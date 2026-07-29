#include "RestApiConnector.h"

RestApiConnector::RestApiConnector(string source) : Connector(source) {
    source = "restapi";
}

vector<string> RestApiConnector::extract() {
    return {"API:44","API:45","API:45"};
}