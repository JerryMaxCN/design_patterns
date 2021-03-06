#ifndef DUCK_HPP
#define DUCK_HPP

#include <cstdio>
#include <memory>

#include "fly.hpp"
#include "quack.hpp"

namespace design_patterns {

namespace strategy_pattern {

class Duck {
public:
    Duck(std::shared_ptr<IFlyBehavior> flyBehavior,
         std::shared_ptr<IQuackBehavior> quackBehavior)
        : pFlyBehavior(flyBehavior), pQuackBehavior(quackBehavior) {}

    virtual ~Duck() {}

    virtual void display() const = 0;

    void setFlyBehavior(std::shared_ptr<IFlyBehavior> newFlyBehavior) {
        pFlyBehavior = newFlyBehavior;
    }
    void setQuackBehavior(std::shared_ptr<IQuackBehavior> newQuackBehavior) {
        pQuackBehavior = newQuackBehavior;
    }

    void performFly() const { pFlyBehavior->fly(); }
    void performQuack() const { pQuackBehavior->quack(); }

private:
    std::shared_ptr<IFlyBehavior> pFlyBehavior;
    std::shared_ptr<IQuackBehavior> pQuackBehavior;
};

class MallardDuck : public Duck {
public:
    MallardDuck()
        : Duck(std::make_shared<FlyWithWings>(), std::make_shared<Quack>()) {}

    void display() const override {
        std::fprintf(stdout, "%s\n", "I am a real Mallard duck");
    }
};

}  // namespace strategy_pattern

inline void testStrategyPattern() {
    using namespace strategy_pattern;
    std::shared_ptr<Duck> duck = std::make_shared<MallardDuck>();
    duck->display();
    duck->performQuack();
    duck->performFly();

    duck->setFlyBehavior(std::make_shared<FlyNoWay>());
    duck->setQuackBehavior(std::make_shared<MuteQuack>());
    duck->performQuack();
    duck->performFly();
}

}  // namespace design_patterns

#endif
