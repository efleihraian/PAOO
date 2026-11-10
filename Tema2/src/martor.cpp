#include <tema2/martor.hpp>
#include <iostream>

Martor::Martor() : nume_("anonim") {
    std::cout << "  [Martor " << nume_ << "] ctor implicit\n";
}

Martor::Martor(const std::string& nume) : nume_(nume) {
    std::cout << "  [Martor " << nume_ << "] ctor\n";
}

Martor::Martor(const Martor& other) : nume_(other.nume_) {
    std::cout << "  [Martor " << nume_ << "] copy ctor\n";
}

Martor& Martor::operator=(const Martor& other) {
    std::cout << "  [Martor " << nume_ << "] operator= (devine " << other.nume_ << ")\n";
    nume_ = other.nume_;
    return *this;
}

Martor::~Martor() {
    std::cout << "  [Martor " << nume_ << "] dtor\n";
}
