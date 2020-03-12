project(Extended_2)
add_executable(main
        bins/main.cpp
        values.h
        TimeSeries.h TimeSeries.cpp
        TimeSeriesW.h TimeSeriesW.cpp
        Measurements/Measurement.h Measurements/Measurement.cpp
        MeasurementW.h Measurements/Measurement.cpp
        Factories/MeasurementFactory.h MeasurementW.cpp
        Measurements/TemperatureMeasurement.cpp Measurements/TemperatureMeasurement.h
        Measurements/StockMeasurement.cpp Measurements/StockMeasurement.h Factories/StockMeasurementFactory.cpp Factories/StockMeasurementFactory.h Factories/TemperatureMeasurementFactory.cpp Factories/TemperatureMeasurementFactory.h)