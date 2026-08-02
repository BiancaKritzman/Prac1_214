
#include <vector>
#include <string>
#include "Pipeline.h"

class ConnectorFactory;
class Transformation;
class RunCheckpoint;

class StreamingPipeline : public Pipeline {
    public:
        StreamingPipeline(ConnectorFactory* factory) : Pipeline(factory) {}
        RunCheckpoint* createCheckpoint() override;
        void restore(RunCheckpoint*) override;
        
    protected:
        void extract() override;
        void load() override;
        
};

