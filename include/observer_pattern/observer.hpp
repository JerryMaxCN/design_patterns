#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "display.hpp"

namespace design_patterns
{
    namespace observer_pattern
    {
        class Subject;
        class Observer
        {
        public:
            virtual ~Observer() {}

            virtual void update(float temp, float humidity, float pressure) = 0;
        };

        class CurrentCoditionDisplay : public Observer, public IDisplay
        {
        public:
            CurrentCoditionDisplay(Subject *subject);

            ~CurrentCoditionDisplay();

            void update(float temp, float humidity, float pressure) override;

            void display() const override;

        private:
            Subject *oSubject;
            float fTemperature;
            float fHumidity;
        };

    } // namespace observer_pattern
} // namespace design_patterns

#endif
