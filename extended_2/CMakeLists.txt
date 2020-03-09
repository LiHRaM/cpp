project(Extended_2)
add_executable(main
        bins/main.cpp
        values.h
        TimeSeries.h TimeSeries.cpp
        TimeSeriesW.h TimeSeriesW.cpp
        Measurement.h Measurement.cpp
        MeasurementW.h Measurement.cpp
        MeasurementFactory.h MeasurementW.cpp
        )