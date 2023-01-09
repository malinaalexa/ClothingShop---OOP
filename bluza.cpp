
#include "bluza.h"
#include "produs.h"
#include <iostream>
#include <utility>
Bluza::Bluza()=default;

Bluza::Bluza(const std::string &denumire, double pret, int nr_buc, int redus,std::string tip) : Produs(denumire,pret,nr_buc,redus), tip(std::move(tip)){}
Bluza &Bluza::operator=(const Bluza &other) {
    denumire = other.denumire;
    pret = other.pret;
    nr_buc=other.nr_buc;
    redus=other.redus;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bluza&produs) {
    os << static_cast<const Produs &>((const Produs &) produs) << produs.denumire << " " << produs.pret<< " " << produs.tip;
    return os;
}

Bluza::Bluza(const Bluza &other): Produs(other) {
    tip = other.tip;
}
void Bluza::reducere()
{
    if(pret>80 && redus<=0 && tip=="tricou")
    {pret=44.99;
        redus++;}
}
std::shared_ptr<Produs> Bluza::clone() const {
    return std::make_shared<Bluza>(*this);
}

Bluza::~Bluza() = default;





