#include "TemperatureMeasurementFactory.h"

MeasurementW TemperatureMeasurementFactory::get_rand() const {
    return MeasurementW{std::make_unique<TemperatureMeasurement>(TemperatureMeasurement{})};
}
