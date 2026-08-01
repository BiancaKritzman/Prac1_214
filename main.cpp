#include "TransformationRegistry.h"
#include "Transformation.h"
#include "Pipeline.h"
#include "PostgresFactory.h"
#include "CheckpointManager.h"
#include "RunCheckpoint.h"

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

    return 0;
}