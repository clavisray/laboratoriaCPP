#include <string>
#include <iostream>

class Osoba {
private:
    std::string imie;
    int wiek;

public:
    Osoba() : imie(""), wiek(0) {}
    Osoba(std::string i, int w) : imie(i), wiek(w) {}

    void setImie(std::string i) { imie = i; }
    std::string getImie() const { return imie; }

    void setWiek(int w) { wiek = w; }
    int getWiek() const { return wiek; }
};
