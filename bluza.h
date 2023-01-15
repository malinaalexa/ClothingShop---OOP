
#ifndef OOP_BLUZA_H
#define OOP_BLUZA_H
#include "produs.h"
#include <iostream>
#include <memory>
#include <exception>

class Bluza : public Produs {
protected:

    std::string tip; // maleta, tricou, cu maneci lungi,etc.
public:
    Bluza();
    Bluza(const std::string &denumire, double pret, int nr_buc, int redus, std::string tip);
    Bluza(const Bluza &other);
    Bluza& operator=(const Bluza&other);
    std::shared_ptr<Produs> clone() const override;
    friend std::ostream &operator<<(std::ostream &os, const Bluza &produs);
    void reducere() override;
    void setTip(std::string tip);
    std::string gettip();
    ~Bluza() override;



};


#endif //OOP_BLUZA_H

