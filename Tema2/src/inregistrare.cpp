#include <tema2/inregistrare.hpp>

InregistrareAtribuire::InregistrareAtribuire(const Martor& nume, const Martor& adresa) {
    nume_ = nume;
    adresa_ = adresa;
}

InregistrareLista::InregistrareLista(const Martor& nume, const Martor& adresa)
    : nume_(nume), adresa_(adresa) {}
