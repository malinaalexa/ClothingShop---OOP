#include "angajat.h"
#include <iostream>
template <typename T>
Angajat<T>::Angajat(std::string nume, double salariu, std::string rol, int overtime, int zile_luna, T bonus) : nume{std::move(nume)}, salariu{salariu}, rol{std::move(rol)}, overtime{overtime}, zile_luna{zile_luna}, bonus{bonus} {
}
template <typename T>
double Angajat<T>::getsalariu()
{
    double sal_zi=salariu/20; //consideram luna de 20 de zile lucratoare
    salariu=sal_zi*zile_luna+sal_zi*2*overtime; //cat se primeste pe o zi * zile lucrate in luna respectiva
    //zilele de overtime se platesc dublu
    return salariu;
}
template <typename T>
Angajat<T> &Angajat<T>::operator=(const Angajat<T> &other) {
    nume= other.nume;
    salariu=other.salariu;
    rol=other.rol;
    overtime=other.overtime;
    zile_luna=other.zile_luna;
    bonus=other.bonus;
    return *this;
}
template <typename T>
Angajat<T>::Angajat(const Angajat<T> &other) : nume{other.nume}, salariu{other.salariu}, rol{other.rol}, overtime{other.overtime}, zile_luna{other.zile_luna}, bonus{other.bonus}
{
}

template<typename T>
void Angajat<T>::adaugare_bonus() {
    bonus++;
}
template<typename T>
void Angajat<T>::bonus_final() {
    salariu=salariu+bonus*15;
    if(bonus>=20)
        salariu=salariu+bonus*15*0.05; //pentru angajatii care s-au ocupat de peste 20 de comenzi bonusul este cu 5% mai mare
    std::cout<<salariu;
}
template<typename T>
Angajat<T>::Angajat() = default;
template<typename T>
Angajat<T>::~Angajat() {

}
template class Angajat<int>;