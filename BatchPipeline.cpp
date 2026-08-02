#include <iostream>
#include "Pipeline.h"
#include "ConnectorFactory.h"
#include "RunCheckpoint.h"
#include "Transformation.h"
#include "BatchPipeline.h"

void BatchPipeline::extract(){
    
    Connector* connector = factory->createConnector();
    records = connector->extract();
    std::cout << "Batch extract: " << records.size() << " records \n" << std::endl;
    stage = 2;
    delete connector;

}

void BatchPipeline::load() {

    std::cout << "Batch load: " << records.size() << " records written \n" << std::endl;

    stage = 4;

}