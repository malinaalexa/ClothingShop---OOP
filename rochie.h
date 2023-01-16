
#ifndef OOP_ROCHIE_H
#define OOP_ROCHIE_H
#include "produs.h"
#include <iostream>
#include <memory>
class Rochie: public Produs {
protected:

    std::string lungime; //scurta, lunga, midi, etc.
public:
    Rochie();
    Rochie(const std::string &denumire, double pret, int nr_buc, int redus, std::string lungime);
    Rochie(const Rochie &other);
    Rochie& operator=(const Rochie&other);
    std::shared_ptr<Produs> clone() const override;
    void reducere() override;
    ~Rochie() override;
    std::string getlungime();
    void setLungime(const std::string &lung1);
};



#endif //OOP_ROCHIE_H
