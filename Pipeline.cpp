#include <iostream>
#include "Pipeline.h"
#include "ConnectorFactory.h"
#include "RunCheckpoint.h"
#include "Transformation.h"

Pipeline::Pipeline(ConnectorFactory* factory) : factory(factory), stage(0) {};
RunCheckpoint* Pipeline::createCheckpoint() { return nullptr; }
void Pipeline::restore(RunCheckpoint*) {}

void Pipeline::addStep(Transformation* t) {
    steps.push_back(t); 
}

void Pipeline::run() {
    connect();
    extract();
    transform();
    load();
}

void Pipeline::connect() {

    //obtain connector from factory
    Connector* connector = factory->createConnector();
    
    std::cout << "Connecting to " << connector->getSource() << "\n" << std::endl;

    stage = 1;

    delete connector;
}

void Pipeline::transform() {

    for(size_t i = 0; i < steps.size(); i++) {
        if(steps[i] != nullptr){
            steps[i]->apply(records);
        }
    }

    stage = 3;
}


Pipeline::~Pipeline() {
    delete factory;

    for(size_t i = 0; i < steps.size(); i++) {
        delete steps[i];
    }
}


