#include "observer.hpp"
#include "subject.hpp"
#include <cstdio>

namespace design_patterns {

namespace observer_pattern {

CurrentCoditionDisplay::CurrentCoditionDisplay(Subject *subject) {
    oSubject = subject;
    oSubject->registerObserver(this);
}

CurrentCoditionDisplay::~CurrentCoditionDisplay() {
    oSubject->removeObserver(this);
}

void CurrentCoditionDisplay::update(float temp, float humidity, float pressure) {
    fTemperature = temp;
    fHumidity = humidity;
    display();
}

void CurrentCoditionDisplay::display() const {
    std::fprintf(stdout, "Current conditions: %fF degrees and %f humidity\n", fTemperature, fHumidity);
}

} // namespace observer_pattern

} // namespace design_patterns
