#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <ctime> 
#define cahr char
#define enld endl
using namespace std;

class Igrac {
public:
	string ime;
	vector<int> Karta;
	Igrac(string _ime) : ime(_ime) {}
};

class Spil {
public:
	vector<int> vK;

	Spil(bool mix_karte) : vK(vector<int>(52)) {
		for (int i = 0; i < 52; i++) vK[i] = i + 1;
		if (mix_karte) {
			srand((unsigned)time(NULL));
			random_shuffle(vK.begin(), vK.end());
		}
	}

	void Podijeli4Karte(Igrac* igrac) {
		for (int i = 0; i < 4; i++){
			igrac->Karta.push_back(vK[0]);
			vK.erase(vK.begin());
		}
	}
};

int main() {
	int N;
	vector<Igrac> igrac;
	Spil sendit(false);

	cout << "Unesi broj igraca: ";
	cin >> N;
	if (N > 13) {cout << "previse igraca!"; return -1;}

	for (int i = 0; i < N; i++) {
		string ime;
		cout << "Ime " << i + 1 << ". igraca: ";
		cin >> ime;
		igrac.push_back(Igrac(ime));
	}

	cout << "\nKarte u spilu (" << sendit.vK.size() << "):\n";

	for (int i = 0; i < sendit.vK.size(); i++){
		cout << sendit.vK[i];
		if (!(((i % 13)+1)%13) && i != 0) cout << "\n";
		else cout << "\t";
	}
	cout << "\n\n";

	for (int i = 0; i < igrac.size(); i++){
		sendit.Podijeli4Karte(&igrac[i]);
		cout << igrac[i].ime << " je dobio seljedece karte: ";
		for (int x : igrac[i].Karta) cout << "\t" << x ;
		cout << "\n";
	}
	cout << enld;

	cout << "Presotle Karte u spilu (" << sendit.vK.size() << "):\n";
	for (int i = 0; i < sendit.vK.size(); i++){
		int x = sendit.vK.size() / 4;
		cout << sendit.vK[i];
		if (!(((i % x)+1)%x) && i != 0) cout << "\n";
		else cout << "\t";
	}

	return 0;
}