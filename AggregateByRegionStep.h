#include <string>
#include <vector>
#include "Transformation.h"

class AggregateByRegionStep : public Transformation {
    public:
        AggregateByRegionStep():Transformation("aggregate"){};
        Transformation* clone() override;
        std::vector<std::string> apply(std::vector<std::string>) override;
};