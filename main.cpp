#include <iostream>
#include "bluza.h"
int main() {
    Bluza Bl("Bluza de bumbac",99.99,15,0,"tricou");
    Bl.reducere();
    std::cout<<Bl.pretprod();
    return 0;
}
