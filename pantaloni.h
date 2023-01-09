
#ifndef OOP_PANTALONI_H
#define OOP_PANTALONI_H
#include "produs.h"
#include <iostream>
#include <memory>

class Pantaloni: public Produs {
protected:

    std::string lungime; //scurti, lungi.
    std::string tip; //blugi, eleganti,trening

public:
    Pantaloni();
    Pantaloni(const std::string &denumire, double pret, int nr_buc, int redus, std::string lungime,std::string tip);
    Pantaloni(const Pantaloni &other);
    Pantaloni& operator=(const Pantaloni&other);

    std::shared_ptr<Produs> clone() const override;
    friend std::ostream &operator<<(std::ostream &os, const Pantaloni &produs);
    void reducere() override;
    ~Pantaloni() override;

};


#endif //OOP_PANTALONI_H
