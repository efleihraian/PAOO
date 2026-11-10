#pragma once

class Jurnal {
private:
    bool construit_;
    int mesaje_;

public:
    Jurnal();
    void scrie(const char* mesaj);
    int mesaje() const;
};

#ifdef JURNAL_GLOBAL
extern Jurnal jurnalGlobal;
#endif

Jurnal& jurnal();
