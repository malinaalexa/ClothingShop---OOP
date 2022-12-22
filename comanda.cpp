
#include "comanda.h"

Comanda &Comanda::operator=(const Comanda &other) {
    prod_comandate= prod_comandate,other;
    valoare=other.valoare;
    nrproduse = other.nrproduse;
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Comanda &comanda) {
    os << static_cast<const Produs &>(comanda)
       << "Ati comandat:" << comanda.nrproduse << "produse, in valoare de:" << comanda.valoare;
    return os;
}
void Comanda::calculvaloare()
{for(int i=0;i<=nrproduse;i++)
    valoare=valoare+pret*nr_buc;
}