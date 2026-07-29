#include <iostream>
#include "Pipeline.h"
#include "ConnectorFactory.h"
#include "RunCheckpoint.h"
#include "Transformation.h"

Pipeline::Pipeline(ConnectorFactory* factory) : factory(factory), stage(0) {};

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
    
    std::cout << "Connecting to" << connector->getSource() << "\n" << std::endl;

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

RunCheckpoint* Pipeline::createCheckpoint() {}

void Pipeline::restore(RunCheckpoint*) {}

Pipeline::~Pipeline() {
    delete factory;

    for(int i = 0; i < steps.size(); i++) {
        delete steps[i];
    }
}

void BatchPipeline::extract(){
    
    Connector* connector;


    std::cout << "Batch extract: " << records.size() << "records \n" << std::endl;

    stage = 2;

    //clean up (delete)
    delete connector;

}

void BatchPipeline::load() {

    std::cout << "Batch load: " << records.size() << "records written \n" << std::endl;

    stage = 4;

}

void StreamingPipeline::extract() {

    Connector* connector;


    std::cout << "Streaming extract: " << records.size() << "records \n" << std::endl;

    stage = 2;

    //clean up (delete)
    delete connector;
}


void StreamingPipeline::load() {
    
    std::cout << "Streaming load: " << records.size() << "records streamed \n" << std::endl;

    stage = 4;
}

//memento
RunCheckpoint* StreamingPipeline::createCheckpoint(){
    RunCheckpoint* checkpoint = new RunCheckpoint(stage, records);
    return checkpoint;
}
void StreamingPipeline::restore(RunCheckpoint* cp){
    stage = cp->getStage();
    records = cp->getRecords();
}