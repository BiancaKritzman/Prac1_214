#include <iostream>
#include "Pipeline.h"
#include "ConnectorFactory.h"

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
    
    std::cout << "Connecting to" << factory->getSource() << "\n" << std::endl;

    stage = 1;

    delete connector;
}

void Pipeline::transform() {

    for(int i = 0; i < records.size(); i++) {
        records[i] = steps[i];
    }

    stage = 3;
}

RunCheckpoint* Pipeline::createCheckpoint() {}

void Pipeline::restore(RunCheckpoint*) {}

PipeLine::~Pipeline() {
    delete factory;

    for(int i = 0; i < steps.size(); i++) {
        delete steps[i];
    }
    delete steps;
}

void BatchPipeline::extract(){
    
    Connector* connector = records->extract();


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

    Connector* connector = records->extract();


    std::cout << "Streaming extract: " << records.size() << "records \n" << std::endl;

    stage = 2;

    //clean up (delete)
    delete connector;
}


void StreamingPipeline::load() {
    
    std::cout << "Streaming load: " << reconrds.size() << "records streamed \n" << std::endl;

    stage = 4;
}
