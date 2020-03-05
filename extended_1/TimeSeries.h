#pragma once
#include <memory>
#include <vector>

class TimeSeries {
   public:
    TimeSeries();
    TimeSeries(const TimeSeries &other) = default;
    explicit TimeSeries(std::vector<int> value);

    static TimeSeries make_random(int size);

    void add_value(int val);

    TimeSeries operator+(const TimeSeries &other) const;
    TimeSeries &operator+=(const TimeSeries &other);
    bool operator<(const TimeSeries &other) const;

   private:
    friend std::ostream &operator<<(std::ostream &os, const TimeSeries &series);
    std::vector<int> value;
    int min{};
    int max{};
};