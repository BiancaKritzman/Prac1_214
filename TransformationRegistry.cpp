#include <iostream>

#include "TransformationRegistry.h"
#include "Transformation.h"

void TransformationRegistry::registerStep(std::string key, Transformation* transformation){
    prototypes[key] = transformation;
}

Transformation* TransformationRegistry::create(std::string key){

    auto p = prototypes.find(key);

    if(p != prototypes.end()) {
        if(p->second){
            return p->second->clone();
        }
        else{
            return nullptr;
        }
    }
    else {
        return nullptr;
    }
}
        
TransformationRegistry::~TransformationRegistry() {
    for (auto i = prototypes.begin(); i != prototypes.end(); ++i) {
        delete i->second;
    }
    prototypes.clear();
}