#include <tema2/casa.hpp>
#include <iostream>

CasaDeVanzare::CasaDeVanzare(const std::string& adresa, int pret)
    : adresa_(adresa), pret_(pret) {}

void CasaDeVanzare::print() const {
    std::cout << "Casa " << adresa_ << ", " << pret_ << " EUR\n";
}

#ifdef COPIERE_DIN_MEMBRU
void CasaDeVanzare::faCopie() const {
    CasaDeVanzare copie(*this);
    copie.print();
}
#endif
