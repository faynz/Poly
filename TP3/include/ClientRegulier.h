#ifndef CLIENT_REG
#define CLIENT_REG
#include "Client.h"
#include <vector>

const double TAUX_REDUC_REGULIER = 0.1;
const double TAUX_REDUC_PRESTIGE = 0.2;
const double SEUIL_DEBUT_REDUCTION = 75;
const double SEUIL_LIVRAISON_GRATUITE = 200;
class ClientRegulier 
{
public:
	ClientRegulier();
	ClientRegulier(string nom , string prenom, int tailleGroupe ,int nbPoints);


	//Accesseurs
	int getNbPoints();


	//Autres Méthodes
	void augmenterNbPoints(int bonus);
	friend ostream & operator<<(ostream & os, const ClientRegulier& client);
	

protected:
	int nbPoints_;
};
#endif
