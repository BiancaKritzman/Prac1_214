#include <iostream>
#include "Pipeline.h"
#include "ConnectorFactory.h"
#include "RunCheckpoint.h"
#include "Transformation.h"
#include "StreamingPipeline.h"


void StreamingPipeline::extract() {

    Connector* connector = factory->createConnector();
    records = connector->extract();

    std::cout << "Streaming extract: " << records.size() << " records \n" << std::endl;

    stage = 2;

    //clean up (delete)
    delete connector;
}


void StreamingPipeline::load() {
    
    std::cout << "Streaming load: " << records.size() << " records streamed \n" << std::endl;

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