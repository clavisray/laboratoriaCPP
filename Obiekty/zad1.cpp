/* Zadanie 1.
Zdefiniuj klasę Samochod zawierającą:
Prywatne pola:
• int vMax
• double paliwoWZbiorniku, zuzycieNa100km

Metody:
• metody dostępowe do prywatnych pól,
• konstruktor:
bez parametrów (inicjuje pola dowolnie przyjętymi wartościami domyślnymi)
• double zasieg() – oblicza ile można przejechać na paliwie w zbiorniku
• double czasDojazdu(double dystans) – oblicza ile zajmie dojazd zakładając średnią
prędkość równą 3⁄4 vMax
• void zatankuj(double ilePaliwaZatankowano) - zwiększa liczbę paliwa w zbiorniku
zgodnie z wartością parametru
• void trasa(double liczbaKilometrów) - zmniejsza liczbę paliwa w zbirniku zgodnie z
liczbą przejechanych kilometrów */

#include <iostream>
#include <stdio.h>
#include <cstring>

class Samochod {
    private: 
        int vMax;
        double paliwoWZbiorniku, zuzycieNa100km;

    public:
        Samochod() {
            vMax = 200;
            paliwoWZbiorniku = 55; 
            zuzycieNa100km = 8.2;
        }

        int getVMax() {
            return vMax;
        }
        
        double getPaliwoWZbiorniku() {
            return paliwoWZbiorniku;
        }
        
        double getZuzycieNa100km() {
            return zuzycieNa100km;
        }

        double zasieg() {
            return paliwoWZbiorniku / zuzycieNa100km * 100;
        };

        double czasDojazdu(double dystans) {
            return dystans / (vMax * 0.75);
        };

        void zatankuj(double ilePaliwaZatankowano) {
            paliwoWZbiorniku += ilePaliwaZatankowano;
            std::cout << "Zatankowano: "<< paliwoWZbiorniku << std::endl;
        };

        void trasa(double liczbaKilometrow) {
            paliwoWZbiorniku -= (liczbaKilometrow * zuzycieNa100km) / 100;
        };
};

int main(){

    return 0;
}