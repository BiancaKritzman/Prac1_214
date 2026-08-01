#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>
#include <string>


class ConnectorFactory;
class Transformation;
class RunCheckpoint;

class Pipeline {

    public:
        Pipeline(ConnectorFactory*);
        void run();
        void addStep(Transformation*);
        virtual ~Pipeline();
        //memento functions
        virtual RunCheckpoint* createCheckpoint();
        virtual void restore(RunCheckpoint*);
    protected:
        void connect();
        virtual void extract() = 0;
        void transform();
        virtual void load() = 0;
    protected:
        ConnectorFactory* factory;
        std::vector<Transformation*> steps;
        int stage;
        std::vector<std::string> records;

};

class BatchPipeline : public Pipeline {
    public:
        BatchPipeline(ConnectorFactory* factory) : Pipeline(factory) {}
    protected:
        void extract() override;
        void load() override;
};

class StreamingPipeline : public Pipeline {
    public:
        StreamingPipeline(ConnectorFactory* factory) : Pipeline(factory) {}

    protected:
        void extract() override;
        void load() override;
        RunCheckpoint* createCheckpoint() override;
        void restore(RunCheckpoint*) override;
};


#endif // PIPELINE_H