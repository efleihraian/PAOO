#include <tema2/jurnal.hpp>
#include <iostream>

Jurnal::Jurnal() : construit_(true), mesaje_(0) {
    std::cout << "[Jurnal] construit, contor pus pe 0\n";
}

void Jurnal::scrie(const char* mesaj) {
    ++mesaje_;
    std::cout << (construit_ ? "[Jurnal] " : "[Jurnal NECONSTRUIT!] ") << mesaj << '\n';
}

int Jurnal::mesaje() const {
    return mesaje_;
}

#ifdef JURNAL_GLOBAL
Jurnal jurnalGlobal;
Jurnal& jurnal() { return jurnalGlobal; }
#else
Jurnal& jurnal() {
    static Jurnal j;
    return j;
}
#endif
