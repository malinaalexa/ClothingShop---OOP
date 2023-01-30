#include <iostream>
#include "produs.h"
#include<memory>
#include <vector>
#include "angajat.h"
#include "comanda.h"
#include "bluza.h"
#include "pantaloni.h"
#include "exceptii.h"

int main() {
    std::vector<Produs*> stoc;
    Angajat<int> An1("Popescu Ion", 2700.0, "Manager", 2, 20,19);
    std::cout<<"Salariu initial "<<An1.getsalariu()<<". Cu bonus devine ";
    An1.bonus_final();
    std::cout<<'\n';

    Bluza Bl{"Bluza de bumbac",99.99,15,0,"tricou"};
    auto* st1 = dynamic_cast<Produs*>(&Bl);
    if (st1 != nullptr)
          {st1->reducere();
          std::cout<<st1->pretprod()<<'\n';}
    Pantaloni Pan("Blugi Negri",180,15,0,"Scurti","Blugi");
    auto* st2 = dynamic_cast<Produs*>(&Pan);
    if (st2 != nullptr)
        std::cout<<st2->pretprod()<<'\n';
    Rochie Ro("Rochie roz",190.99,15,0,"Lunga");
    auto* st3 = dynamic_cast<Produs*>(&Ro);

    if (st3 != nullptr)
         std::cout<<st3->pretprod()<<'\n';
    try {
        Bl.setTip(Bl.gettip());
        Pan.setTip(Pan.gettip());
    } catch (eroare_tip &error) {
        std::cout<<error.what()<<'\n';
    }

    try {
        Pan.setLungime(Pan.getlungime());
        Ro.setLungime(Ro.getlungime());
    }  catch (eroare_lungime &error) {
        std::cout<<error.what()<<'\n';
    }
    try{
        stoc.push_back(st1);
        stoc.push_back(st2);
        stoc.push_back(st3);}
    catch (std::exception& e) { std::cout << e.what() << std::endl; }

    Comanda C1 = Comanda(std::vector<std::shared_ptr<Produs>>(), 0, An1,std::vector<int>());
    std::cout<<"\nStoc inainte de comanda (Bluze, Pantaloni, Rochii): "<<stoc[0]->getstoc()<< " "<<stoc[1]->getstoc()<<" "<<stoc[2]->getstoc()<<'\n';
    C1.insert(Bl,3);
    C1.insert(Pan,1);
    std::cout<<"\nStoc dupa comanda (Bluze, Pantaloni, Rochii): "<<stoc[0]->getstoc()<< " "<<stoc[1]->getstoc()<<" "<<stoc[2]->getstoc()<<'\n';
    C1.calculvaloare();
    std::cout<<"\nSalariul angajatului cu bonus marit va deveni: ";//C1 e a 20-a comanda de care se ocupa pt a arata marirea de bonus
    C1.getbonusfin();
    return 0;
}
