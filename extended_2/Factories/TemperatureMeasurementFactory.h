#pragma once

#include "../Measurements/TemperatureMeasurement.h"
#include "MeasurementFactory.h"

class TemperatureMeasurementFactory : public MeasurementFactory {
   public:
    MeasurementW get_rand() const override;
};
