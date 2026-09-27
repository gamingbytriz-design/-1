#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "velichiny.h"
#include "pribory.h"

using namespace Velichiny;
using namespace Pribory;

template<typename T>
void print_izmerenie(const char* label, const Izmerenie<T>& m) {
    printf("%svalue = %.4f, error = ±%.4f, time = %ld\n",
           label, m.value().value, m.error(), (long)m.time());
}

void primer_oma() {
    printf("=== Ohm's law ===\n");
    auto u = 12.0_V;
    auto r = 4.0_Ohm;
    auto i = u / r;
    printf("U = %.2f, R = %.2f, I = %.2f\n\n", u.value, r.value, i.value);
}

void primer_moshchnosti() {
    printf("=== Power and work ===\n");
    auto u = 220.0_V;
    auto i = 0.5_mA;
    auto p = u * i;
    auto t = 10.0_s;
    auto a = p * t;
    printf("P = %.4f, A = %.4f\n\n", p.value, a.value);
}

void primer_voltmetra() {
    printf("=== Voltmeter ===\n");
    Voltmeter v(0.0, 1000.0, 0.5, "V-001");
    print_izmerenie("Voltage: ", v.izmerit());
    printf("\n");
}

void primer_ampermetra() {
    printf("=== Ampermetr ===\n");
    Ampermetr a(0.0, 10.0, 1.0, "A-001");
    print_izmerenie("Current: ", a.izmerit());
    printf("\n");
}

void primer_multimetra() {
    printf("=== Multimetr ===\n");
    Multimetr mm(0.0, 500.0, 0.2, "MM-001");
    print_izmerenie("Voltage: ", mm.izmerit_napryazhenie());
    print_izmerenie("Current: ", mm.izmerit_tok());
    printf("\n");
}

void primer_invariantov() {
    printf("=== Invariants (assert) ===\n");
    printf("Invalid parameters will trigger assert.\n");
}

int main() {
    srand((unsigned)time(nullptr));

    primer_oma();
    primer_moshchnosti();
    primer_voltmetra();
    primer_ampermetra();
    primer_multimetra();
    primer_invariantov();

    return 0;
}
