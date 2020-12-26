#ifndef DUCK_HPP
#define DUCK_HPP

#include <memory>
#include <cstdio>
#include "quack.hpp"
#include "fly.hpp"

namespace design_patterns
{
    namespace strategy_pattern
    {
        class Duck
        {
        public:
            Duck(std::shared_ptr<FlyBehavior> flyBehavior,
                 std::shared_ptr<QuackBehavior> quackBehavior)
                : pFlyBehavior(flyBehavior), pQuackBehavior(quackBehavior) {}

            virtual ~Duck() {}

            virtual void display() const = 0;

            void performFly() const { pFlyBehavior->fly(); }

            void performQuack() const { pQuackBehavior->quack(); }

        private:
            std::shared_ptr<FlyBehavior> pFlyBehavior;
            std::shared_ptr<QuackBehavior> pQuackBehavior;
        };

        class MallardDuck : public Duck
        {
        public:
            MallardDuck() : Duck(std::make_shared<FlyWithWings>(), std::make_shared<Quack>()) {}

            void display() const override
            {
                std::fprintf(stdout, "%s\n", "I am a real Mallard duck");
            }
        };

    } // namespace strategy_pattern

    inline void test_strategy_pattern()
    {
        using namespace strategy_pattern;
        std::shared_ptr<Duck> duck = std::make_shared<MallardDuck>();
        duck->display();
        duck->performQuack();
        duck->performFly();
    }

} // namespace design_patterns

#endif
