#pragma once

#include "../Measurements/StockMeasurement.h"
#include "MeasurementFactory.h"

class StockMeasurementFactory : public MeasurementFactory {
    MeasurementW get_rand() const override;
};
