#pragma once
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>
#include "velichiny.h"
#include "izmerenie.h"

namespace Pribory {

    using namespace Velichiny;

    class Pribor {
    protected:
        double min_;
        double max_;
        double accuracy_;
        char id_[64];

        Pribor(double min, double max, double accuracy, const char* id, bool)
            : min_(min), max_(max), accuracy_(accuracy) {
            strncpy(id_, id, sizeof(id_) - 1);
            id_[sizeof(id_) - 1] = '\0';
            assert(min_ < max_ && "min >= max");
            assert(accuracy_ > 0.0 && accuracy_ <= 100.0 && "accuracy out of (0,100]");
            assert(id_[0] != '\0' && "empty id");
        }

        double random_value() const {
            return min_ + (double)rand() / RAND_MAX * (max_ - min_);
        }

        double calc_error() const {
            return (accuracy_ / 100.0) * max_;
        }

    public:
        Pribor(double min, double max, double accuracy, const char* id)
            : Pribor(min, max, accuracy, id, true) {}

        virtual ~Pribor() = default;
    };

    class Voltmeter : public Pribor {
    public:
        explicit Voltmeter(double min, double max, double a, const char* id)
            : Pribor(min, max, a, id) {}

        Izmerenie<Volt> izmerit() {
            return Izmerenie<Volt>( time(nullptr), Volt{ random_value() }, calc_error() );
        }
    };

    class Ampermetr : public Pribor {
    public:
        explicit Ampermetr(double min, double max, double a, const char* id)
            : Pribor(min, max, a, id) {}

        Izmerenie<Amper> izmerit() {
            return Izmerenie<Amper>( time(nullptr), Amper{ random_value() }, calc_error() );
        }
    };

    class Multimetr : public Pribor {
    public:
        explicit Multimetr(double min, double max, double a, const char* id)
            : Pribor(min, max, a, id) {}

        Izmerenie<Volt> izmerit_napryazhenie() {
            return Izmerenie<Volt>( time(nullptr), Volt{ random_value() }, calc_error() );
        }

        Izmerenie<Amper> izmerit_tok() {
            return Izmerenie<Amper>( time(nullptr), Amper{ random_value() }, calc_error() );
        }
    };

}
