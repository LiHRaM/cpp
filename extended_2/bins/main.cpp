#include <iostream>

#include "../Factories/TemperatureMeasurementFactory.h"
#include "../TimeSeries.h"

int main() {
    auto measurement = TemperatureMeasurement{};
    std::cout << measurement << std::endl;
//    auto factory = TemperatureMeasurementFactory{};
//    auto time_series = TimeSeries::make_random(factory, 25);
//    std::cout << time_series << std::endl;
    return 0;
}