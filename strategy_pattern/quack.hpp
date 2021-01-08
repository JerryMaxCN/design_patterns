#ifndef QUACK_HPP
#define QUACK_HPP

#include <cstdio>

namespace design_patterns {

namespace strategy_pattern {

class IQuackBehavior {
public:
    virtual ~IQuackBehavior() {}

    virtual void quack() const = 0;
};

class Quack : public IQuackBehavior {
public:
    void quack() const override { std::fprintf(stdout, "%s\n", "Quack!"); }
};

class MuteQuack : public IQuackBehavior {
public:
    void quack() const override { std::fprintf(stdout, "%s\n", "Slience!"); }
};

class Squeak : public IQuackBehavior {
public:
    void quack() const override { std::fprintf(stdout, "%s\n", "Squeak!"); }
};

}  // namespace strategy_pattern

}  // namespace design_patterns

#endif
