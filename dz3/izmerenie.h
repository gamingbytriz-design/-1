#pragma once
#include <ctime>

template<typename T>
class Izmerenie {
    time_t time_;
    T value_;
    double error_;

public:
    Izmerenie(time_t t, T v, double e)
        : time_(t), value_(v), error_(e) {}

    T value() const { return value_; }
    double error() const { return error_; }
    time_t time() const { return time_; }
};
