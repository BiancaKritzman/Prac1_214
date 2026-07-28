#ifndef TRANSFORMATIONREGISTRY_H
#define TRANSFORMATIONREGISTRY_H

#include <string>
#include <vector>
#include <map>

class Transformation;


class TransformationRegistry {
    public:
        void registerStep(std::string, Transformation*);
        Transformation* create(std::string);
        ~TransformationRegistry(); 
    private:
        std::map<std::string, Transformation*> prototypes;
};


#endif // TRANSFORMATIONREGISTRY_H