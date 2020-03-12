#pragma once

#include <memory>
#include <string>

class Measurement {
   public:
    virtual ~Measurement() {};
    virtual std::string to_string() const = 0;

    bool operator<(const Measurement &other);
    std::unique_ptr<Measurement> operator+(const Measurement &other);
    std::unique_ptr<Measurement> operator-(const Measurement &other);
    std::unique_ptr<Measurement> operator=(const Measurement &other);
    std::unique_ptr<Measurement> operator=(std::unique_ptr<Measurement> other);
    friend std::ostream &operator<<(std::ostream &os, const Measurement &data);

   protected:
    virtual bool smaller_than(const Measurement &other) = 0;
    virtual std::unique_ptr<Measurement> plus(const Measurement &other) = 0;
    virtual std::unique_ptr<Measurement> minus(const Measurement &other) = 0;
    virtual std::unique_ptr<Measurement> assign(const Measurement &other) = 0;
};
