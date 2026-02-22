#include <iostream>
#include <fstream>
#include <string>
#include <cctype>   // tolower

using namespace std;

class CzarnaSkrzynka
{
public:
    CzarnaSkrzynka(const string& nazwaPliku);
    ~CzarnaSkrzynka(); 

    bool readData();
    bool processData();

    int getSpeedUpCount() const;
    int getSlowDownCount() const;
    int getLeftTurnCount() const;
    int getRightTurnCount() const;

    bool saveCleanedData(const string& nazwaPliku);
    bool saveAsText(const string& nazwaPliku);
    bool saveAsXML(const string& nazwaPliku);

private:
    string nazwaPliku;  
    string dane;        

    bool dataLoaded;    
    bool processed;     

    int przyspieszenia;
    int zwolnienia;
    int leweSkrety;
    int praweSkrety;
};


CzarnaSkrzynka::CzarnaSkrzynka(const string& nazwaPliku_)
    : nazwaPliku(nazwaPliku_),
      dane(""),
      dataLoaded(false),
      processed(false),
      przyspieszenia(0),
      zwolnienia(0),
      leweSkrety(0),
      praweSkrety(0)
{
}

CzarnaSkrzynka::~CzarnaSkrzynka()
{
  
}

bool CzarnaSkrzynka::readData()
{
    dataLoaded = false;
    processed = false;
    dane.clear();

    if (nazwaPliku.empty())
        return false;

    ifstream inFile(nazwaPliku);  
    if (!inFile)
        return false;

    char ch;
    while (inFile.get(ch))        
    {
        dane += ch;
    }

    dataLoaded = true;
    return true;
}

bool CzarnaSkrzynka::processData()
{
    if (!dataLoaded)
    {
        processed = false;
        return false;
    }

    przyspieszenia = 0;
    zwolnienia     = 0;
    leweSkrety     = 0;
    praweSkrety    = 0;

    for (size_t i = 0; i < dane.size(); ++i)
    {
        char ch = dane[i];
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));

        if (ch == 'a')
            ++przyspieszenia;
        else if (ch == 'z')
            ++zwolnienia;
        else if (ch == 'l')
            ++leweSkrety;
        else if (ch == 'r')
            ++praweSkrety;
    }

    processed = true;
    return true;
}

int CzarnaSkrzynka::getSpeedUpCount() const
{
    return processed ? przyspieszenia : -1;
}

int CzarnaSkrzynka::getSlowDownCount() const
{
    return processed ? zwolnienia : -1;
}

int CzarnaSkrzynka::getLeftTurnCount() const
{
    return processed ? leweSkrety : -1;
}

int CzarnaSkrzynka::getRightTurnCount() const
{
    return processed ? praweSkrety : -1;
}

bool CzarnaSkrzynka::saveCleanedData(const string& nazwaPlikuWyj)
{
    if (!dataLoaded)
        return false;

    ofstream outFile(nazwaPlikuWyj);   
    if (!outFile)
        return false;

    for (size_t i = 0; i < dane.size(); ++i)
    {
        char ch = dane[i];
        char lower = static_cast<char>(tolower(static_cast<unsigned char>(ch)));

        if (lower == 'a' || lower == 'z' || lower == 'l' || lower == 'r')
        {
            outFile << ch;
        }
    }

    return true;
}

bool CzarnaSkrzynka::saveAsText(const string& nazwaPlikuWyj)
{
    if (!processed)
        return false;

    ofstream outFile(nazwaPlikuWyj);
    if (!outFile)
        return false;

    outFile << "Raport dla pliku: " << nazwaPliku << "\n";
    outFile << "Przyspieszenia: " << przyspieszenia << "\n";
    outFile << "Hamowania: "     << zwolnienia     << "\n";
    outFile << "Lewo: "          << leweSkrety     << "\n";
    outFile << "Prawo: "         << praweSkrety    << "\n";

    return true;
}

bool CzarnaSkrzynka::saveAsXML(const string& nazwaPlikuWyj)
{
    if (!processed)
        return false;

    ofstream outFile(nazwaPlikuWyj);
    if (!outFile)
        return false;

    outFile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    outFile << "<report file=\"" << nazwaPliku << "\">\n";
    outFile << "  <speed-up-count>"  << przyspieszenia << "</speed-up-count>\n";
    outFile << "  <slow-down-count>" << zwolnienia     << "</slow-down-count>\n";
    outFile << "  <left-turn-count>" << leweSkrety     << "</left-turn-count>\n";
    outFile << "  <right-turn-count>"<< praweSkrety    << "</right-turn-count>\n";
    outFile << "</report>\n";

    return true;
}


int main()
{
    CzarnaSkrzynka report("dane.txt");

    if (report.readData())
    {
        if (report.processData())
        {
            cout << "\nPrzyspieszenia: " << report.getSpeedUpCount();
            cout << "\nHamowania: "     << report.getSlowDownCount();
            cout << "\nW lewo: "        << report.getLeftTurnCount();
            cout << "\nW prawo: "       << report.getRightTurnCount();

            if (report.saveCleanedData("dane_czyste.txt"))
                cout << "\nOczyszczone dane zapisane";

            if (report.saveAsText("raport.txt"))
                cout << "\nRaport tekstowy zapisany";

            if (report.saveAsXML("raport.xml"))
                cout << "\nPlik XML zapisany";
        }
        else
        {
            cout << "\nNie udalo sie przetworzyc danych.";
        }
    }
    else
    {
        cout << "\nNie udalo sie odczytac pliku z danymi.";
    }

    cout << endl;
    return 0;
}
