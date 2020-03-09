#pragma once
#include <memory>
#include <vector>

#include "MeasurementFactory.h"
#include "MeasurementW.h"

class TimeSeries {
   public:
    TimeSeries();
    ~TimeSeries() = default;
    explicit TimeSeries(std::vector<MeasurementW> value);

    // Delete the copy constructor
    TimeSeries(const TimeSeries &other) = delete;

    // Move constructor
    TimeSeries(TimeSeries &&other) = default;

    static TimeSeries make_random(const MeasurementFactory &factory, int size);

    void add_value(MeasurementW val);

    TimeSeries operator+(const TimeSeries &other) const;
    TimeSeries &operator+=(const TimeSeries &other);
    TimeSeries &operator=(TimeSeries &&other);
    bool operator<(const TimeSeries &other) const;

   private:
    friend std::ostream &operator<<(std::ostream &os, const TimeSeries &series);
    std::unique_ptr<MeasurementFactory> factory{};
    std::vector<MeasurementW> value{};
    MeasurementW min{};
    MeasurementW max{};
};