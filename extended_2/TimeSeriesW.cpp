#include "TimeSeriesW.h"

#include <memory>

TimeSeries& TimeSeriesW::operator*() {
    return *value;
}

bool TimeSeriesW::operator<(const TimeSeriesW& other) {
    return value < other.value;
}

TimeSeriesW::TimeSeriesW() {
    value = std::make_unique<TimeSeries>(TimeSeries());
}
