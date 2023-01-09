#include "pantaloni.h"
#include "produs.h"
#include <iostream>
#include <utility>
Pantaloni::Pantaloni()=default;

Pantaloni::Pantaloni(const std::string &denumire, double pret, int nr_buc, int redus,std::string lungime,std::string tip) :
        Produs(denumire,pret,nr_buc,redus), lungime(std::move(lungime)),tip(std::move(tip)){}
Pantaloni &Pantaloni::operator=(const Pantaloni &other) {
    denumire = other.denumire;
    pret = other.pret;
    nr_buc=other.nr_buc;
    redus=other.redus;
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Pantaloni&produs) {
    os << static_cast<const Produs &>((const Produs &) produs) << produs.denumire << " " << produs.pret<< " " << produs.lungime<<" "<<produs.tip;
    return os;
}

Pantaloni::Pantaloni(const Pantaloni &other): Produs(other) {
    lungime = other.lungime;
}
void Pantaloni::reducere()
{   if(pret>90 && redus<=0 && tip=="trening")
    {pret=pret-pret*0.5;
        redus++;}
    if(pret>70 && redus<=0 && lungime=="scurti")
    {pret=pret-pret*0.3;
        redus++;}
}
std::shared_ptr<Produs> Pantaloni::clone() const {
    return std::make_shared<Pantaloni>(*this);
}

Pantaloni::~Pantaloni() = default;
