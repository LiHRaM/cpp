#pragma once

#include <memory>

#include "Measurement.h"
class MeasurementW {
   public:
    MeasurementW() = default;
    MeasurementW(const MeasurementW& other) = delete;
    MeasurementW(MeasurementW&& other) = default;
    Measurement& operator*() const;

   private:
    std::unique_ptr<Measurement> value{};
};
