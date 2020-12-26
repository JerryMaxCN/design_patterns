#ifndef FLY_HPP
#define FLY_HPP

#include <cstdio>

namespace design_patterns
{
    namespace strategy_pattern
    {
        class FlyBehavior
        {
        public:
            virtual ~FlyBehavior() {}

            virtual void fly() const = 0;
        };

        class FlyWithWings : public FlyBehavior
        {
        public:
            void fly() const override
            {
                std::fprintf(stdout, "%s\n", "I'm flying!");
            }
        };

        class FlyNoWay : public FlyBehavior
        {
        public:
            void fly() const override
            {
                std::fprintf(stdout, "%s\n", "I cannot fly!");
            }
        };
    } // namespace strategy_pattern
} // namespace design_patterns

#endif
