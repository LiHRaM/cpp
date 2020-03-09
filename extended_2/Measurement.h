#pragma once

#include <string>
#include <memory>

class Measurement {
   public:
    bool operator<(const Measurement &other);
    std::unique_ptr<Measurement> operator+(const Measurement &other);
    std::unique_ptr<Measurement> operator-(const Measurement &other);
    std::unique_ptr<Measurement> operator=(const Measurement &other);
    std::unique_ptr<Measurement> operator=(std::unique_ptr<Measurement> other);

    friend std::ostream &operator<<(std::ostream &os, const Measurement &data);

    virtual std::string to_string() const = 0;
    virtual ~Measurement() = 0;

   private:
    virtual bool smaller_than(const Measurement &other) = 0;
    virtual std::unique_ptr<Measurement> plus(const Measurement &other) = 0;
    virtual std::unique_ptr<Measurement> minus(const Measurement &other) = 0;
    virtual std::unique_ptr<Measurement> assign(const Measurement &other) = 0;
};

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
