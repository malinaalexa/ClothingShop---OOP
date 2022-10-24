//Steica Malina-Alexa, grupa 161
//am adaugat doar clasele pe care le voi folosi (si cate un obiect pentru test)

#include <iostream>
#include <string>
#include <vector>

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
    Distribuitor (int id_distr_,Date date_distr_,
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
    float pret;
    std::string material;
    std::string culoare;
    std::string marime;
    Distribuitor producator;
public:
    Produs(int id_prod_,
           const std::string& denumire_,
           float pret_,
           const std::string& material_,
           const std::string& culoare_,
           const std::string& marime_,
           Distribuitor producator_) :
        id_prod{id_prod_},
        denumire{denumire_},
        pret{pret_},
        material{material_},
        culoare{culoare_},
        marime{marime_},
        producator{producator_}
    {
        std::cout<<"-Constructor produs-"<<'\n';
    };
    friend std::ostream& operator<<(std::ostream& os, const Produs& Prod)
    {
        os <<Prod.id_prod<<" "<<Prod.denumire<<" "<<Prod.pret<<"lei "<<Prod.material<<" "<<Prod.culoare<<" "<<Prod.marime<<" "<<Prod.producator<<'\n';
        return os;
    }
};
class Angajat
{
    int id_angajat;
    std::string rol;
    Date date_personale;
public:
    Angajat(int id_angajat_,
            const std::string& rol_,
            Date date_personale_) :
        id_angajat{id_angajat_},
        rol{rol_},
        date_personale{date_personale_}
    {
        std::cout<<"constructor angajati"<<'\n';
    };
    friend std::ostream& operator<<(std::ostream& os, const Angajat& An)
    {
        os <<An.id_angajat<<" "<<An.rol<<" "<<An.date_personale<<'\n';
        return os;
    }
};

int main()
{
    Angajat A1{1,"Manager",Date{"Andrei","0766555222","andrei@gmail.com"}};
    Distribuitor D1{1,Date{"Zara","0766555333","zara@gmail.com"},"Strada 1 Decembrie, nr. 1"};
    Produs P1{1,"Bluza",149.99,"Matase","Alb","M",{D1}};
    std::cout<<A1<<D1<<P1;
    return 0;
}
