#include <iostream>
#include "bluza.h"
#include "produs.h"
#include <utility>
#include<memory>
#include<string>
#include <vector>
#include "angajat.h"
int main() {
    Angajat An{"Popescu Ion",2700,"Manager",2,20};
    std::cout<<An.getsalariu();
    return 0;
}
