#include "velichiny.h"

namespace Velichiny {

    Volt operator*(Amper i, Ohm r)  { return Volt{ i.value * r.value }; }
    Volt operator*(Ohm r, Amper i)  { return Volt{ r.value * i.value }; }

    Amper operator/(Volt u, Ohm r) { return Amper{ u.value / r.value }; }
    Ohm   operator/(Volt u, Amper i) { return Ohm{ u.value / i.value }; }

    Watt operator*(Volt u, Amper i)  { return Watt{ u.value * i.value }; }
    Watt operator*(Amper i, Volt u)  { return Watt{ i.value * u.value }; }
    Watt operator*(Amper a, Amper b) { return Watt{ a.value * b.value }; }

    Joule operator*(Watt p, Sekunda t) { return Joule{ p.value * t.value }; }
    Joule operator*(Sekunda t, Watt p) { return Joule{ t.value * p.value }; }

    Volt    operator""_V(long double v)   { return Volt{ (double)v }; }
    Amper   operator""_mA(long double v)  { return Amper{ (double)v / 1000.0 }; }
    Ohm     operator""_Ohm(long double v) { return Ohm{ (double)v }; }
    Watt    operator""_W(long double v)   { return Watt{ (double)v }; }
    Joule   operator""_J(long double v)   { return Joule{ (double)v }; }
    Sekunda operator""_s(long double v)   { return Sekunda{ (double)v }; }

}
