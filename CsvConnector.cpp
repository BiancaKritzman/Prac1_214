#include "CsvConnector.h"

CsvConnector::CsvConnector(string source) : Connector(source) {
    source = "csv";
}

vector<string> CsvConnector::extract() {
    return {"CSV:x1","CSV:x2","CSV:x3","CSV:x3"};
}