#pragma once
#include <memory>
#include <vector>

#include "MeasurementW.h"
#include "MeasurementFactory.h"

class TimeSeries {
   public:
    TimeSeries();
    TimeSeries(const TimeSeries &other) = delete;
    TimeSeries(std::vector<MeasurementW> value);

    static TimeSeries make_random(const MeasurementFactory &factory, int size);

    void add_value(MeasurementW val);

    TimeSeries operator+(const TimeSeries &other) const;
    TimeSeries &operator+=(const TimeSeries &other);
    bool operator<(const TimeSeries &other) const;

   private:
    friend std::ostream &operator<<(std::ostream &os, const TimeSeries &series);
    std::unique_ptr<MeasurementFactory> factory{};
    std::vector<MeasurementW> value{};
    MeasurementW min{};
    MeasurementW max{};
};