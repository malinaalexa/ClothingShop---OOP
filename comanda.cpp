
#include "comanda.h"
Comanda::Comanda() = default;
Comanda &Comanda::operator=(const Comanda&obj) {
   Comanda temp(obj);
   swap(*this, temp);
  return *this;
}
void swap(Comanda &obj1, Comanda &obj2) {
std::swap(obj1.prod_comandate, obj2.prod_comandate);

}
Comanda::Comanda(const Comanda&other) {
   for (auto &Produs: other.prod_comandate)
    prod_comandate.push_back(Produs->clone());

}

std::ostream &operator<<(std::ostream &os, const Comanda &comanda) {
    os <<"Ati comandat:" << comanda.nrproduse << "produse, in valoare de:" << comanda.valoare;
    return os;
}

Comanda::Comanda(const std::vector<std::shared_ptr<Produs>> &prodComandate) : prod_comandate(prodComandate) {}


void Comanda::calculvaloare()
{for(int i=0;i<=nrproduse;i++)
    {double pret=prod_comandate[i]->pretprod();
    int buc=prod_comandate[i]->nr_buc_prod();
    valoare=valoare+pret*buc;}
}
Comanda::~Comanda() = default;
void Comanda::insert(Produs &prod) {
   prod_comandate.push_back(prod.clone());
}

