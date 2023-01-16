
#include "comanda.h"
#include<memory>
#include <vector>
#include "rochie.h"
#include "bluza.h"
#include "pantaloni.h"
#include "produs.h"
Comanda::Comanda() = default;

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
    os <<"Ati comandat:" << comanda.nrproduse << "produse, in valoare de:" << comanda.valoare;
    return os;
}

Comanda::Comanda(const std::vector<std::shared_ptr<Produs>> &prodComandate) : prod_comandate(prodComandate) {}


void Comanda::calculvaloare()
{int n=prod_comandate.size();
    for(int i=0;i<n;i++)
    {double pret=prod_comandate[i]->pretprod();
    int buc=prod_comandate[i]->nr_buc_prod();
    valoare=valoare+pret*buc;}
}
Comanda::~Comanda() = default;
void Comanda::insert(const Produs &prod) {
   prod_comandate.push_back(prod.clone());
}

