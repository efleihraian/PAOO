#pragma once
#include <string>
#ifdef STIL_NECOPIABIL
#include <tema2/necopiabil.hpp>
#endif

#if !defined(STIL_DELETE) && !defined(STIL_PRIVAT) && !defined(STIL_NECOPIABIL)
#error "STIL_COPIERE trebuie sa fie DELETE, PRIVAT sau NECOPIABIL"
#endif

class CasaDeVanzare
#ifdef STIL_NECOPIABIL
    : private Necopiabil
#endif
{
public:
    CasaDeVanzare(const std::string& adresa, int pret);

#ifdef STIL_DELETE
    CasaDeVanzare(const CasaDeVanzare&) = delete;
    CasaDeVanzare& operator=(const CasaDeVanzare&) = delete;
#endif

    void print() const;

#ifdef COPIERE_DIN_MEMBRU
    void faCopie() const;
#endif

private:
#ifdef STIL_PRIVAT
    CasaDeVanzare(const CasaDeVanzare&);
    CasaDeVanzare& operator=(const CasaDeVanzare&);
#endif

    std::string adresa_;
    int pret_;
};
