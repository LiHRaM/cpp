#include "TemperatureMeasurement.h"
std::string TemperatureMeasurement::to_string() const {
    return std::to_string(double());
}
bool TemperatureMeasurement::smaller_than(const Measurement& other) {
    return false;
}
std::unique_ptr<Measurement> TemperatureMeasurement::plus(const Measurement& other) {
    return std::unique_ptr<Measurement>();
}
std::unique_ptr<Measurement> TemperatureMeasurement::minus(const Measurement& other) {
    return std::unique_ptr<Measurement>();
}
std::unique_ptr<Measurement> TemperatureMeasurement::assign(const Measurement& other) {
    return std::unique_ptr<Measurement>();
}
