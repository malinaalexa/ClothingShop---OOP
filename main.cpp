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
    std::vector<Produs*> stoc;
    Bluza Bl{"Bluza de bumbac",99.99,15,0,"tricou"};

    try {
        Bl.setTip(Bl.gettip());
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    auto* st1 = dynamic_cast<Produs*>(&Bl);
    st1->reducere();
    std::cout<<st1->pretprod()<<'\n';
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
    std::cout<<st2->pretprod()<<'\n';
    Rochie Ro("Rochie roz",190.99,15,0,"Lunga");
    try {
        Ro.setLungime(Ro.getlungime());
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    auto* st3 = dynamic_cast<Produs*>(&Ro);
    std::cout<<st3->pretprod()<<'\n';

    try{
        stoc.push_back(st1);
        stoc.push_back(st2);
        stoc.push_back(st3);}
    catch (std::exception& e) { std::cout << e.what() << std::endl; }
    Comanda C1 = Comanda(std::vector<std::shared_ptr<Produs>>(), 0, An1,std::vector<int>());
    C1.insert(Bl,3);
    C1.insert(Pan,1);
    C1.calculvaloare();
    return 0;
}
