#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdlib>

class CzarnaSkrzynka
{
public:
    CzarnaSkrzynka(const char *nazwaPliku);
    ~CzarnaSkrzynka();

    bool readData();
    bool processData();

    int getSpeedUpCount();
    int getSlowDownCount();
    int getLeftTurnCount();
    int getRightTurnCount();

    bool saveCleanedData(const char *nazwaPliku);
    bool saveAsText(const char *nazwaPliku);
    bool saveAsXML(const char *nazwaPliku);

private:
    char *m_nazwaPliku;   // nazwa pliku z danymi
    char *m_danePliku;       // dane z pliku 
    std::size_t m_wielkoscDanych;

    bool m_dataLoaded;  // czy readData() zakończyło się powodzeniem
    bool m_processed;   // czy processData() zostało poprawnie wykonane

    int m_przyspieszenia;
    int m_zwolnienia;
    int m_leweSkrety;
    int m_praweSkrety;
};

// implementacja klasy CzarnaSkrzynka

CzarnaSkrzynka::CzarnaSkrzynka(const char *nazwaPliku)
    : m_nazwaPliku(nullptr),
      m_danePliku(nullptr),
      m_wielkoscDanych(0),
      m_dataLoaded(false),
      m_processed(false),
      m_przyspieszenia(0),
      m_zwolnienia(0),
      m_leweSkrety(0),
      m_praweSkrety(0)
{
    // konstruktor tylko zapamietuje nazwe pliku w tablicy dynam.
    if (nazwaPliku != nullptr)
    {
        std::size_t len = std::strlen(nazwaPliku);
        m_nazwaPliku = new char[len + 1];
        std::strcpy(m_nazwaPliku, nazwaPliku);
    }
    else
    {
        // brak nazwy pliku – readData() nie powiedzie się
        m_nazwaPliku = nullptr;
    }
}

CzarnaSkrzynka::~CzarnaSkrzynka()
{
    delete[] m_nazwaPliku;
    delete[] m_danePliku;
}

bool CzarnaSkrzynka::readData()
{
    // wyczyszczenie poprezdniego stanu
    m_dataLoaded = false;
    m_processed = false;
    delete[] m_danePliku;
    m_danePliku = nullptr;
    m_wielkoscDanych = 0;

    if (m_nazwaPliku == nullptr)
    {
        return false;
    }

    FILE *f = std::fopen(m_nazwaPliku, "rb");
    if (!f)
    {
        return false;
    }

    // ustawienie rozmiaru plikow
    if (std::fseek(f, 0, SEEK_END) != 0)
    {
        std::fclose(f);
        return false;
    }

    long rozmiarPliku = std::ftell(f);
    if (rozmiarPliku < 0)
    {
        std::fclose(f);
        return false;
    }

    std::rewind(f);

    // alokowanie pamieci pod zawartosc pliku (+1 na '\0', dla wygody)
    if (rozmiarPliku == 0)
    {
        // pusty plik traktowany jako odczytany z brakiem danych
        m_danePliku = new char[1];
        m_danePliku[0] = '\0';
        m_wielkoscDanych = 0;
        m_dataLoaded = true;
        std::fclose(f);
        return true;
    }

    m_danePliku = new char[static_cast<std::size_t>(rozmiarPliku) + 1];

    std::size_t readBytes =
        std::fread(m_danePliku, 1, static_cast<std::size_t>(rozmiarPliku), f);

    std::fclose(f);

    if (readBytes != static_cast<std::size_t>(rozmiarPliku))
    {
        delete[] m_danePliku;
        m_danePliku = nullptr;
        m_wielkoscDanych = 0;
        return false;
    }

    m_danePliku[readBytes] = '\0';
    m_wielkoscDanych = readBytes;
    m_dataLoaded = true;

    return true;
}

bool CzarnaSkrzynka::processData()
{
    if (!m_dataLoaded || m_danePliku == nullptr)
    {
        m_processed = false;
        return false;
    }

    m_przyspieszenia   = 0;
    m_zwolnienia  = 0;
    m_leweSkrety  = 0;
    m_praweSkrety = 0;

    for (std::size_t i = 0; i < m_wielkoscDanych; ++i)
    {
        unsigned char uch = static_cast<unsigned char>(m_danePliku[i]);
        char ch = static_cast<char>(std::tolower(uch));

        switch (ch)
        {
        case 'a':
            ++m_przyspieszenia;
            break;
        case 'b':
            ++m_zwolnienia;
            break;
        case 'l':
            ++m_leweSkrety;
            break;
        case 'r':
            ++m_praweSkrety;
            break;
        default:
            // ignorowanie innych znakow
            break;
        }
    }

    m_processed = true;
    return true;
}

int CzarnaSkrzynka::getSpeedUpCount()
{
    return m_processed ? m_przyspieszenia : -1;
}

int CzarnaSkrzynka::getSlowDownCount()
{
    return m_processed ? m_zwolnienia : -1;
}

