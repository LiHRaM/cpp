#include "Measurement.h"


bool Measurement::operator<(const Measurement &other) {
    return smaller_than(other);
}

std::ostream &operator<<(std::ostream &os, const Measurement &data) {
    return os << data.to_string();
}

std::unique_ptr<Measurement> Measurement::operator+(const Measurement &other) {
    return plus(other);
}

std::unique_ptr<Measurement> Measurement::operator-(const Measurement &other) {
    return minus(other);
}

std::unique_ptr<Measurement> Measurement::operator=(const Measurement &other) {
    return assign(other);
}

std::unique_ptr<Measurement> Measurement::operator=(std::unique_ptr<Measurement> other) {
    return plus(*other);
}
