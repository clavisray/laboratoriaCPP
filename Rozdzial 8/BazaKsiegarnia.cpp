#include <iostream>
#include <cstring>
using namespace std;

const int N = 20;

struct Ksiazka {
  int idKsiazki;
	char tytul[80];
  char autor[80];
  int liczbaStron;
  bool wypozyczona;
  bool rekordSkasowany;
};
    
Ksiazka baza[N] = {};

void DodajKsiazke(){
  char tytul[80];
  char autor[80];
  int liczbaStron;

  cout << "Podaj tytul ksiazki: ";
  cin.ignore();
  cin.getline(tytul, 80);

  cout << "Podaj autora ksiazki: ";
  cin.getline(autor, 80);

  cout << "Podaj liczbe stron ksiazki: ";
  cin >> liczbaStron;

  for (int i = 0; i < N; i++){

    if(baza[i].rekordSkasowany || baza[i].tytul[0] == '\0'){

      baza[i].idKsiazki = i;
      strcpy(baza[i].tytul, tytul);
      strcpy(baza[i].autor, autor);
      baza[i].liczbaStron = liczbaStron;
      baza[i].wypozyczona = false;
      baza[i].rekordSkasowany = false;
      cout << "Ksiazka dodana pomyslnie!\n";
      break;

    }
  }
}

void EdytujKsiazke(){

  int ktoraKsiazka;

  char tytul[80];
  char autor[80];
  int liczbaStron;
  bool wypozyczona;
  bool rekordSkasowany;

  do{
    cout << "Wpisz ID ksiazki ktora chcesz edytowac: \n";
    cin >> ktoraKsiazka;

    if(ktoraKsiazka < 0 || ktoraKsiazka >= N){
      
      cout << "Podano niewlasciwa wartosc. Podaj liczbe z zakresu 0-19!\n";

    }
  } while (ktoraKsiazka < 0 || ktoraKsiazka >= N);

  cout << "Podaj tytul ksiazki: ";
  cin.ignore();
  cin.getline(tytul, 80);

  cout << "Podaj autora ksiazki: ";
  cin.getline(autor, 80);

  cout << "Podaj liczbe stron ksiazki: ";
  cin >> liczbaStron;

  cout << "Czy wypozyczona?: ";
  cin >> wypozyczona;

  cout << "Czy usunieta?: ";
  cin >> rekordSkasowany;

  for(int i = 0; i < N; i++){
    if (i == ktoraKsiazka){
      strcpy(baza[i].tytul, tytul);
      strcpy(baza[i].autor, autor);
      baza[i].liczbaStron = liczbaStron;
      baza[i].wypozyczona = wypozyczona;
      baza[i].rekordSkasowany = rekordSkasowany;

      cout << "Ksiazka numer " << ktoraKsiazka << " edytowana pomyslnie!\n";

      break;
    }
  }

}

void UsunKsiazke(){

  int ktoraKsiazka;

  do{
    cout << "Wpisz ID ksiazki ktora chcesz usunac: \n";
    cin >> ktoraKsiazka;

    if(ktoraKsiazka < 0 || ktoraKsiazka >= N){
      
      cout << "Podano niewlasciwa wartosc. Podaj liczbe z zakresu 0-19!\n";

    }
  } while (ktoraKsiazka < 0 || ktoraKsiazka >= N);

  for (int i = 0; i < N; i++){

    if (i == ktoraKsiazka){

      baza[i].rekordSkasowany = true;
      cout << "Pomyslnie usunieto ksiazke o numerze ID " << ktoraKsiazka << endl;
      break;

    }

  }

}


