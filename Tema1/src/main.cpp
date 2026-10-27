#include <tema1/imagine.hpp>
#include <iostream>
#include <utility>

int main() {
    std::cout << "1.Constructor si incapsulare\n";
    Imagine poza("Poza", 3, 2);
    poza.setPixel(0, 0, 100);
    poza.setPixel(2, 1, 200);
    poza.setPixel(9, 9, 50);
    poza.print();

    std::cout << "\n2.Destructor\n";
    {
        Imagine temp("Temporara", 1000, 1000);
    }

    std::cout << "\n3.Copy constructor\n"; 
    Imagine copie = poza;
    copie.setPixel(0, 0, 255);
    std::cout << "Original: "; poza.print();
    std::cout << "Copie:    "; copie.print();

    std::cout << "\n4.Move constructor\n";
    Imagine mutata = std::move(copie);
    std::cout << "Copie:   "; copie.print();
    std::cout << "Mutata:  "; mutata.print();

    std::cout << "\nSfarsit main: destructori\n";
}