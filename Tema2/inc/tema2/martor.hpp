#pragma once
#include <string>

class Martor {
private:
    std::string nume_;

public:
    Martor();
    explicit Martor(const std::string& nume);
    Martor(const Martor& other);
    Martor& operator=(const Martor& other);
    ~Martor();
};
