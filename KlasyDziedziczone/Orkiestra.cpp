#include <iostream>
#include <string>

class Instrument {

    protected:
        std::string nazwa;
    
    public:
    Instrument(const std::string& n) : nazwa(n) {

    };

    virtual void graj() const = 0;
    virtual double glosnosc() const = 0;
    virtual void pokazInfo() const = 0;

    virtual ~Instrument() {};

};

class Skrzypce : public Instrument {

    public:
        Skrzypce(const std::string& n)
            : Instrument(n){}
        
        void pokazInfo() const override {
            std::cout << "Instrument: " << nazwa << ", ";
        }

        void graj() const override {
            std::cout << "Skrrreeee..., ";
        }
        
        double glosnosc() const override {
            return 8.5;
        }
};

class Bongo : public Instrument {
    public:
        Bongo(const std::string& n)
            : Instrument(n){}

        void pokazInfo() const override {
            std::cout << "Instrument: " << nazwa << ", ";
        }
        
        void graj() const override {
            std::cout << "Bum-bum tss!, ";
        }

        double glosnosc() const override {
            return 9.0;
        }
};

class Flet : public Instrument {
    public:
        Flet(const std::string& n)
            : Instrument(n){}

        void pokazInfo() const override {
            std::cout << "Instrument: " << nazwa << ", ";
        }

        void graj() const override {
            std::cout << "Fiuuuu..., ";
        }

        double glosnosc() const override {
            return 6.0;
        }
};





int main(){

    Instrument* orkiestra[3];
    orkiestra[0] = new Skrzypce("Stradivarius");
    orkiestra[1] = new Bongo("Afrykańskie");
    orkiestra[2] = new Flet("Poprzeczny");

    for(int i = 0; i < 3; i++) {

        orkiestra[i]->pokazInfo();
        std::cout << "Gra: ";
        orkiestra[i]->graj();
        std::cout << "Glosnosc: " << orkiestra[i]->glosnosc() << std::endl;
        delete orkiestra[i];
        
    }
    return 0;
}