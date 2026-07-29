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
        RunCheckpoint* createCheckpoint();
        void restore(RunCheckpoint*);
        virtual ~Pipeline();
        //memento functions
        RunCheckpoint* createCheckpoint();
        void restore(RunCheckpoint*);
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
    protected:
        void extract() override;
        void load() override;
};

class StreamingPipeline : public Pipeline {
    protected:
        void extract() override;
        void load() override;
};


#endif // PIPELINE_H