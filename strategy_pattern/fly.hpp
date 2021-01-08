#ifndef FLY_HPP
#define FLY_HPP

#include <cstdio>

namespace design_patterns {

namespace strategy_pattern {

class IFlyBehavior {
public:
    virtual ~IFlyBehavior() {}

    virtual void fly() const = 0;
};

class FlyWithWings : public IFlyBehavior {
public:
    void fly() const override { std::fprintf(stdout, "%s\n", "I'm flying!"); }
};

class FlyNoWay : public IFlyBehavior {
public:
    void fly() const override { std::fprintf(stdout, "%s\n", "I cannot fly!"); }
};

}  // namespace strategy_pattern

}  // namespace design_patterns

#endif
