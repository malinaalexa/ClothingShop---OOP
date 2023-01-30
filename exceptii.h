
#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H
#include <stdexcept>
#include <string>
    class eroare_app: public std::runtime_error{
        using std::runtime_error::runtime_error;
    };
    class eroare_lungime: public eroare_app {
    public:
        explicit eroare_lungime();
    };
    class eroare_tip: public eroare_app {
    public:
        explicit eroare_tip();
    };


#endif //OOP_EXCEPTII_H
