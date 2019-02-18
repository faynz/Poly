/*
* Titre : Restaurant.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
const int INTTABLES = 6;
class Restaurant {
public: 
	//constructeurs 
	Restaurant(); 
	Restaurant(const string& fichier, const string& nom,  TypeMenu moment);
        ~Restaurant();

	//setters 
	void setMoment(TypeMenu moment); 

	//getters 
	string getNom() const; 
	TypeMenu getMoment() const; 

	//Autres methodes 
	void lireTable(const string& fichier); 
	void ajouterTable(int id, int nbPlaces);
	void libererTable(int id); 
	void commanderPlat(const string& nom, int idTable);
	void placerClients(int nbClients); 

	//affichage 
	void afficher() const;

private: 
	string* nom_; 

	double chiffreAffaire_; 
	TypeMenu momentJournee_; 

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_; 
	Menu* menuMidi_; 
	Menu* menuSoir_; 

	//liste des tables 
	unsigned int capaciteTables_;
	Table** tables_; 
	unsigned int nbTables_; 

};
#endif // !RESTAURANT_H
