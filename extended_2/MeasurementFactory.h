#pragma once

#include "MeasurementW.h"

class MeasurementFactory {
   public:
    virtual ~MeasurementFactory() = 0;
    virtual MeasurementW get_rand() const = 0;
};