#pragma once

#include <memory>

#include "TimeSeries.h"

class TimeSeriesW {
   public:
    TimeSeriesW();
    TimeSeries &operator*();
    bool operator<(const TimeSeriesW &other);

   private:
    std::unique_ptr<TimeSeries> value;
};
