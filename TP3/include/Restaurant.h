/*
* Titre : Restaurant.h - Travail Pratique #1
* Date : 11 Fevrier 2019
* Auteur : Fatou S. Mounzeo
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
#include "ClientPrestige.h"

const int NB_ZONES_LIVR = 3;
const int INDEX_TABLE_LIVRAISON = 4;


class Restaurant {
public:
	//constructeurs
	Restaurant();
	Restaurant(const string& fichier, const string& nom,  TypeMenu moment);
	Restaurant(const Restaurant& restau); 

	//destructeur
	~Restaurant();

	//setters
	void setMoment(TypeMenu moment);
	void setNom(const string& nom); 

	//getters
	string getNom() const;
	TypeMenu getMoment() const;
	double getFraisTransports(int index) const;

	//Autres methodes
	void lireTable(const string& fichier);
	void lireAdresses(const string& fichier);

	Restaurant& operator+=(Table* table); 
	///TODO
	void libererTable(int id); /// A Modifier
	///TODO 
	void commanderPlat(const string& nom, int idTable, TypePlat type= Regulier,int nbIngredients = 0); ///A modifier
	bool operator < (const Restaurant& restau) const ;
	Restaurant& operator = (const Restaurant& restau); 
	///TODO 
	void placerClients(int nbClients);///A Modifier
	///TODO
	void livrerClient(Client * client, vector<string>nomPlats);
	///TODO
	double calculerReduction(Client* client, double montant, bool livraison);
	//TODO
	friend ostream& operator<<(ostream& os, const Restaurant& restau); 




private:
	string* nom_;

	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	//liste des tables
	vector<Table*> tables_;

	//Tarif des trois zones de livraison nouvel attribut
	double fraisTransport_[NB_ZONES_LIVR]; 


};
#endif // !RESTAURANT_H
