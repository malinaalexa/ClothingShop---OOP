#include <iostream>
#include<vector>
#include "produs.h"
#include "comanda.h"

int main() {
    std::vector<Produs> prod;
    prod.push_back(Produs(1,"Bluza",59.90,15));
    prod.push_back(Produs(1,"Pantaloni",159.90,20));
    prod.push_back(Produs(1,"Rochie",79.90,20));

    return 0;
}
