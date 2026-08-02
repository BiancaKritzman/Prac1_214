#include "TransformationRegistry.h"
#include "Transformation.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "Pipeline.h"
#include "BatchPipeline.h"
#include "PostgresFactory.h"
#include "RestApiFactory.h"
#include "CheckpointManager.h"
#include "RunCheckpoint.h"
#include "StreamingPipeline.h"
#include "CsvFactory.h"


int main() {

    //(1) transformation registry
    TransformationRegistry registry;
    registry.registerStep("dedup", new DeduplicateStep());
    registry.registerStep("aggregate", new AggregateByRegionStep());

    //(2) BatchPipeline with PostgresFactory
    BatchPipeline* pipeline = new BatchPipeline(new PostgresFactory());

    //(3) add cloned
    pipeline->addStep(registry.create("dedup"));
    pipeline->addStep(registry.create("aggregate"));

    //(4) checkpt manager
    CheckpointManager* manager = new CheckpointManager();

    //(5)
    pipeline->run();
    RunCheckpoint* cp = pipeline->createCheckpoint();
    manager->save(cp);

    //(6) deletes
    delete pipeline;
    delete manager;
    delete cp;

    return 0;



    //Testing a second pipeline
    StreamingPipeline* streamPipeline = new StreamingPipeline(new RestApiFactory());
    streamPipeline->addStep(registry.create("dedup"));
    streamPipeline->addStep(registry.create("aggregate"));

    CheckpointManager* manager2 = new CheckpointManager();

    streamPipeline->run();
    RunCheckpoint* cp2 = streamPipeline->createCheckpoint();
    manager2->save(cp2);

    RunCheckpoint* restored = manager2->undo(); //to test undo
    if (restored != nullptr) {
        streamPipeline->restore(restored); //test restore
    }

    delete streamPipeline;
    delete manager2;
    delete restored;
    delete cp2;


    //factory test
    StreamingPipeline* csvPipeline = new StreamingPipeline(new CsvFactory());
    csvPipeline->run();
    delete csvPipeline;

    return 0;
}