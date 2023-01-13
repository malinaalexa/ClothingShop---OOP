#include "angajat.h"
#include <iostream>
#include <utility>
Angajat::Angajat(std::string  nume, double salariu, std::string  rol, int overtime, int zile_luna) : nume{std::move(nume)}, salariu{salariu}, rol{std::move(rol)}, overtime{overtime}, zile_luna{zile_luna}
{ }
double Angajat::getsalariu()
{double sal_zi=salariu/20; //consideram luna de 20 de zile lucratoare
salariu=sal_zi*zile_luna+sal_zi*2*overtime; //cat se primeste pe o zi * zile lucrate in luna respectiva
//zilele de overtime se platesc dublu
    return salariu;
}

Angajat &Angajat::operator=(const Angajat &other) {
    nume= other.nume;
    salariu=other.salariu;
    rol=other.rol;
    overtime=other.overtime;
    zile_luna=other.zile_luna;
    return *this;
}

Angajat::Angajat(const Angajat &other) : nume{other.nume}, salariu{other.salariu}, rol{other.rol}, overtime{other.overtime}, zile_luna{other.zile_luna}
{
    std::cout<<"Constructor de copiere Angajat\n";
}

std::ostream &operator<<(std::ostream &os, const Angajat &An) {
    os <<An.nume<<" "<<An.salariu<<" "<<An.rol<<"Zile lucrate pe luna in curs: "<< An.overtime+An.zile_luna<<'\n';
    return os;
}

