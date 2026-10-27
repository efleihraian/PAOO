#pragma once
#include <string>

class Imagine {
private:
    const std::string nume_;
    int latime_;
    int inaltime_;
    unsigned char* pixeli_;

public:
    Imagine(const std::string& nume, int latime, int inaltime);
#ifndef FARA_DESTRUCTOR
    ~Imagine();
#endif
#ifdef SHALLOW_COPY
    Imagine(const Imagine& other) = default;
#else
    Imagine(const Imagine& other);
#endif
#ifndef FARA_MOVE
    Imagine(Imagine&& other) noexcept;
#endif

    void setPixel(int x, int y, unsigned char valoare);
    void print() const;
};