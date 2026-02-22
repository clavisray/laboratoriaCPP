#include <string>
#include <iostream>

class Egzamin {
private:
    std::string oCzym;
    int ocena;

public:
    Egzamin()
        : oCzym(""), ocena(0) {}

    Egzamin(std::string o, int c)
        : oCzym(o), ocena(c) {}

    void setOczym(std::string o)   { oCzym = o; }
    void setOcena(int c)          { ocena = c; }

    std::string getOczym() const  { return oCzym; }
    int getOcena() const          { return ocena; }

    std::string opis() const      { return "SlaboPoszlo"; }
};

class Student : public Egzamin {
private: 
    std::string jaki;

public:
    Student()
        : Egzamin(), jaki("") {}

    Student(std::string oC, int c, std::string j)
        : Egzamin(oC, c), jaki(j) {}

    void setJaki(std::string j)   { jaki = j; }
    std::string getJaki() const   { return jaki; }

    std::string opis() const      { return "DobrzePoszlo?"; }
};
        
int main() {
    return 0;
}
