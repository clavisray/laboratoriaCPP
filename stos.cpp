#include <iostream>
#include <stdio.h>
#include <cstring>

struct Element{
    int liczba;
    struct Element* nastepny;
};

void dodajNaKoniec(struct Element** head, int wartosc) {
    struct Element* newElement = new Element;  
    newElement->liczba = wartosc;
    newElement->nastepny = NULL;  
    
    if(*head == NULL) {
        *head = newElement;
    } else {
        struct Element* obecny = *head;
        while (obecny->nastepny != NULL) {  
            obecny = obecny->nastepny;       
        }
        obecny->nastepny = newElement;       
    }
}



int main(){
    return 0;
}