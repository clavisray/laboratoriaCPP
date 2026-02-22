/* Załóżmy, że istnieje pewien pojazd wyposażony w komputer pokładowy, rejestrujący przebieg jazdy. Tuż po
uruchomieniu pojazdu tworzony jest plik tekstowy, w którym zapisywane są znaki, określające zdarzenia zachodzące
podczas jazdy. Po zakończeniu jazdy, plik jest zamykany. Nas interesują zdarzenia: przyśpieszanie (oznaczane znakiem a
lub A), zwalnianie (oznaczane znakiem b lub B), skręt w lewo (oznaczany znakiem l lub L), skręt w prawo (oznaczany
znakiem r lub R). W pliku mogą wystąpić inne znaki, oznaczające zdarzenia, które nas w tym momencie nie interesują.
Przykładowa zawartość pliku:
aaxabbvllllyrrsedieeofefefefaaabbbbllrrrr
az
bz
lz
rz
Nas interesują wskazane wyżej znaki:
aaabbllllrraaabbbbllrrrrablr
Na ich podstawie możemy stwierdzić ile razy przyśpieszano, zwalniano, skręcano w lewo i w prawo. W przedstawionym
przykładzie było to dla każdego ze zdarzeń siedem razy.
Zadanie
Naszym zadaniem jest zdefiniowanie klasy, która na podstawie zawartości pliku pozwoli wyznaczenie ile razy
przyśpieszano, zwalniano, skręcano w lewo i w prawo. Klasa ma posiadać następujące publiczne funkcje składowe: */

#include <iostream>
#include <string>
#include <fstream>
#include <cctype> 

class RideReport {
    private:
        int przyspieszenia;
        int zwolnienia;
        int skretyLewo;
        int skretyPrawo;

    public:

        RideReport(const char *fileName){
            
        };

        ~RideReport();
        
        bool readData();
        bool processData();
        int getSpeedUpCount();
        int getSlowDownCount();
        int getLeftTurnCount();
        int getRightTurnCount();
        bool saveCleanedData(const char *fileName);
        bool saveAsText(const char *fileName);
        bool saveAsXML(const char *fileName);

};

int main(){

}