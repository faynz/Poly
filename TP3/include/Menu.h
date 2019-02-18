/*
* Titre : Menu.h - Travail Pratique #3
* Date : 11 Février 2019
* Auteur : Fatou S. Mounzeo
*/

#ifndef MENU_H
#define MENU_H 

#include <fstream>
#include <vector>
#include"PlatBio.h"



enum TypeMenu{Matin, Midi, Soir};

class Menu {
public: 
	// constructeurs
	Menu(); 
	Menu(string fichier, TypeMenu type);
	///TODO
	Menu(const Menu& menu); ///A modifier


	//getters
	vector<Plat*> getListePlats() const; 
	
	//methodes en plus
	Plat* trouverPlat(const string& nom) const; 
	Menu& operator+=(const Plat& plat); 
	///TODO
	Menu& operator+=(const PlatBio& plat); 
	///TODO 
	Menu& operator=(const Menu& menu); ///A MODIFIER
	void lireMenu(const string& fichier); 
	Plat* trouverPlatMoinsCher() const;
	///TODO 
	friend ostream& operator<<(ostream& os, const Menu& menu); ///A modifier
	
private : 
	vector<Plat*> listePlats_; 
	TypeMenu type_; 

};

#endif // !MENU_H
