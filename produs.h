#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H
#include <iostream>

class Produs {
protected:
        int id_prod;
        std::string denumire;
        double pret;
        int nr_buc;
        int redus = 0;
    public:
        Produs(int id_prod_,
               const std::string &denumire_,
               double pret_,
               int nr_buc_) :
                id_prod{id_prod_},
                denumire{denumire_},
                pret{pret_},
                nr_buc{nr_buc_} {
            std::cout << "-Constructor Produs-" << '\n';
        };
    friend std::ostream& operator<<(std::ostream& os, const Produs& Prod)
    {
        os <<Prod.id_prod<<" "<<Prod.denumire<<" "<<Prod.pret<<"lei "<<Prod.nr_buc<<'\n';
        return os;
    }
    double pretprod();
    void reducere();

    void lichidare_de_stoc();
};
#endif //OOP_PRODUS_H
