/*
* Titre : PlatBio.h - Travail Pratique #2
* Date : 11 Février 2019
* Auteur : Fatou S. MOUNZEO
*/

#ifndef PLAT_BIO_H
#define PLAT_BIO_H

#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio  {
public:
	// constructeurs
	PlatBio(string nom = "inconnu", double prix = 0, double cout = 0,double ecotaxe = 0);
	
	//getters 
	double getEcoTaxe() const;

	//setters 
	void setEcoTaxe(double ecoTaxe);




	//methodes en plus 

	friend ostream& operator<<(ostream& os, const PlatBio& plat); ///

private:
	double ecoTaxe_;	
};

#endif // !PLAT_BIO_H