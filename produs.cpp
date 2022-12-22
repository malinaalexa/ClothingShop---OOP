#include "produs.h"
#include <iostream>
#include<vector>
double Produs::pretprod()
{
    return pret;
}
void Produs::reducere()
{
    if(pret>80 && redus<=0)
    {pret=pret-pret*0.2;
        redus++;}
}

void Produs::lichidare_de_stoc()
{
    if(nr_buc<10)
    {
        std::cout<<"Promotie! Pretul este redus cu 20% de doua ori!"<<'\n';
        redus=-1;
        reducere();
        reducere();
    }
}
