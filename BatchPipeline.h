
#include <vector>
#include <string>
#include "Pipeline.h"

class ConnectorFactory;
class Transformation;
class RunCheckpoint;


class RunCheckpoint;class BatchPipeline : public Pipeline {
    public:
        BatchPipeline(ConnectorFactory* factory) : Pipeline(factory) {}
    protected:
        void extract() override;
        void load() override;
};