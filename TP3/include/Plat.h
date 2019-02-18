/*
* Titre : Plat.h - Travail Pratique #3
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std; 

enum TypePlat { Regulier, Bio, Custom };

class Plat {
public: 
	// constructeurs
	//Plat();
	Plat(string nom = "inconnu", double prix = 0, double cout = 0);

	//getters 
	string getNom() const; 
	double getPrix() const; 
	double getCout() const; 
	TypePlat getType() const;

	//setters 
	void setNom(string nom); 
	void setPrix(double prix); 
	
	//methodes en plus 
	bool operator<(const Plat& plat) const ; ///

	friend ostream& operator<<(ostream& os, const Plat& plat); ///

protected:
	TypePlat type_; 
	string nom_; 
	double prix_; 
	double cout_; 



};

#endif // !PLAT_H
