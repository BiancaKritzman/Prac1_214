#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <vector>
#include <string>
class RunCheckpoint;

class CheckpointManager{
    private: std::vector<RunCheckpoint*> history;
    public:
        void save(RunCheckpoint*);
        RunCheckpoint* undo();
        ~CheckpointManager();
};

#endif