#include <iostream>
#include <stdio.h>
#define MAX_LEN 128

using namespace std;

int str_len(const char t[]){

    int liczbaZnakow = 0;

    while(t[liczbaZnakow] != '\0'){

        liczbaZnakow++;

    }

    return liczbaZnakow;

}

int lwr_str_cnt(const char t[]){

    int liczbaMalychZnakow = 0;
    int dlugoscStringa = str_len(t);

    for(int i = 0; i < dlugoscStringa; i++){

        if(t[i] >= 'a' && t[i] <= 'z') {

            liczbaMalychZnakow++;

        }

    }

    return liczbaMalychZnakow;

}

int upr_str_cnt(const char t[]){

    int liczbaDuzychZnakow = 0;

    for(int i = 0; i < str_len(t); i++){

        if(t[i] >= 'A' && t[i] <= 'Z'){

            liczbaDuzychZnakow++;

        }

    }

    return liczbaDuzychZnakow;

}

int dgt_str_cnt(const char t[]){

    int liczbaCyfr = 0;

    for(int i = 0; i < str_len(t); i++){

        if(t[i] >= '0' && t[i] <= '9'){

            liczbaCyfr++;

        }

    }

    return liczbaCyfr;

}

/*  NIE DA SIE ZWROCIC DWOCH WARTOSCI NA RAZ */
// int nalpha_str_cnt(const char t[]){

//     int liczbaLiter = lwr_str_cnt(t) + upr_str_cnt(t);

//     cout << "Ilosc liter: " << liczbaLiter << " ";
//     cout << "Ilosc liczb: " << dgt_str_cnt(t) << endl;

//     return ??

// }

void nalpha_str_cnt(const char t[]){

    int liczbaLiter = lwr_str_cnt(t) + upr_str_cnt(t);

    cout << "Ilosc liter: " << liczbaLiter << " ";
    cout << "Ilosc liczb: " << dgt_str_cnt(t) << endl;

}

int chr_str_cnt(const char t[]){
    
    int liczbaZnakuC = 0;

    for(int i = 0; i < str_len(t); i++){

        if(t[i] == 'c' || t[i] == 'C'){

            liczbaZnakuC++;

        }

    }
    
    return liczbaZnakuC;

}

int chr_str_pos(const char t[]){
    for(int i = 0; i < str_len(t); i++){
        if(t[i] == 'c' || t[i] == 'C'){
            return i;
        }
    }
    return -1; 
}

int chr_str_cnt2(const char t[]){
    for(int i = str_len(t); i >= 0; i--){
        if(t[i] == 'c' || t[i] == 'C'){
            return i;
        }
    }
    return -1;
}

void str_rev(const char t[]){
    if (*t != '\0'){
        str_rev(t + 1);
        cout << *t;
    }
}

int main(){

    cout << "test funkcji 1: " << str_len("teeest") << endl;
    cout << "test funkcji 2: " << lwr_str_cnt("TeSttt") << endl;
    cout << "test funkcji 3: " << upr_str_cnt("TeSttt") << endl;
    cout << "test funkcji 4: " << dgt_str_cnt("TeSttt44505") << endl;
    cout << "test funkcji 5: "; nalpha_str_cnt("teeSST333444");
    cout << "test funkcji 6: " << chr_str_cnt("teccstCC") << endl;
    cout << "test funkcji 7: " << chr_str_pos("teeeeecst") << endl;
    cout << "test funkcji 7 bez litery c: " << chr_str_pos("teeeeest") << endl;
    cout << "test funkcji 8: " << chr_str_cnt2("teeeestciorc") << endl;
    cout << "test funkcji 9: ";  str_rev("Slowodotestu"); 
    cout << "\n";
    
    return 0;

}