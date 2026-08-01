#include "CheckpointManager.h"

void CheckpointManager::save(RunCheckpoint* cp){
    //appends
    history.push_back(cp);
}
RunCheckpoint* CheckpointManager::undo(){
    if(!history.empty()){
        RunCheckpoint* cp = history.back();
        history.pop_back();
        return cp;
    }
    else {
        return nullptr;
    }
}
CheckpointManager::~CheckpointManager(){
    for(size_t i = 0; i < history.size(); i++){
        delete history[i];
    }
}