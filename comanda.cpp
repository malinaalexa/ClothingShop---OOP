
#include "comanda.h"
#include<memory>
#include <utility>
#include <vector>
#include "produs.h"

void Comanda::swap(Comanda &obj1, Comanda obj2) {
std::swap(obj1.prod_comandate, obj2.prod_comandate);
}
Comanda &Comanda::operator=(const Comanda&obj) {
    swap(*this, Comanda(obj));
    return *this;
}

Comanda::Comanda(const Comanda&other) {
    for (const auto &Produs: other.prod_comandate)
    prod_comandate.push_back(Produs->clone());

}

std::ostream &operator<<(std::ostream &os, const Comanda &comanda) {
    os <<"Ati comandat produse, in valoare de:" << comanda.valoare;
    return os;
}

void Comanda::calculvaloare()
{int n=prod_comandate.size();
    for(int i=0;i<n;i++)
    {double pret=prod_comandate[i]->pretprod();
    valoare=valoare+pret*nr_buc[i];}
std::cout<<"\nValoarea comenzii: "<<valoare<<" lei \n";}


void Comanda::insert(Produs &prod,int x) {
   prod_comandate.push_back(prod.clone());
   nr_buc.push_back(x);
   prod.edit_stoc(x);
}

Comanda::Comanda(std::vector<std::shared_ptr<Produs>> prod_comandate, double valoare, const Angajat& An_responsabil, std::vector<int> nr_buc)
        : prod_comandate(std::move(prod_comandate)),valoare(valoare), An_responsabil(An_responsabil), nr_buc(std::move(nr_buc)){
}

Comanda::~Comanda() = default;
