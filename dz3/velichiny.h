#pragma once
#include <cstdio>

namespace Velichiny {

    struct Volt    { double value; };
    struct Amper   { double value; };
    struct Ohm     { double value; };
    struct Watt    { double value; };
    struct Joule   { double value; };
    struct Sekunda { double value; };

    Volt  operator*(Amper i, Ohm r);
    Volt  operator*(Ohm r, Amper i);
    Amper operator/(Volt u, Ohm r);
    Ohm   operator/(Volt u, Amper i);

    Watt  operator*(Volt u, Amper i);
    Watt  operator*(Amper i, Volt u);
    Watt  operator*(Amper a, Amper b);
    Joule operator*(Watt p, Sekunda t);
    Joule operator*(Sekunda t, Watt p);

    Volt    operator""_V(long double v);
    Amper   operator""_mA(long double v);
    Ohm     operator""_Ohm(long double v);
    Watt    operator""_W(long double v);
    Joule   operator""_J(long double v);
    Sekunda operator""_s(long double v);

}
