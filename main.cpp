//Steica Malina-Alexa, grupa 161

#include <iostream>


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
    std::string getnume()
    {
        return nume;
    }
    std::string getmail()
    {
        return adresa_mail;
    }
    std::string gettel()
    {
        return numar_telefon;
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
    void afisare_nume()
    {
        std::cout<<date_distr.getnume();
    }
    void afisare_mail()
    {
        std::cout<<date_distr.getmail();
    }
    void afisare_tel()
    {
        std::cout<<date_distr.gettel();
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
    int nr_buc;
    int redus=0;
public:
    Produs(int id_prod_,
           const std::string& denumire_,
           double pret_,
           const std::string& material_,
           const std::string& culoare_,
           const std::string& marime_,
           const Distribuitor &producator_,
           int nr_buc_):
            id_prod{id_prod_},
            denumire{denumire_},
            pret{pret_},
            material{material_},
            culoare{culoare_},
            marime{marime_},
            producator{producator_},
            nr_buc{nr_buc_}
    {
        std::cout<<"-Constructor Produs-"<<'\n';
    };

    friend std::ostream& operator<<(std::ostream& os, const Produs& Prod)
    {
        os <<Prod.id_prod<<" "<<Prod.denumire<<" "<<Prod.pret<<"lei "<<Prod.material<<" "<<Prod.culoare<<" "<<Prod.marime<<" "<<Prod.producator<<Prod.nr_buc<<'\n';
        return os;
    }
    void reducere ()
    {
        if(pret>80 && redus<=0)
            {pret=pret-pret*0.2;
            redus++;}
    }
    void lichidare_de_stoc()
    {
        if(nr_buc<10)
        {
            std::cout<<"Promotie! Pretul este redus cu 20% de doua ori!"<<'\n';
            redus=-1;
            reducere();
            reducere();
        }
    }
    void aprovizionare()
    {
        if((nr_buc<30 && nr_buc>10) || nr_buc==0)
        {
            std::cout<<"Vom contacta distribuitorul ";
            producator.afisare_nume();
            std::cout<<" pentru a comanda "<<30-nr_buc<<" produse."<<'\n';
            std::cout<<"Mail: ";
            producator.afisare_mail();
            std::cout<<'\n'<<"Numar de telefon: ";
            producator.afisare_tel();
            std::cout<<'\n';
            nr_buc=30;
        }
    }

};
class Angajat
{
    int id_angajat;
    double salariu;
    std::string rol;
    Date date_personale;
public:
    Angajat(int id_angajat_,
            double salariu_,
            const std::string& rol_,
            const Date &date_personale_) :
            id_angajat{id_angajat_},
            salariu{salariu_},
            rol{rol_},
            date_personale{date_personale_}
    {
        std::cout<<"-Constructor Angajati-"<<'\n';
    };
    friend std::ostream& operator<<(std::ostream& os, const Angajat& An)
    {
        os <<An.id_angajat<<" "<<An.salariu<<" "<<An.rol<<" "<<An.date_personale<<'\n';
        return os;
    }
    Angajat(const Angajat& other) : id_angajat{other.id_angajat}, salariu{other.salariu}, rol{other.rol},date_personale{other.date_personale}
    {
        std::cout<<"Constructor de copiere Angajat\n";
    }
    Angajat& operator=(const Angajat& other)
    {
        id_angajat = other.id_angajat;
        salariu=other.salariu;
        rol=other.rol;
        date_personale=other.date_personale;
        return *this;
    }
    void marire_salariu()
    {
        if(salariu<2000)
            salariu=salariu+salariu*0.2;
    }
    ~Angajat() {};//destructor

};

int main()
{
    Angajat A1{1,2300,"Manager",Date{"Andrei","0766555222","andrei@gmail.com"}};
    Angajat A2{2,1560,"Agent de vanzari",Date{"Alex","0766555333","alex@gmail.com"}};
    Distribuitor D1{1,Date{"Zara","0766555333","zara@gmail.com"},"Strada 1 Decembrie, nr. 1"};
    Produs P1{1,"Bluza",99.99,"Matase","Alb","M",{D1},0};
    Produs P2{2,"Pantaloni",149.99,"Piele","Negru","M",{D1},15};
    Produs P3{3,"Rochie",199.99,"Satin","Rosu","M",{D1},5};
    std::cout<<A1<<A2<<D1<<P1<<P2<<P3;
    A1.marire_salariu();
    P2.reducere();
    P1.aprovizionare();
    P2.aprovizionare();
    P3.lichidare_de_stoc();
    std::cout<<P1<<P2<<P3<<A1;
    return 0;
}
