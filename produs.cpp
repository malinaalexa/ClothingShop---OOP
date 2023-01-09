#include "produs.h"
#include <iostream>
#include <utility>
Produs::Produs() : pret(pret), nr_buc(nr_buc), redus(redus) {
    pret=0;
    nr_buc=15;
    redus=0;
}

Produs::Produs(std::string denumire,double pret, int nr_buc, int redus)
        : denumire(std::move(denumire)),pret(pret),nr_buc(nr_buc), redus(redus){
}

Produs::Produs(const Produs &other) = default;

Produs &Produs::operator=(const Produs &other) {
    denumire = other.denumire;
    pret = other.pret;
    nr_buc=other.nr_buc;
    redus=other.redus;
    return *this;
}
double Produs::pretprod()
{
    return pret;
}
int Produs::nr_buc_prod()
{
    return nr_buc;
}
void Produs::lichidare_de_stoc()
{
    if(nr_buc<10)
    {
        std::cout<<"Promotie! Pretul este redus cu 20% de doua ori!"<<'\n';
        redus=-1;
        reducere();
        reducere();
    }
}

Produs::~Produs() = default;
