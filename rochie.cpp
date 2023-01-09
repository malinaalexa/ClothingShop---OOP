
#include "rochie.h"
#include "produs.h"
#include <iostream>
#include <utility>
Rochie::Rochie()=default;

Rochie::Rochie(const std::string &denumire, double pret, int nr_buc, int redus,std::string lungime) : Produs(denumire,pret,nr_buc,redus), lungime(std::move(lungime)){}
Rochie &Rochie::operator=(const Rochie &other) {
    denumire = other.denumire;
    pret = other.pret;
    nr_buc=other.nr_buc;
    redus=other.redus;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Rochie&produs) {
    os << static_cast<const Produs &>((const Produs &) produs) << produs.denumire << " " << produs.pret<< " " << produs.lungime;
    return os;
}

Rochie::Rochie(const Rochie &other): Produs(other) {
    lungime = other.lungime;
}
void Rochie::reducere()
{
    if(pret>180 && redus<=0)
    {pret=pret-pret*0.2;
        redus++;}
}
std::shared_ptr<Produs> Rochie::clone() const {
    return std::make_shared<Rochie>(*this);
}

Rochie::~Rochie() = default;





