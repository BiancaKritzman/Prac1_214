#include <iostream>
#include "Transformation.h"
#include "Pipeline.h"
#include "AggregateByRegionStep.h"

std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> records) { 

  std::vector<std::string> aggRecords;
  
  aggRecords.push_back("COUNT=" + std::to_string(records.size()));

  return aggRecords;
}

Transformation* AggregateByRegionStep::clone() {

  name = "aggregate"; //not sure
  
  return new AggregateByRegionStep(*this);
}

