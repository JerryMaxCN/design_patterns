#ifndef QUACK_HPP
#define QUACK_HPP

#include <cstdio>

namespace design_patterns
{
    namespace strategy_pattern
    {
        class QuackBehavior
        {
        public:
            virtual ~QuackBehavior() {}
            virtual void quack() const = 0;
        };

        class Quack : public QuackBehavior
        {
        public:
            void quack() const override
            {
                std::fprintf(stdout, "%s\n", "Quack!");
            }
        };

        class MuteQuack : public QuackBehavior
        {
        public:
            void quack() const override
            {
                std::fprintf(stdout, "%s\n", "Slience!");
            }
        };

        class Squeak : public QuackBehavior
        {
        public:
            void quack() const override
            {
                std::fprintf(stdout, "%s\n", "Squeak!");
            }
        };
    } // namespace strategy_pattern
} // namespace design_patterns

#endif
