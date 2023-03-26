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


class Artikl {
public:
    string naziv;
    int kolicina;
    double cijena_po_kg;
    Artikl() = default;
    Artikl(string a, int b, double c) : naziv(a), kolicina(b), cijena_po_kg(c) {}
};


bool cmp(Artikl a, Artikl b) {
    return (a.cijena_po_kg * a.kolicina) > (b.cijena_po_kg * b.kolicina);
}

class Racun {
public:
    int br;
    vector<Artikl> artikl;
    Racun(int a) : br(a) {};

    void dodaj(Artikl a) {
        artikl.push_back(a);
    }

    double ukupnaCijena() {
        double a = 0;
        for (Artikl x : artikl)
            a += x.kolicina * x.cijena_po_kg;
        return a;
    }

    Artikl najskuplji() {
        sort(artikl.begin(), artikl.end(), cmp);
        return artikl[0];
    }

};

class Kupac {
public:
    Racun racun;
    Kupac(Racun a) : racun(a) {}
};

int main() {

    Kupac Ante(Racun(1)); // Ante ima racun broj 1
    Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
    Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
    Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
    cout << "Ukupno: " << Ante.racun.ukupnaCijena() << " kn" << endl; // 41 kn
    cout << "Najskuplje placeni artikl je " << Ante.racun.najskuplji().naziv << " (" << Ante.racun.najskuplji().cijena_po_kg * Ante.racun.najskuplji().kolicina << ")";
    return 0;
}