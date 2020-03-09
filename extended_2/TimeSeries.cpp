#include "TimeSeries.h"

#include <functional>
#include <random>

TimeSeries TimeSeries::operator+(const TimeSeries& other) const {
    auto& longer = other.value.size() > value.size()
                       ? other.value
                       : value;
    auto& shorter = other.value.size() < value.size()
                        ? other.value
                        : value;
    const int size = longer.size();
    std::vector<MeasurementW> measurements{};
    measurements.reserve(size);
    int i = 0;
    for (; i < shorter.size(); i++) {
        *measurements[i] = *longer[i] + *shorter[i];
    }
    for (; i < longer.size(); i++) {
        *measurements[i] = *longer[i];
    }
    return TimeSeries{std::move(measurements)};
}

TimeSeries& TimeSeries::operator+=(const TimeSeries& other) {
    return *this = *this + other;
}

bool TimeSeries::operator<(const TimeSeries& other) const {
    return *max - *min < *other.max - *other.min;
}

void TimeSeries::add_value(MeasurementW& val) {
    value.push_back(std::move(val));
}

std::ostream& operator<<(std::ostream& os, const TimeSeries& series) {
    std::string str{"TimeSeries ["};
    for (auto& el : series.value) {
        str.append((*el).to_string());
        str.push_back(',');
    }
    str.pop_back();
    str.push_back(']');
    return os << str;
}

TimeSeries TimeSeries::make_random(const MeasurementFactory& factory, int size) {
    std::vector<MeasurementW> measurements{};
    measurements.reserve(size);
    for (int i = 0; i < size; i++) {
        measurements.push_back(factory.get_rand());
    }
    return TimeSeries{std::move(measurements)};
}

TimeSeries& TimeSeries::operator=(TimeSeries&& other) {
    if (this != &other) {
        value = std::exchange(other.value, std::vector<MeasurementW>{});
    }
    return *this;
}

TimeSeries::TimeSeries(std::vector<MeasurementW>&& value) {
    for (auto& i : value) {
        if (*max < *i) {
            *max = *i;
        }
        if (*i < *max) {
            *min = *i;
        }
    }
    this->value = std::move(value);
}
