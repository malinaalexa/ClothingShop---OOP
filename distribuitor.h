
#ifndef OOP_DISTRIBUITOR_H
#define OOP_DISTRIBUITOR_H
#include <iostream>

class Distribuitor {

    std::string nume;
    std::string telefon;
    std::string adresa;
public:
    Distribuitor (const std::string& nume_,const std::string& telefon_,
                  const std::string& adresa_) :
            nume{nume_},
            telefon{telefon_},
            adresa{adresa_}
    {
        std::cout<<"-Constructor Distribuitor-"<<'\n';
    };
    friend std::ostream& operator<<(std::ostream& os, const Distribuitor& Distr)
    {
        os <<Distr.nume<<" "<<Distr.telefon<<" "<<Distr.adresa<<'\n';
        return os;
    }

    void afisare_nume();

    void afisare_tel();

    void afisare_adr();
};


#endif //OOP_DISTRIBUITOR_H
