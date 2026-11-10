#include <tema2/jurnal.hpp>
#include <tema2/martor.hpp>
#include <tema2/inregistrare.hpp>
#include <tema2/senzor.hpp>
#include <tema2/pereche.hpp>
#include <tema2/obiect_numit.hpp>
#include <tema2/casa.hpp>
#include <cstddef>
#include <iostream>
#include <string>

static int contorStatic;

// FARA_INIT
static void murdaresteStiva() {
    volatile unsigned char gunoi[4096];
    for (std::size_t i = 0; i < sizeof gunoi; ++i) gunoi[i] = 0xAB;
}

static void demoTipuriBuiltIn() {
#ifdef FARA_INIT
    int local;
#else
    int local = 0;
#endif
    std::cout << "contorStatic = " << contorStatic << " (static => 0)\n";
    std::cout << "local        = " << local << '\n';
}

static void demoSenzor() {
    std::string camera("Laborator B418");
    Senzor senzor("Termometru", camera, 8);
    senzor.print();
}

int main() {
    std::cout << "\n===== ITEM 4: initializare inainte de folosire =====\n";

    std::cout << "\n1.Tipuri built-in\n";
    murdaresteStiva();
    demoTipuriBuiltIn();

    std::cout << "\n2.Atribuire in corp vs lista de initializare\n";
    {
        Martor nume("Ion");
        Martor adresa("Timisoara");
        std::cout << "-- InregistrareAtribuire (doi pasi pe membru):\n";
        InregistrareAtribuire a(nume, adresa);
        std::cout << "-- InregistrareLista (un pas pe membru):\n";
        InregistrareLista l(nume, adresa);
        std::cout << "-- sfarsit bloc:\n";
    }

    std::cout << "\n3.Membri const/referinta si ordinea de initializare\n";
    murdaresteStiva();
    demoSenzor();

    std::cout << "\n4.Obiecte statice din fisiere diferite\n";
    jurnal().scrie("main a pornit");
    std::cout << "Mesaje inregistrate: " << jurnal().mesaje() << " (asteptat 2)\n";

    std::cout << "\n===== ITEM 5: ce scrie si apeleaza compilatorul =====\n";

    std::cout << "\n5.Pereche (nicio functie speciala declarata)\n";
    {
        std::cout << "-- Pereche a;      (ctor implicit)\n";
        Pereche a;
        std::cout << "-- Pereche b(a);   (copy ctor)\n";
        Pereche b(a);
        std::cout << "-- b = a;          (operator=)\n";
        b = a;
        std::cout << "-- sfarsit bloc    (destructori)\n";
    }

    std::cout << "\n6.ObiectNumit: membru referinta + membru const\n";
    std::string catelNou("Persephone");
    std::string catelVechi("Satch");
    ObiectNumit<int> p(catelNou, 2);
    ObiectNumit<int> s(catelVechi, 36);
    ObiectNumit<int> c(p);
    p.print();
    s.print();
    c.print();
#ifdef INCEARCA_ATRIBUIRE
    p = s;
#endif

    std::cout << "\n===== ITEM 6: interzicerea functiilor generate =====\n";

    std::cout << "\n7.CasaDeVanzare (stil: "
#if defined(STIL_DELETE)
              << "= delete"
#elif defined(STIL_PRIVAT)
              << "private, nedefinite"
#else
              << "mostenire din Necopiabil"
#endif
              << ")\n";
    CasaDeVanzare h1("Str. Paris 2", 120000);
    CasaDeVanzare h2("Bd. V. Parvan 2", 95000);
    h1.print();
    h2.print();
#ifdef INCEARCA_COPIERE
    CasaDeVanzare h3(h1);
    h1 = h2;
#endif
#ifdef COPIERE_DIN_MEMBRU
    h1.faCopie();
#endif

    std::cout << "\nSfarsit main: destructori\n";
}
