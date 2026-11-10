#pragma once
#include <tema2/martor.hpp>

class InregistrareAtribuire {
private:
    Martor nume_;
    Martor adresa_;

public:
    InregistrareAtribuire(const Martor& nume, const Martor& adresa);
};

class InregistrareLista {
private:
    Martor nume_;
    Martor adresa_;

public:
    InregistrareLista(const Martor& nume, const Martor& adresa);
};
