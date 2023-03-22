#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
using namespace std;

class Pedalina {
public:
    string boja;
    int kapacitet;
};

class Lokacija {
public:
    string imePrezime;
    double x, y;
    vector<Pedalina> vP;
};


int main() {
    cout << "Unesite broj lokacija (N):";
    int N; cin >> N;
    vector<Lokacija> vL(N);

    for (int i = 0; i < N; i++){
        cout << "Unesite odgovornu osobu i GPS koordinate za " << i + 1 << ". lokaciju:\n";
        getline(cin >> ws, vL[i].imePrezime);
        cin >> vL[i].x >> vL[i].y;
    }

    cout << "Unesite broj pedalina (M): ";
    int M; cin >> M;
    for (int i = 0; i < M; i++){
        int pos;
        cout << "Unesite redni broj lokacije kojoj pripada " << i + 1 << ". pedalina: ";
        cin >> pos; pos -= 1;
        vL[pos].vP.push_back(Pedalina());
        cout << "Unesite boju i kapacitet pedaline:";
        cin >> vL[pos].vP[vL[pos].vP.size() - 1].boja >> vL[pos].vP[vL[pos].vP.size() - 1].kapacitet;
    }

    //ispis
    for (int i = 0; i < N; i++){
        cout << i + 1 << ". " << vL[i].x << " " << vL[i].y << " " << vL[i].imePrezime << " - pedaline:";
        for (Pedalina x: vL[i].vP){
            cout << " " << x.boja << " " << x.kapacitet;
        }
        cout << "\n";
    }
    return 0;
}