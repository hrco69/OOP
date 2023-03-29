#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <ctime>
#define enld endl
using namespace std;

class Automobil {
public:
	string brend;
	string gorivo;
	int ks;
	int prize;

	Automobil(string a, string b, int c, int d) : brend(a), gorivo(b), ks(c), prize(d) {}

};

bool cmp(Automobil& a, Automobil& b) {
	return a.ks < b.ks;
}

class	AutoSalon {
public:
	string naziv;
	string adresa;
	vector<Automobil> vA;
	AutoSalon(string a, string b, vector<Automobil> c) : naziv(a), adresa(b), vA(c) {}
	vector<Automobil> Strongestcar();

	void Sortiraj() {
		sort(vA.begin(), vA.end(), cmp);
	}
};

vector<Automobil> AutoSalon::Strongestcar() {
	vector<Automobil> a;
	for (int i = 0; i < vA.size(); i++)
		if (100 < vA[i].ks)
			a.push_back(vA[i]);
	return a;
}


AutoSalon Najskupljikurac(vector<AutoSalon> a) {
	double prosjek = 0;
	double prosjek1 = 0;
	int b = 0;

	for (int i = 0; i < a.size(); i++){
		for (Automobil x : a[i].vA)
		{
			prosjek += x.prize;
		}
		prosjek /= a[i].vA.size();

		if (prosjek > prosjek1){
			prosjek1 = prosjek;
			b = i;
		}
	}
	return a[b];
}




int main() {

	vector<Automobil> auti = { Automobil("BMW 118i" , "benzin", 150, 225000), Automobil("Dacija" , "plin", 91, 114200) ,Automobil("citroen C3" , "dizel", 110, 127000) };
	AutoSalon autosalon("Auto Salon", "Rijeka", auti);

	return 0;
}