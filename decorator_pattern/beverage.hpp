#ifndef BEVERAGE_HPP
#define BEVERAGE_HPP

#include <string>

namespace design_patterns {

namespace decorator_pattern {

class Beverage {
public:
    Beverage(std::string desc) : sDesc(desc) {}
    virtual ~Beverage() {}

    std::string getDescription() const { return sDesc; }

    virtual double cost() const = 0;

private:
    std::string sDesc{"Unknown Beverage"};
};

class Espresso : public Beverage {
public:
    Espresso() : Beverage("Espresso") {}

    double cost() const override { return 1.99; }
};

class HouseBlend : public Beverage {
public:
    HouseBlend() : Beverage("House Blend Coffee") {}

    double cost() const override { return 0.89; }
};

}  // namespace decorator_pattern

}  // namespace design_patterns

#endif
