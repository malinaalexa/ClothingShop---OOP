
#include "rochie.h"
#include "produs.h"
#include <iostream>
#include <utility>
Rochie::Rochie()=default;

Rochie::Rochie(const std::string &denumire, double pret, int nr_buc, int redus,std::string lungime) : Produs(denumire,
                                                                                                             pret,
                                                                                                             nr_buc,
                                                                                                             redus), lungime(std::move(lungime)){}
Rochie &Rochie::operator=(const Rochie &other) {
    denumire = other.denumire;
    pret = other.pret;
    nr_buc=other.nr_buc;
    redus=other.redus;

    return *this;
}



Rochie::Rochie(const Rochie &other): Produs(other),lungime(other.lungime) {

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
std::string Rochie::getlungime()
{
    return lungime;
}
void Rochie::setLungime(const std::string& lung1) {
    if (lung1 == "Scurta" || lung1 == "Lunga" || lung1 == "Midi") {
        this->lungime = lung1;
    } else {
        throw std::invalid_argument("Invalid tip value");
    }
}
Rochie::~Rochie() = default;





