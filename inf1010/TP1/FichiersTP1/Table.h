/*
* Titre : Table.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
const  int MAXCAP = 5;
class Table {
public: 
	//constructeurs 
	Table(); 
	Table(int id, int nbPlaces);

	//getters 
	int getId(); 
	int getNbPlaces(); 
	bool estOccupee(); 

	//setters 
	void libererTable(); 
	void placerClient(); 
	void setId(int id); 

	//autres methodes 
	void commander(Plat* plat); 
	double getChiffreAffaire(); 

	//affichage
	void afficher(); 
private : 
	Plat** commande_; 
	unsigned int capacite_; 
	unsigned int nbPlats_; 

	int id_; 
	unsigned int nbPlaces_; 
	bool occupee_; 
};
#endif // !TABLE_H