void WypozyczKsiazke(){

  int ktoraKsiazka;

  do{
    cout << "Wpisz ID ksiazki ktora chcesz wypozyczyc: \n";
    cin >> ktoraKsiazka;

    if(ktoraKsiazka < 0 || ktoraKsiazka >= N){
      
      cout << "Podano niewlasciwa wartosc. Podaj liczbe z zakresu 0-19!\n";

    }
  } while (ktoraKsiazka < 0 || ktoraKsiazka >= N);

  for (int i = 0; i < N; i++){

    if (i == ktoraKsiazka){

      baza[i].wypozyczona = true;
      cout << "Pomyslnie wypozyczono ksiazke o numerze ID " << ktoraKsiazka << endl;
      break;

    }

  }

}

void ZwrocKsiazke(){

  int ktoraKsiazka;

  do{
    cout << "Wpisz ID ksiazki ktora chcesz zwrocic: \n";
    cin >> ktoraKsiazka;

    if(ktoraKsiazka < 0 || ktoraKsiazka >= N){
      
      cout << "Podano niewlasciwa wartosc. Podaj liczbe z zakresu 0-19!\n";

    }
  } while (ktoraKsiazka < 0 || ktoraKsiazka >= N);

  for (int i = 0; i < N; i++){

    if (i == ktoraKsiazka){

      baza[i].wypozyczona = false;
      cout << "Pomyslnie zwrocono ksiazke o numerze ID " << ktoraKsiazka << endl;
      break;

    }

  }

}

void WyswietlWszystkie(){

  for (int i = 0; i < N; i++) {

    if (baza[i].tytul[0] != '\0' && !baza[i].rekordSkasowany) { 
        cout << "ID: " << baza[i].idKsiazki << endl;
        cout << "Tytul: " << baza[i].tytul << endl;
        cout << "Autor: " << baza[i].autor << endl;
        cout << "Liczba stron: " << baza[i].liczbaStron << endl;
        cout << "Wypozyczona: " << (baza[i].wypozyczona ? "tak" : "nie") << endl;
        cout << "Rekord skasowany?: " << (baza[i].rekordSkasowany ? "tak" : "nie") << endl;
        cout << "-------------------------\n";

    }
  }
}

void WyswietlWypozyczone(){

  for (int i = 0; i < N; i++) {

    if (baza[i].wypozyczona == true && !baza[i].rekordSkasowany) { 
        cout << "ID: " << baza[i].idKsiazki << endl;
        cout << "Tytul: " << baza[i].tytul << endl;
        cout << "Autor: " << baza[i].autor << endl;
        cout << "Liczba stron: " << baza[i].liczbaStron << endl;
        cout << "Wypozyczona: " << (baza[i].wypozyczona ? "tak" : "nie") << endl;
        cout << "Rekord skasowany?: " << (baza[i].rekordSkasowany ? "tak" : "nie") << endl;
        cout << "-------------------------\n";

    }
  }
}

int main() {

    int wybierzFunkcje = 0;
    char choice = 'y';

  do{
  
  	cout << "Wybierz funkcję, której chcesz użyć:\n0. Wyjscie z programu.\n1. Dodaj nowa ksiazke.\n2. Edytuj ksiazke.\n3. Usun ksiazke.\n4. Wypozycz ksiazke.\n5. Zwroc ksiazke.\n6. Wyswietl wszystkie ksiazki.\n7. Wyswietl tylko wypozyczone.\n";
    cin >> wybierzFunkcje;
    
    switch(wybierzFunkcje){
      case 0:
        choice = 'n';
        cout << "Pomyslnie zamknieto program.";
        break;
      case 1:
        DodajKsiazke();
        break;
      case 2:
        EdytujKsiazke();
        break;
      case 3:
        UsunKsiazke();
        break;
      case 4:
        WypozyczKsiazke();
        break;
      case 5:
        ZwrocKsiazke();
        break;
      case 6:
        WyswietlWszystkie();
        break;
      case 7:
        WyswietlWypozyczone();
        break;
      default:
        cout << "Nie wybrano zadnej funkcji, czy chcesz kontynuowac? Dla tak 'y' dla nie 'n': ";
        cin >> choice;
        break;

    }

  } while (choice == 'y');

  return 0;
}