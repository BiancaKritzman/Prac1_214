#include <iostream>
#include "Transformation.h"
#include "Pipeline.h"

Transformation::Transformation(std::string name) : name(name) {};

//if name is from DeduplicateStep = dedup
//if name is from AggregateByRegionStep = aggregate

std::string Transformation::getName(){
    return name;
}

std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> records) { //correct?
  //remove consective duplicates from records - keep the first of each input
  std::vector<std::string> deduplicatedRecords;
  for (size_t i = 0; i < records.size(); ++i) {
    if (i == 0 || records[i] != records[i - 1]) {
        deduplicatedRecords.push_back(records[i]);
    }
  }
  return deduplicatedRecords;
}

Transformation* DeduplicateStep::clone() {

  name = "dedup"; //not sure
  
  return new DeduplicateStep(*this);
}

std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> records) { //correct?
  
  std::string element = "COUNT=" + records.size();
}

Transformation* AggregateByRegionStep::clone() {

  name = "aggregate"; //not sure
  
  return new AggregateByRegionStep(*this);
}





