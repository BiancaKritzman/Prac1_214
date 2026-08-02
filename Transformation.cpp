#include <iostream>
#include "Transformation.h"
#include "Pipeline.h"

Transformation::Transformation(std::string name) : name(name) {};
Transformation::~Transformation(){}

//if name is from DeduplicateStep = dedup
//if name is from AggregateByRegionStep = aggregate

std::string Transformation::getName(){
    return name;
}





