
#ifndef OOP_COMANDA_H
#define OOP_COMANDA_H
#include "produs.h"
#include <iostream>
#include<vector>
#include <memory>
#include "rochie.h"
#include "bluza.h"
#include "pantaloni.h"
class Comanda {
    std::vector<std::shared_ptr<Produs>> prod_comandate;
    double valoare=0;
    int nrproduse{};
public:
    Comanda();
    Comanda &operator=(const Comanda &obj);
    Comanda(const Comanda &other);
    explicit Comanda(const std::vector<std::shared_ptr<Produs>> &prodComandate);
    friend std::ostream &operator<<(std::ostream &os, const Comanda&comanda);
    friend void swap(Comanda &obj1, Comanda &obj2);
    void calculvaloare();
    void insert(Produs &prod);
    virtual ~Comanda();
};


#endif //OOP_COMANDA_H
