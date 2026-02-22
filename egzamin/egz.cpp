#include <iostream>
#include <string>

class Osoba {
private:
    std::string imie;
    int wiek;

public:
    // konstruktor bezparametrowy
    Osoba()
        : imie(""), wiek(0) {}

    // konstruktor z parametrami
    Osoba(const std::string& i, int w)
        : imie(i), wiek(w) {}

    // funkcje ustawiające
    void setImie(const std::string& i) { imie = i; }
    void setWiek(int w)               { wiek = w; }

    // funkcje pobierające
    std::string getImie() const { return imie; }
    int         getWiek() const { return wiek; }

    // przykładowa funkcja do redefinicji w klasie pochodnej
    std::string opis() const {
        return "Osoba";
    }
};

class Student : public Osoba {
private:
    std::string kierunek;
    float srednia;

public:
    // konstruktor bezparametrowy
    Student()
        : Osoba(), kierunek(""), srednia(0.0f) {}

    // konstruktor z parametrami
    Student(const std::string& i,
            int w,
            const std::string& k,
            float s)
        : Osoba(i, w),   // wywołanie konstruktora klasy bazowej
          kierunek(k),
          srednia(s) {}

    // dodatkowe settery
    void setKierunek(const std::string& k) { kierunek = k; }
    void setSrednia(float s)               { srednia = s; }

    // dodatkowe gettery
    std::string getKierunek() const { return kierunek; }
    float       getSrednia() const  { return srednia; }

    // redefinicja funkcji opis() z klasy bazowej
    std::string opis() const {
        return "Student";
    }
};


int main() {

}