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


class Predmet{
public:
    string opis;
    int k;
    Predmet(int a, string b) : k(a), opis(b) {}
};

class Plaza{
public:
    int duljina;
    double x, y;
    vector<Predmet> vP;
};


int main() {
    cout << " Unesite broj plaza (N):";
    int N; cin >> N;
    vector<Plaza> vpp(N);

    for (int i = 0; i < N; i++){
        cout << "Unesite velicinu i lokaciju za " << i + 1 << ". plazu:\n";
        cin >> vpp[i].duljina >> vpp[i].x >> vpp[i].y;
    }

    cout << "Unesite broj predmeta (M):";
    int M; cin >> M;
    for (int i = 0; i < M; i++){
        cout << "Unesite redni broj plaze kojoj pripada " << i + 1 << ". Predmet:";
        int pos; cin >> pos; pos -= 1;
        int kol;
        string p;
        cout << "Unesite kolicinu i opis predmeta:";
        cin >> kol >> p;
        vpp[pos].vP.push_back(Predmet(kol, p));
    }

    // ispis

    for (int i = 0; i < N; i++){
        cout << i + 1 << ". " << vpp[i].x << " " << vpp[i].y << " D=" << vpp[i].duljina << " - predmeti:";
        for (Predmet x : vpp[i].vP) cout << " " << x.k << " " << x.opis;
        cout << enld;
     }



    return 0;
}




