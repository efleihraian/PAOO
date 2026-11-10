#include <tema2/jurnal.hpp>
#include <iostream>

namespace {
struct Pornire {
    Pornire() { jurnal().scrie("pornire: configurare citita (inainte de main)"); }
};

Pornire pornire;
}
