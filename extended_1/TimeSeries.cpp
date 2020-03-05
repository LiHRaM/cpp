#include "TimeSeries.h"

#include <functional>
#include <iostream>
#include <random>

static std::default_random_engine generator;                     // NOLINT(cert-msc32-c,cert-msc51-cpp,cert-err58-cpp)
static std::uniform_int_distribution<int> distribution(1, 100);  // NOLINT(cert-err58-cpp)
static auto get_rand = std::bind(distribution, generator);       // NOLINT(cert-err58-cpp)

TimeSeries TimeSeries::operator+(const TimeSeries& other) const {
    auto& longer = other.value.size() > value.size()
                       ? other.value
                       : value;
    auto& shorter = other.value.size() < value.size()
                        ? other.value
                        : value;
    const int size = longer.size();
    std::vector<int> val{size};
    int i = 0;
    for (; i < shorter.size(); i++) {
        val[i] = longer[i] + shorter[i];
    }
    for (; i < longer.size(); i++) {
        val[i] = longer[i];
    }
    return TimeSeries{std::move(val)};
}

TimeSeries& TimeSeries::operator+=(const TimeSeries& other) {
    *this = *this + other;
    return *this;
}

bool TimeSeries::operator<(const TimeSeries& other) const {
    return this->max - this->min < other.max - other.min;
}

TimeSeries TimeSeries::make_random(const int size) {
    std::vector<int> value{};
    value.reserve(size);
    for (int i = 0; i < size; i++) {
        value.push_back(get_rand());
    }
    return TimeSeries{std::move(value)};
}

TimeSeries::TimeSeries(std::vector<int> value) {
    for (auto& i : value) {
        if (i > max) {
            max = i;
        }
        if (i < min) {
            min = i;
        }
    }
    this->value = std::move(value);
}

void TimeSeries::add_value(const int val) {
    value.push_back(val);
}

std::ostream& operator<<(std::ostream& os, const TimeSeries& series) {
    std::string str{};
    str.push_back('[');
    for (const auto& el : series.value) {
        str.append(std::to_string(el));
        str.push_back(',');
    }
    str.pop_back();
    str.push_back(']');
    return os << str;
}
TimeSeries::TimeSeries() {
    std::vector<int> empty_vec;
    value = empty_vec;
}
