#pragma once

#include "../values.h"
#include "Measurement.h"

class TemperatureMeasurement : public Measurement, public TempMeasure {
   public:
    ~TemperatureMeasurement() override = default;
    TemperatureMeasurement() : TempMeasure() {};
    TemperatureMeasurement(double _m) : TempMeasure(_m) {};

    std::string to_string() const override;

   protected:
    bool smaller_than(const Measurement &other) override;
    std::unique_ptr<Measurement> plus(const Measurement &other) override;
    std::unique_ptr<Measurement> minus(const Measurement &other) override;
    std::unique_ptr<Measurement> assign(const Measurement &other) override;
};
