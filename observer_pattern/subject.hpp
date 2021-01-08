#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <list>
#include <memory>

#include "observer.hpp"

namespace design_patterns {

namespace observer_pattern {

class Subject {
public:
    virtual ~Subject() {}

    virtual void registerObserver(Observer *newObserver) = 0;
    virtual void removeObserver(Observer *oldObserver) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherData : public Subject {
public:
    void setMeasurements(float temperature, float humidity, float pressure);

    void registerObserver(Observer *newObserver) override;

    void removeObserver(Observer *oldObserver) override;

    void notifyObservers() override;

private:
    std::list<Observer *> observers;

    float fTemperature;
    float fHumidity;
    float fPressure;
};

}  // namespace observer_pattern

static void testObserverPattern() {
    using namespace observer_pattern;
    WeatherData weatherData;
    CurrentCoditionDisplay currentCoditionDisplay(&weatherData);
    weatherData.setMeasurements(80, 60, 100);
}

}  // namespace design_patterns

#endif
