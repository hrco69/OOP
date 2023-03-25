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


class Student {
public:
    string ime_prezime;
    string oib;

    Student(string a, string b) : ime_prezime(a), oib(b) {}
};


class Bodovi{
public:
    int bodovi;
    Student student;

    Bodovi(Student s, int b) : student(s), bodovi(b) {}
};

bool cmp(Bodovi a, Bodovi b) {
    if (a.student.ime_prezime.compare(b.student.ime_prezime) < 0) return true;
    else return false;
}

class Kolegij {
public: 
    string kolegij;
    vector<Bodovi> bodovi;

    Kolegij(string a, vector<Bodovi> b) : kolegij(a), bodovi(b) {}

    void ispis() {
        sort(bodovi.begin(), bodovi.end(), cmp);
        for (Bodovi x : bodovi){
            cout << x.student.ime_prezime << " " << x.student.oib << " " << x.bodovi << enld;
         }
    }
};


    /* Preko objekta OOP ispisite bodove svih studenata tog kolegija pocevsi od
       onih s najmanjim brojem bodova prema vecim. Npr.;
       Objektno orijentirano programiranje bodovi:
       Ivica Ivanovic  0246005654      20
       Ivana Ivic      0246002475      25
       Marko Markic    0246004234      32
    */

int main() {

    vector<Bodovi> OOPBodovi{
    Bodovi(Student("Ivana Ivic", "0246002475"), 25),
    Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
    Bodovi(Student("Marko Markic", "0246004234"), 32) };

    Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);
    OOP.ispis();


    return 0;


}




