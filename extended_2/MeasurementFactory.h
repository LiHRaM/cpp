#pragma once

#include "Measurement.h"

class MeasurementFactory {
   public:
    virtual MeasurementW get_rand() const = 0;
};