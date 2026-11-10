#pragma once
#include <string>

class Senzor {
private:
#ifdef ORDINE_GRESITA
    int capacitate_;
    int dimensiune_;
#else
    int dimensiune_;
    int capacitate_;
#endif
    const std::string nume_;
    std::string& locatie_;
    double ultimaValoare_;

public:
    Senzor(const std::string& nume, std::string& locatie, int dimensiune);
    void print() const;
};
