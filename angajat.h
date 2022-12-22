
#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H
#include <iostream>

class Angajat {
protected:
    std::string nume;
    double salariu;
    std::string rol;
public:
    friend std::ostream& operator<<(std::ostream& os, const Angajat& An)
    {
        os <<An.nume<<" "<<An.salariu<<" "<<An.rol<<'\n';
        return os;
    }
    Angajat(const Angajat& other) : nume{other.nume}, salariu{other.salariu}, rol{other.rol}
    {
        std::cout<<"Constructor de copiere Angajat\n";
    }
    Angajat& operator=(const Angajat& other)
    {
        nume= other.nume;
        salariu=other.salariu;
        rol=other.rol;
        return *this;
    }
    void marire_salariu();
    ~Angajat();
};


#endif //OOP_ANGAJAT_H
