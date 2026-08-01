#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <string>
#include <vector>


class Transformation {
    public:
        Transformation(std::string);
        virtual Transformation* clone() = 0;
        virtual std::vector<std::string> apply(std::vector<std::string>) = 0;
        std::string getName();
        virtual ~Transformation();
    protected:
        std::string name;

};

class DeduplicateStep : public Transformation {
    public:
        DeduplicateStep():Transformation("dedup"){};
        Transformation* clone() override;
        std::vector<std::string> apply(std::vector<std::string>) override;
};

class AggregateByRegionStep : public Transformation {
    public:
        AggregateByRegionStep():Transformation("aggregate"){};
        Transformation* clone() override;
        std::vector<std::string> apply(std::vector<std::string>) override;
};


#endif // TRANSFORMATION_H