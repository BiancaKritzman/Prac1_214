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




#endif // PIPELINE_H