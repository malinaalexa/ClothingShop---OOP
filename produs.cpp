#include "produs.h"
#include <iostream>
#include <utility>
int Produs::urm=0;
Produs::Produs() : id_prod(urm) {
    pret=0;
    nr_buc=15;
    redus=0;
}

Produs::Produs(std::string denumire, double pret, int nr_buc, int redus)
        : denumire(std::move(denumire)), pret(pret), nr_buc(nr_buc), redus(redus) {
}

Produs::Produs(const Produs &other) = default;

Produs &Produs::operator=(const Produs &other) {
    denumire = other.denumire;
    pret = other.pret;
    nr_buc=other.nr_buc;
    redus=other.redus;
    return *this;
}

double Produs::pretprod() const
{
    return pret;
}


std::ostream &operator<<(std::ostream &os, const Produs &Prod) {
    Prod.afis(os);
    return os;
}

 void Produs::afis(std::ostream &ostream) const {
    ostream <<denumire<<" "<<pret<<"lei "<<nr_buc<<" ";
}


Produs::~Produs() = default;