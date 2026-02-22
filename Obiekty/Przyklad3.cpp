#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string filename = "studenci.txt";

    // 1. Zapis do pliku (tworzenie/wyczyszczenie pliku)
    ofstream outFile(filename);          // domyślnie ios::out, plik zostanie nadpisany
    if (!outFile) {
        cerr << "Nie mozna otworzyc pliku do zapisu!\n";
        return 1;
    }

    outFile << "Adam Abacki 4.5\n";
    outFile << "Celina Cebacka 5.0\n";
    outFile << "Darek Debacki 3.0\n";
    outFile.close();                     // zawsze zamykamy plik

    // 2. Dopisanie danych na końcu pliku
    ofstream appendFile(filename, ios::app);  // ios::app = dopisywanie na końcu
    if (!appendFile) {
        cerr << "Nie mozna otworzyc pliku do dopisywania!\n";
        return 1;
    }

    appendFile << "Zenon Zebacki 4.0\n";
    appendFile.close();

    // 3. Odczyt linia po linii (np. do wyświetlenia raportu)
    ifstream inFile(filename);           // domyślnie ios::in – tylko do odczytu
    if (!inFile) {
        cerr << "Nie mozna otworzyc pliku do odczytu!\n";
        return 1;
    }

    cout << "Zawartosc pliku (getline):\n";
    string line;
    while (getline(inFile, line)) {      // czyta do znaku nowej linii
        cout << line << '\n';
    }
    inFile.close();

    // 4. Odczyt pola po polu (imie, nazwisko, ocena) z uzyciem fstream
    fstream fileRW(filename, ios::in);   // tu używamy tylko ios::in, ale można też ios::in | ios::out
    if (!fileRW) {
        cerr << "Nie mozna ponownie otworzyc pliku!\n";
        return 1;
    }

    cout << "\nOdczyt strukturalny (operator >>):\n";
    string imie, nazwisko;
    double ocena;

    // operator >> czyta oddzielając białymi znakami (spacja, enter, tab)
    while (fileRW >> imie >> nazwisko >> ocena) {
        cout << "Student: " << imie << ' ' << nazwisko
             << ", ocena: " << ocena << '\n';
    }

    fileRW.close();
    return 0;
}
