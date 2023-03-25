#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <ctime>
#include <iomanip>
#include <memory.h>
#define cahr char
#define enld endl
using namespace std;

class Cipela {
public:
    int broj;
    string materijal;
    string boja;

    Cipela(int a, string b, string c) : broj(a), materijal(b), boja(c) {}
};

class Narudzba {
public: 
    string narucitelj;
    vector<Cipela> vC;

    void dodajCipelu(Cipela c) {
        vC.push_back(Cipela(c));
    }

    Narudzba() = default;
    Narudzba(string a) : narucitelj(a) {}

};

class Postolar {
public:
    vector<Narudzba> vN;

    double preuzmiNarudzbu(Narudzba x) {
        vN.push_back(Narudzba(x));
        double a = 0;
        for (Cipela x : vN[vN.size() - 1].vC){
            a += x.broj * 10.5;
        }
        return a;
    }

    void ispisiNarudzbe() {
        cout << enld;
        for (Narudzba x : vN){
            cout << x.narucitelj << " : \n";
            for (Cipela y : x.vC)
                cout << y.boja << " " << y.broj << " " << y.materijal << enld;
            cout << endl;
        }
    }
};

int main() {

    Postolar p;
    Narudzba n1;

    n1.narucitelj = "Susjed Mirko";
    //Cipela ima broj (velicinu), materijal i boju
    n1.dodajCipelu(Cipela(47, "Sky", "plava"));
    n1.dodajCipelu(Cipela(44, "Platno", "zelena"));

    //Cijena izrade jedne cipele se racuna na nacin da se velicina (broj cipele) pomnozi sa 10.5
    double c1 = p.preuzmiNarudzbu(n1);
    cout << "Ukupna cijena 1. narudzbe je " << c1 << endl;

    Narudzba n2("Barica");
    n2.dodajCipelu(Cipela(43, "Koza", "crna"));
    double c2 = p.preuzmiNarudzbu(n2);
    cout << "Ukupna cijena 2. narudzbe je " << c2 << endl;

    //Ispisuje sve narudzbe
    //Za svaku narudzbu ispisuje tko je narucitelj, te popis svih cipela koje su narucene
    p.ispisiNarudzbe();

    return 0;
}