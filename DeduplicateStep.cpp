#include <iostream>
#include "Transformation.h"
#include "Pipeline.h"
#include "DeduplicateStep.h"

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