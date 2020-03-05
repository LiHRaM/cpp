#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

#include "../TimeSeries.h"

template <typename F>
void time_lambda(const F& to_time) {
    auto start = std::chrono::system_clock::now();
    to_time();
    auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = stop - start;
    std::cout << "Performance: " << diff.count() << std::endl;
}

int main() {
    std::vector<TimeSeries> series{100000};
    for (auto& el : series) {
        el = TimeSeries::make_random(100);
    }
    time_lambda([&] {
        std::sort(series.begin(), series.end());
    });
}
