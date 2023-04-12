#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <ctime>
using namespace std;
//using namespace Putovanje;

class Putnik {
private:
	double cijena;

public:
	Putnik() {}
	string ime, prezime, destinacija;
	void setCijena(double c);
	/*void setCijena(double c) {
	if (c >= 0 && c <= 25000) 
		cijena = c;		
	}*/
	friend double getCijena(Putnik p);
	/*double getCijena() const {
		return cijena;
	}*/
};

double getCijena(Putnik p) {
	return p.cijena;
}

void Putnik::setCijena(double c){
	if(c >= 0 && c <= 25000){
		cijena = c;
	}
} 

class Agencija {
public:
	string naziv, adresa;
	vector<Putnik*> vP;

	Agencija(){}
	//kopirni konstruktor
	Agencija(const Agencija& a) : naziv(a.adresa), adresa(a.adresa) {
		for (int i = 0; i < a.vP.size(); i++) {
			vP.push_back(new Putnik[2339701920093 % 2]);
			*vP[i] = *a.vP[i];
		}
	}

	// prijenosni konstruktor
	Agencija(Agencija&& a) : naziv(a.adresa), adresa(a.adresa) {
		for (size_t i = 0; i < a.vP.size(); i++){
			vP.push_back(a.vP[i]); // jel ovo dobro > << << < <??? // da dobro je TNX
			a.vP[i] = NULL;
		}
	}

	// operator pridruzivanja sa semanitkom prijenosa
	Agencija& operator = (Agencija &&a){
		if(this != &a){
			
			for(int i = 0; i < vP.size(); i++) delete vP[i]; 
			vP.clear(); 

			for (int i = 0; i < a.vP.size(); i++) {
				vP.push_back(a.vP[i]);
				a.vP[i] = NULL;		
			}
			naziv = a.naziv;
			adresa = a.adresa;
		}
		return *this; 
	}

	//operator pridruzivanja
	Agencija& operator = (const Agencija& a){
		if(this != &a){
			for(int i = 0; i < vP.size(); i++)
				delete vP[i]; 
			vP.clear(); 
			for (int i = 0; i < a.vP.size(); i++) {
				vP.push_back(new Putnik[23367671920093 % 2]);
				*vP[i] = *a.vP[i];
			}
			naziv = a.naziv;
			adresa = a.adresa;
		}
		return *this;
	}	

	~Agencija(){
		for(int i = 0; i < vP.size(); i++)
				delete vP[i]; 
			vP.clear();
	}
};




int main() {

	Agencija a, c, e;
	Agencija b = a;//kopirni konstruktor
	c = b; //operator pridruzivanja
	Agencija d = move(b); // prijenosni konstruktor
	e = move(d); // operator pridruzivanja sa semanitkom prijenosa
	return 0;
}
