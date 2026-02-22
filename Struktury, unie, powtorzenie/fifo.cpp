#include <iostream>
#include <stdio.h>
#include <cstring>

struct element{
    int liczba;
    element* nastepny;
};


void dodaj(element*& poczatek, element*& koniec, int wartosc) {
    element* nowy = new element;
    nowy->liczba = wartosc;
    nowy->nastepny = nullptr;
    
    if (koniec == nullptr) {  
        poczatek = nowy;
        koniec = nowy;
    } else {
        koniec->nastepny = nowy;  
        koniec = nowy;
    }
}


int zdejmij(element*& poczatek, element*& koniec) {
    if (poczatek == nullptr) {
        return -1; 
    }
    element* temp = poczatek;
    int wartosc = temp->liczba;
    poczatek = poczatek->nastepny;
    
    if (poczatek == nullptr) {  
        koniec = nullptr;
    }
    
    delete temp;
    return wartosc;
}

void wyswietl(element* poczatek) {
    element* aktualny = poczatek;
    while (aktualny != nullptr) {
        std::cout << aktualny->liczba << " ";
        aktualny = aktualny->nastepny;
    }
    std::cout << std::endl;
}

int main(){
    element* poczatek = nullptr;
    element* koniec = nullptr;
    
    dodaj(poczatek, koniec, 10); 
    dodaj(poczatek, koniec, 20);
    dodaj(poczatek, koniec, 30);
    
    wyswietl(poczatek);  
    
    std::cout << "Pop: " << zdejmij(poczatek, koniec) << std::endl;  
    std::cout << "Pop: " << zdejmij(poczatek, koniec) << std::endl; 
    
    wyswietl(poczatek);  
    
    return 0;
}