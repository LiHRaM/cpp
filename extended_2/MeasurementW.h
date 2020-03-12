#pragma once

#include <memory>

#include "Measurements/Measurement.h"
class MeasurementW {
   public:
    MeasurementW() = default;
    MeasurementW(const MeasurementW& other) = delete;
    MeasurementW(MeasurementW&& other) noexcept : value{std::move(other.value)} {};
    MeasurementW(std::unique_ptr<Measurement>&& m) noexcept : value{std::move(m)} {};
    Measurement& operator*() const;

   private:
    std::unique_ptr<Measurement> value{};
};
