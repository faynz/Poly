/*
* Titre : Client.h - Travail Pratique #3
* Date : 11  Février 2019
* Auteur : Fatou S. Mounzeo
*/
#ifndef CLIENT
#define CLIENT

#include <string>
#include <iostream>

enum StatutClient { Occasionnel,Fidele,Prestige };

class Client{
public:
	Client();
	Client(string nom,string prenom,int tailleGroupe);
	~Client();

// Accesseurs
	StatutClient getStatut();
	int getTailleGroupe();
	string getNom();
	string getPrenom();
	
//Autes méthodes

	friend ostream & operator<<(ostream & os, const Client& client);
private:
	string convertirStatutString() const;

protected:
	string nom_;
	string prenom_;
	int tailleGroupe_;
	StatutClient statut_;
};

#endif

