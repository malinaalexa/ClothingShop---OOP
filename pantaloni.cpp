#include "pantaloni.h"
#include "produs.h"
#include <iostream>
#include <utility>
Pantaloni::Pantaloni()=default;

Pantaloni::Pantaloni(const std::string &denumire, double pret, int nr_buc, int redus,std::string lungime,std::string tip) :
        Produs(denumire, pret, nr_buc, redus), lungime(std::move(lungime)), tip(std::move(tip)){}
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

Pantaloni::Pantaloni(const Pantaloni &other): Produs(other), lungime(other.lungime){
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
std::string Pantaloni::gettip()
{
    return tip;
}
void Pantaloni::setTip(const std::string& tip1) {
    if (tip1 == "Blugi" || tip1 == "Eleganti" || tip1 == "Trening") {
        this->tip = tip1;
    } else {
        throw std::invalid_argument("Invalid value");
    }
}
std::string Pantaloni::getlungime()
{
    return lungime;
}
void Pantaloni::setLungime(const std::string& lung1) {
    if (lung1 == "Scurti" || lung1 == "Lungi") {
        this->lungime = lung1;
    } else {
        throw std::invalid_argument("Invalid tip value");
    }
}
Pantaloni::~Pantaloni() = default;
