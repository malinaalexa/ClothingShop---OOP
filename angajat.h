#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H
#include <iostream>
template <typename T>
class Angajat {
protected:
    std::string nume;
    double salariu;
    std::string rol;
    int overtime;
    int zile_luna;
    T bonus;//se primeste un bonus de 15 lei pentru fiecare comanda
public:
    Angajat(std::string nume, double salariu, std::string rol, int overtime, int zile_luna, T bonus);
    Angajat(const Angajat<T>& other);
    Angajat();
    Angajat& operator=(const Angajat<T>& other);
    friend std::ostream &operator<<(std::ostream &os, const Angajat<T> &An) {
        os <<An.nume<<" "<<An.salariu<<" "<<An.rol<<"Zile lucrate pe luna in curs: "<< An.overtime+An.zile_luna<<" Bonus: "<< An.bonus <<'\n';
        return os;
    }
    double getsalariu();
    void adaugare_bonus();
    void bonus_final();
    ~Angajat();

};


#endif
