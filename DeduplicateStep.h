#include <string>
#include <vector>
#include "Transformation.h"

class DeduplicateStep : public Transformation {
    public:
        DeduplicateStep():Transformation("dedup"){};
        Transformation* clone() override;
        std::vector<std::string> apply(std::vector<std::string>) override;
};