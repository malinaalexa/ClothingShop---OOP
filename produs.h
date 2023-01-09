#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H
#include <iostream>
#include<memory>
#include <vector>
class Produs {
protected:
    std::string denumire;
    double pret;
    int nr_buc;
    int redus;
public:
    Produs();

    Produs(std::string denumire, double pret, int nr_buc, int redus);

    Produs(const Produs &other);

    Produs &operator=(const Produs &other);

    friend std::ostream& operator<<(std::ostream& os, const Produs& Prod)
    {
        os <<Prod.denumire<<" "<<Prod.pret<<"lei "<<Prod.nr_buc<<'\n';
        return os;
    }
    virtual std::shared_ptr<Produs> clone() const = 0;
    double pretprod();
    int nr_buc_prod();
    virtual void reducere();
    void lichidare_de_stoc();
    virtual ~Produs();
};
#endif //OOP_PRODUS_H
