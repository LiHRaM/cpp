#pragma once

#include "../MeasurementW.h"

class MeasurementFactory {
   public:
    virtual ~MeasurementFactory() = default;
    virtual MeasurementW get_rand() const = 0;
};