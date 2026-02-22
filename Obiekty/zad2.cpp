/* Zadanie 2.
Zaprojektuj klasę Rational, reprezentującą liczby wymierne jako pary liczb całkowitych
(licznik i mianownik), wraz z podstawowymi działaniami arytmetycznymi i
porównaniem. W klasie powinny znaleźć się następujące metody publiczne (oprócz
konstruktora):
1. dodawanie: Rational* add(Rational* arg);
2. mnożenie: Rational* mul(Rational* arg);
3. odejmowanie: Rational* sub(Rational* arg);
4. dzielenie: Rational* div(Rational* arg);
5. równość: boolean equals(Rational* arg);
6. porównanie: int compareTo(Rational* arg);
7. tekstowa reprezentacja liczby: char* toString().
Metody 1–4 powinny zwracać jako rezultat wskaźnik do nowego obiektu klasy Rational,
będącego wynikiem operacji wykonanej na argumencie arg i this. Metoda 5. ma
porównywać obiekty klasy Rational na podstawie wartości liczb, np. 1/2 = 2/4. Metoda
6. ma generować poniższe wartości:
• Jeśli this jest równe arg, to zwraca 0.
• Jeśli this jest mniejsze od arg, to zwraca −1.
• Jeśli this jest większe niż arg, to zwraca 1.
Metoda 7. ma zwracać łańcuch znakowy opisujący ten obiekt. Na przykład może to być
napis postaci 1/2 lub -1/1. */

#include <iostream>
#include <stdio.h>
#include <cstring>

class Rational {

    private:
        int licznik;
        int mianownik;

    public: 
        Rational(int l, int m){

            licznik = l;
            mianownik = m;

        }

        Rational* add(Rational* arg) {

            int nowyL = this->licznik * arg->mianownik + this->mianownik * arg->licznik;
            
            int nowyM = this->mianownik * arg->mianownik;
            
            return new Rational(nowyL, nowyM);

        }

        Rational* mul(Rational* arg){
            
            int nowyL = this->licznik * arg->licznik;
            
            int nowyM = this->mianownik * arg->mianownik;

            return new Rational(nowyL, nowyM);

        }

        Rational* sub(Rational* arg){

            int nowyL = this->licznik * arg->mianownik - arg->licznik * this->mianownik;

            int nowyM = this->mianownik * arg->mianownik;

            return new Rational(nowyL, nowyM);

        }

        Rational* div(Rational* arg){

            int nowyL = this->licznik * arg->mianownik;

            int nowyM = this->mianownik * this->licznik;

            return new Rational(nowyL, nowyM);

        }

        bool equals(Rational* arg){

            return (this->licznik * arg->mianownik) == (this->mianownik * arg->licznik);

        }

        int compareTo(Rational* arg){
            
            int lewy = this->licznik * arg->mianownik;
            int prawy = arg->licznik * this->mianownik;

            if(lewy == prawy) return 0;
            if(lewy > prawy) return 1;
            if(lewy < prawy) return -1;

        }

        char* toString() {
            static char bufor[50];
            sprintf(bufor, "%d/%d", licznik, mianownik);
            return bufor;
        }
};

int main() {
    int l1, m1, l2, m2;
    
    std::cout << "Podaj pierwszy ułamek (licznik mianownik): ";
    std::cin >> l1 >> m1;
    
    std::cout << "Podaj drugi ułamek (licznik mianownik): ";
    std::cin >> l2 >> m2;
    
    Rational* a = new Rational(l1, m1);
    Rational* b = new Rational(l2, m2);

    Rational* wynik = a->add(b);

    
    std::cout << "Wynik: " << wynik->toString() << std::endl;
    std::cout << "Porownanie: " << a->compareTo(b) << std::endl;
    return 0;
}