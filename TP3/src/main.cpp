/*
* Titre : main.cpp - Travail Pratique #3
* Date : 11 Février 2019 
* Auteur : Fatou S. Mounzeo
*/

#include "Restaurant.h"
#include "ClientPrestige.h"


using namespace std; 

int main() {



	//creation du restaurant 
	Restaurant poly("polyFood.txt", "PolyFood", Soir); 

	///creer plusieurs clients  


	Client * cl1 = new Client("Martin", "b", 1);

	vector<string> commandeMartin;
	commandeMartin.push_back("Muffin");
	commandeMartin.push_back("Poisson");
	Client * cl2 = new Client("Amy", "wh", 15);
	Client * cl3 = new ClientRegulier("Jonh", "sm", 5,25);
	Client * cl4 = new ClientRegulier("Moussa", "T", 3,45);
	Client * cl5 = new ClientPrestige("Andree", "F", 2,150, Zone2);
	Client * cl6 = new ClientPrestige("Marie", "C", 1,125, Zone1);



	cout << "\t\t\t\t\tLIVRAISONS" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	//Livrer les clients Marie et Martins

	cout << "\t\t\t\t\tPLACEMENT DES CLIENT" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	//placer les clients 
	poly.placerClients(cl1);
	poly.placerClients(cl2);
	poly.placerClients(cl3); 
	poly.placerClients(cl4); 
	poly.placerClients(cl5); 

	// commander des plats 

	poly.commanderPlat("Poisson", 1,Custom,3);
	poly.commanderPlat("Pizza", 2, Custom,4);
	poly.commanderPlat("Poulet", 2);
	poly.commanderPlat("Poulet", 4); 
	poly.commanderPlat("Muffin", 4); 
	poly.commanderPlat("Oeuf", 4); 


	//Creation d'une copie du poly restaurant 
	Restaurant poly2(poly);
	poly2.setNom("PolyFood2");

	//Affichage du restaurant poly 
	cout << poly;

	cout << "--------------------------------------------------------------------------------------------------" << endl;


	//liberer les tables et calcule du chiffre d'affaire
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);

	cout << poly;

	cout << "====================================================================================================" << endl;

	// Le restaurant Poly2 ne doit pas encore avoir liberer ses tables
	cout << poly2;

	poly2 = poly;


	cout << "--------------------------------------------------------------------------------------------------" << endl;
	// Le restaurant Poly2 doit maintenant avoir toutes ses tables libérées
	cout << poly2;

	delete cl1;
	delete cl2;
	delete cl3;
	delete cl4;
	delete cl5;

}