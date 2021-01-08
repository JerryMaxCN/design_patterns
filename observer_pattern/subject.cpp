#include "subject.hpp"

#include "observer.hpp"

namespace design_patterns {

namespace observer_pattern {

void WeatherData::setMeasurements(float temperature, float humidity,
                                  float pressure) {
    fTemperature = temperature;
    fHumidity = humidity;
    fPressure = pressure;
    notifyObservers();
}

void WeatherData::registerObserver(Observer *newObserver) {
    observers.push_back(newObserver);
}

void WeatherData::removeObserver(Observer *oldObserver) {
    observers.remove(oldObserver);
}

void WeatherData::notifyObservers() {
    for (auto observer : observers) {
        observer->update(fTemperature, fHumidity, fPressure);
    }
}

}  // namespace observer_pattern

}  // namespace design_patterns
