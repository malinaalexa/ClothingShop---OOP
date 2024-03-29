#ifndef OOP_PRODUS_H
#define OOP_PRODUS_H
#include <iostream>
#include<memory>
#include<string>
#include <vector>
class Produs {
protected:
    const int id_prod = 0;
    std::string denumire;
    double pret;
    int nr_buc;
    int redus;
    static int urm;
public:
    Produs();
    Produs(std::string denumire, double pret, int nr_buc, int redus);
    Produs(const Produs &other);
    Produs &operator=(const Produs &other);
    friend std::ostream& operator<<(std::ostream& os, const Produs& Prod);
    virtual std::shared_ptr<Produs> clone() const = 0;
    double pretprod() const;
    virtual void reducere() = 0;
    void edit_stoc(int x);
    virtual void afis(std::ostream &ostream) const;
    int getstoc();
    virtual ~Produs();
};
#endif //OOP_PRODUS_H