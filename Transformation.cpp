#include <iostream>
#include "Transformation.h"
#include "Pipeline.h"

//make a friends?

Transformation::Transformation(std::string name) : name(name) {};

//if name is from DeduplicateStep = dedup
//if name is from AggregateByRegionStep = aggregate

std::string Transformation::getName(){
    return name;
}

std::vector<std::string> DeduplicateStep::apply() {
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
    return new DeduplicateStep(*this);
}




