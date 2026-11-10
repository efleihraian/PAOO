#pragma once
#include <iostream>
#include <string>

template<typename T>
class ObiectNumit {
public:
    ObiectNumit(std::string& nume, const T& valoare)
        : nume_(nume), valoare_(valoare) {}

    void print() const { std::cout << nume_ << " = " << valoare_ << '\n'; }

private:
    std::string& nume_;
    const T valoare_;
};
