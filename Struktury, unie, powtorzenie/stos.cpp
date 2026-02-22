#include <iostream>
#include <stdio.h>
#include <cstring>

struct element{
    int liczba;
    element* nastepny;
};

void dodaj(element*& stos, int wartosc) {
    element* nowy = new element;
    nowy->liczba = wartosc;
    nowy->nastepny = stos;
    stos = nowy;
}

int zdejmij(element*& stos) {
    if (stos == nullptr) {
        return -1; 
    }
    element* temp = stos;
    int wartosc = temp->liczba;
    stos = stos->nastepny;
    delete temp;
    return wartosc;
}


void wyswietl(element* stos) {
    element* aktualny = stos;
    while (aktualny != nullptr) {
        std::cout << aktualny->liczba << " ";
        aktualny = aktualny->nastepny;
    }
    std::cout << std::endl;
}

int main(){
    element* stos = nullptr;
    
    dodaj(stos, 10); 
    dodaj(stos, 20);
    dodaj(stos, 30);
    
    wyswietl(stos);  
    
    std::cout << "Pop: " << zdejmij(stos) << std::endl;  
    std::cout << "Pop: " << zdejmij(stos) << std::endl;  
    
    wyswietl(stos); 
    
    return 0;
}