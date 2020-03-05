#pragma once

#include <memory>

#include "Measurement.h"
class MeasurementW {
   public:
    Measurement &operator*() const;

   private:
    std::unique_ptr<Measurement> value{};
};
