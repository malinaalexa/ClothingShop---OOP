#include <iostream>
#include "produs.h"
#include<memory>
#include <vector>
#include "angajat.h"
#include "comanda.h"
#include "bluza.h"
#include "pantaloni.h"

int main() {
    Angajat An1("Popescu Ion", 2700, "Manager", 2, 20);
    std::cout<<An1.getsalariu()<<'\n';
    std::vector<Produs*> Stoc;
    Bluza Bl{"Bluza de bumbac",99.99,15,0,"tricou"};
    try {
        Bl.setTip(Bl.gettip());
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    auto* st1 = dynamic_cast<Produs*>(&Bl);
    if (st1 == nullptr)
        std::cout << "null" << '\n';
    st1->reducere();
    std::cout<<st1->pretprod();

    Pantaloni Pan("Blugi Negri",180,15,0,"Scurti","Blugi");
    try {
        Pan.setTip(Pan.gettip());
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        Pan.setLungime(Pan.getlungime());
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    auto* st2 = dynamic_cast<Produs*>(&Pan);
    if (st2 == nullptr)
        std::cout << "null" << '\n';

    Rochie Ro("Rochie roz",190.99,15,0,"Lunga");
    try {
        Ro.setLungime(Ro.getlungime());
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    auto* st3 = dynamic_cast<Produs*>(&Ro);
    if (st3 == nullptr)
        std::cout << "null" << '\n';
    
    Comanda C1 = Comanda(std::vector<std::shared_ptr<Produs>>(), 0, An1,std::vector<int>());
    C1.insert(Bl,3);
    C1.insert(Pan,1);
    C1.calculvaloare();
    return 0;
}
