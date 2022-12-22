
#ifndef OOP_COMANDA_H
#define OOP_COMANDA_H
#include "produs.h"
#include <iostream>
#include <vector>
class Comanda: public Produs {
    std::vector<Produs> prod_comandate;
    double valoare=0;
    int nrproduse;
public:
    Comanda();
    Comanda(double valoare, int nrproduse);
    Comanda(const Comanda &other);
    Comanda& operator=(const Comanda &other);
    friend std::ostream &operator<<(std::ostream &os, const Comanda&comanda);
   // ~Comanda() override;

    void calculvaloare();
};


#endif //OOP_COMANDA_H
