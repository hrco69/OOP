#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <ctime>
#define enld endl
#define ret return
using namespace std;

class Knjiga {
public: 
	string naslov;
	string autor;
	int pon;
	int dost;
	Knjiga(string a, string b, int c, int d) : naslov(a), autor(b), pon(c), dost(d) {}
};

bool cmp(Knjiga& a, Knjiga& b) {
	ret a.pon > b.pon;
}

class Knjiznica {
public:
	string naziv;
	string adresa;
	vector<Knjiga> vK;

	Knjiznica(string a, string b, Knjiga c) : naziv(a), adresa(b){
		vK.push_back(c);
	}
	vector<Knjiga> PriKrajuZaliha();

	void sortiraj() {
		sort(vK.begin(), vK.end(), cmp);
	}

};

vector<Knjiga> Knjiznica:: PriKrajuZaliha() {
	vector<Knjiga> t;
	for (Knjiga x : vK)
		if (10 > x.dost) t.push_back(x);
	return t;
}

Knjiznica Najviseprimjeraka(vector<Knjiznica> a) {
	int suma1 = 0;
	int suma2 = 0;
	int b = 0;

	for (int i = 0; i < a.size(); i++) {
		for (Knjiga x : a[i].vK) 
			suma1 += x.dost;

		if (suma1 > suma2){
			suma2 = suma1;
			b = 1;
		}
	}
	return a[b];
}

int main() {
	Knjiga knjiga("Knjiga 1", "Autor 1", 20, 15);
	Knjiznica knjiznica("Knjiznica 1", "Adresa 1", knjiga);

	return 0;
}