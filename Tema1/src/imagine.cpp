#include <tema1/imagine.hpp>
#include <cstring>
#include <iostream>

Imagine::Imagine(const std::string& nume, int latime, int inaltime)
    : nume_(nume), latime_(latime), inaltime_(inaltime),
      pixeli_(new unsigned char[latime * inaltime]()) {
    std::cout << "[ctor] " << nume_ << ": buffer alocat la " << (void*)pixeli_ << '\n';
}

#ifndef FARA_DESTRUCTOR
Imagine::~Imagine() {
    std::cout << "[dtor] " << nume_ << ": eliberez " << (void*)pixeli_ << '\n';
    delete[] pixeli_;
}
#endif

#ifndef SHALLOW_COPY
Imagine::Imagine(const Imagine& other)
    : nume_(other.nume_), latime_(other.latime_), inaltime_(other.inaltime_),
      pixeli_(new unsigned char[other.latime_ * other.inaltime_]) {
    std::memcpy(pixeli_, other.pixeli_, latime_ * inaltime_);
    std::cout << "[copy] " << nume_ << ": pixelii copiati la adresa noua " << (void*)pixeli_ << '\n';
}
#endif

#ifndef FARA_MOVE
Imagine::Imagine(Imagine&& other) noexcept
    : nume_(other.nume_), latime_(other.latime_), inaltime_(other.inaltime_),
      pixeli_(other.pixeli_) {
    other.pixeli_ = nullptr;
    other.latime_ = 0;
    other.inaltime_ = 0;
    std::cout << "[move] " << nume_ << ": preiau bufferul de la " << (void*)pixeli_ << '\n';
}
#endif

void Imagine::setPixel(int x, int y, unsigned char valoare) {
    if (x < 0 || x >= latime_ || y < 0 || y >= inaltime_) {
        std::cout << "Pixel invalid: (" << x << ", " << y << ")\n";
        return;
    }
    pixeli_[y * latime_ + x] = valoare;
}

void Imagine::print() const {
    std::cout << nume_ << " " << latime_ << "x" << inaltime_ << ":";
    for (int i = 0; i < latime_ * inaltime_; ++i) std::cout << ' ' << (int)pixeli_[i];
    std::cout << '\n';
}