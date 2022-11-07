//Steica Malina-Alexa, grupa 161

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

class Date
{
    std::string nume;
    std::string numar_telefon;
    std::string adresa_mail;

public:
    Date (const std::string& nume_,
          const std::string& numar_telefon_,
          const std::string& adresa_mail_) :
        nume{nume_},
        numar_telefon{numar_telefon_},
        adresa_mail{adresa_mail_}
    {
        std::cout<<"-Constructor Date-"<<'\n';
    };
    friend std::ostream& operator<<(std::ostream& os, const Date& Date)
    {
        os <<Date.nume<<" "<<Date.numar_telefon<<" "<<Date.adresa_mail;
        return os;
    }
};
class Distribuitor
{
    int id_distr;
    Date date_distr;
    std::string adresa;
public:
    Distribuitor (int id_distr_,const Date& date_distr_,
                  const std::string& adresa_) :
        id_distr{id_distr_},
        date_distr{date_distr_},
        adresa{adresa_}
    {
        std::cout<<"-Constructor Distribuitor-"<<'\n';
    };
    friend std::ostream& operator<<(std::ostream& os, const Distribuitor& Distr)
    {
        os <<Distr.id_distr<<" "<<Distr.date_distr<<" "<<Distr.adresa<<'\n';
        return os;
    }
};
class Produs
{
    int id_prod;
    std::string denumire;
    double pret;
    std::string material;
    std::string culoare;
    std::string marime;
    Distribuitor producator;
public:
    Produs(int id_prod_,
           const std::string& denumire_,
           double pret_,
           const std::string& material_,
           const std::string& culoare_,
           const std::string& marime_,
           const Distribuitor &producator_) :
        id_prod{id_prod_},
        denumire{denumire_},
        pret{pret_},
        material{material_},
        culoare{culoare_},
        marime{marime_},
        producator{producator_}
    {
        std::cout<<"-Constructor Produs-"<<'\n';
    };

    friend std::ostream& operator<<(std::ostream& os, const Produs& Prod)
    {
        os <<Prod.id_prod<<" "<<Prod.denumire<<" "<<Prod.pret<<"lei "<<Prod.material<<" "<<Prod.culoare<<" "<<Prod.marime<<" "<<Prod.producator<<'\n';
        return os;
    }
    friend void reducere (Produs &x);
    friend void set_price(Produs &x);
};
class Angajat
{
    int id_angajat;
    std::string rol;
    Date date_personale;
public:
    Angajat(int id_angajat_,
            const std::string& rol_,
            const Date &date_personale_) :
        id_angajat{id_angajat_},
        rol{rol_},
        date_personale{date_personale_}
    {
        std::cout<<"-Constructor Angajati-"<<'\n';
    };
    friend std::ostream& operator<<(std::ostream& os, const Angajat& An)
    {
        os <<An.id_angajat<<" "<<An.rol<<" "<<An.date_personale<<'\n';
        return os;
    }
    Angajat(const Angajat& other) : id_angajat{other.id_angajat}, rol{other.rol},date_personale{other.date_personale}
    {
        std::cout<<"Constructor de copiere Angajat\n";
    }
    Angajat& operator=(const Angajat& other)
    {
        id_angajat = other.id_angajat;
        rol=other.rol;
        date_personale=other.date_personale;
        return *this;
    }
    ~Angajat() {};//destructor

};
class Magazin
{
    Angajat angajati[21];
    Produs produse[101];
};
void reducere (Produs &x)
{
    if(x.pret>100)
        x.pret=x.pret-x.pret*0.3;
}
void set_price(Produs &x)
{if(x.denumire=="Bluza") x.pret=79.99;
if(x.denumire=="Pantaloni") x.pret=129.99;
if(x.denumire=="Rochie") x.pret=99.90;
}
int main()
{
    Angajat A1{1,"Manager",Date{"Andrei","0766555222","andrei@gmail.com"}};
    Distribuitor D1{1,Date{"Zara","0766555333","zara@gmail.com"},"Strada 1 Decembrie, nr. 1"};
    Produs P1{1,"Bluza",-1,"Matase","Alb","M",{D1}};
    Produs P2{1,"Pantaloni",-1,"Piele","Negru","M",{D1}};
    Produs P3{1,"Rochie",-1,"Satin","Rosu","M",{D1}};
    std::cout<<A1<<D1<<P1<<P2<<P3;
    set_price(P1);
    set_price(P2);
    set_price(P3);
    std::cout<<P1<<P2<<P3;
    reducere(P1);
    reducere(P2);
    std::cout<<"Dupa reducere"<<P1<<P2<<P3;
    return 0;
}
