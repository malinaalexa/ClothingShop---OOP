
#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H
#include <iostream>

class Angajat {
protected:
    std::string nume;
    double salariu;
    std::string rol;
    int overtime;
    int zile_luna;
public:
    Angajat(std::string nume, double salariu, std::string rol, int overtime, int zile_luna);
    friend std::ostream& operator<<(std::ostream& os, const Angajat& An);
    Angajat(const Angajat& other);
    Angajat& operator=(const Angajat& other);
    double getsalariu();
    ~Angajat() = default;
};


#endif //OOP_ANGAJAT_H
