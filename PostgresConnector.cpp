#include "PostgresConnector.h"

PostgresConnector::PostgresConnector(string source) : Connector(source) {
    source = "postgres";
}

vector<string> PostgresConnector::extract() {
    return {"PG:001","PG:002","PG:002","PG:003"};
}