int CzarnaSkrzynka::getLeftTurnCount()
{
    return m_processed ? m_leweSkrety : -1;
}

int CzarnaSkrzynka::getRightTurnCount()
{
    return m_processed ? m_praweSkrety : -1;
}

bool CzarnaSkrzynka::saveCleanedData(const char *nazwaPliku)
{
    if (!m_dataLoaded || m_danePliku == nullptr || nazwaPliku == nullptr)
        return false;

    FILE *f = std::fopen(nazwaPliku, "wb");
    if (!f)
        return false;

    for (std::size_t i = 0; i < m_wielkoscDanych; ++i)
    {
        unsigned char uch = static_cast<unsigned char>(m_danePliku[i]);
        char ch = static_cast<char>(std::tolower(uch));

        if (ch == 'a' || ch == 'b' || ch == 'l' || ch == 'r')
        {
            // zapisanie oryginalnego znaku z zachowaniem wielkości liter
            std::fputc(m_danePliku[i], f);
        }
    }

    std::fclose(f);
    return true;
}

bool CzarnaSkrzynka::saveAsText(const char *nazwaPliku)
{
    if (!m_processed || nazwaPliku == nullptr)
        return false;

    FILE *f = std::fopen(nazwaPliku, "w");
    if (!f)
        return false;

    // bieżąca data i czas
    std::time_t now = std::time(nullptr);
    std::tm *lt = std::localtime(&now);
    if (!lt)
    {
        std::fclose(f);
        return false;
    }

    char dateBuf[11]; // "rrrr-mm-dd"
    char timeBuf[9];  // "gg:mm:ss"

    std::strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", lt);
    std::strftime(timeBuf, sizeof(timeBuf), "%H:%M:%S", lt);

    std::fprintf(f, "Raport dla pliku:\n");
    std::fprintf(f, "%s\n", m_nazwaPliku ? m_nazwaPliku : "");
    std::fprintf(f, "Data utworzenia:\n");
    std::fprintf(f, "%s\n", dateBuf);
    std::fprintf(f, "Czas utworzenia:\n");
    std::fprintf(f, "%s\n", timeBuf);
    std::fprintf(f, "Przyspieszenia: %d\n", m_przyspieszenia);
    std::fprintf(f, "Hamowania: %d\n", m_zwolnienia);
    std::fprintf(f, "Lewo: %d\n", m_leweSkrety);
    std::fprintf(f, "Prawo: %d\n", m_praweSkrety);

    std::fclose(f);
    return true;
}

bool CzarnaSkrzynka::saveAsXML(const char *nazwaPliku)
{
    if (!m_processed || nazwaPliku == nullptr)
        return false;

    FILE *f = std::fopen(nazwaPliku, "w");
    if (!f)
        return false;

    std::time_t now = std::time(nullptr);
    std::tm *lt = std::localtime(&now);
    if (!lt)
    {
        std::fclose(f);
        return false;
    }

    char deklaracjaDaty[11]; // "rrrr-mm-dd"
    char deklaracjaCzasu[9];  // "gg:mm:ss"

    std::strftime(deklaracjaDaty, sizeof(deklaracjaDaty), "%Y-%m-%d", lt);
    std::strftime(deklaracjaCzasu, sizeof(deklaracjaCzasu), "%H:%M:%S", lt);

    std::fprintf(f, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    std::fprintf(
        f,
        "<report file=\"%s\" date=\"%s\" time=\"%s\">\n",
        m_nazwaPliku ? m_nazwaPliku : "",
        deklaracjaDaty,
        deklaracjaCzasu
    );
    std::fprintf(f, "<speed-up-count>%d</speed-up-count>\n", m_przyspieszenia);
    std::fprintf(f, "<slow-down-count>%d</slow-down-count>\n", m_zwolnienia);
    std::fprintf(f, "<left-turn-count>%d</left-turn-count>\n", m_leweSkrety);
    std::fprintf(f, "<right-turn-count>%d</right-turn-count>\n", m_praweSkrety);
    std::fprintf(f, "</report>\n");

    std::fclose(f);
    return true;
}


int main()
{
    CzarnaSkrzynka report("dane.txt");

    if (report.readData())
    {
        if (report.processData())
        {
            std::cout << "\nPrzyspieszenia: " << report.getSpeedUpCount();
            std::cout << "\nHamowania: " << report.getSlowDownCount();
            std::cout << "\nW lewo: " << report.getLeftTurnCount();
            std::cout << "\nW prawo: " << report.getRightTurnCount();

            if (report.saveCleanedData("dane_czyste.txt"))
                std::cout << "\nOczyszczone dane zapisane";

            if (report.saveAsText("raport.txt"))
                std::cout << "\nRaport tekstowy zapisany";

            if (report.saveAsXML("raport.xml"))
                std::cout << "\nPlik XML zapisany";
        }
        else
        {
            std::cout << "\nNie udalo sie przetworzyc danych.";
        }
    }
    else
    {
        std::cout << "\nNie udalo sie odczytac pliku z danymi.";
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}
