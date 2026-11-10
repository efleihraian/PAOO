#include <tema2/senzor.hpp>
#include <iostream>

Senzor::Senzor(const std::string& nume, std::string& locatie, int dimensiune)
    : dimensiune_(dimensiune),
      capacitate_(dimensiune_ * 2),   // ORDINE_GRESITA
      nume_(nume),
      locatie_(locatie)
#ifndef FARA_INIT
      , ultimaValoare_(0.0)
#endif
{}

void Senzor::print() const {
    std::cout << nume_ << " @ " << locatie_
              << ": dimensiune=" << dimensiune_
              << " capacitate=" << capacitate_
              << " ultimaValoare=" << ultimaValoare_ << '\n';
}
