#include "Restaurant.h"

Restaurant::Restaurant() {
        nom_ = nullptr;
        chiffreAffaire_ = 0.0;
        momentJournee_ = Matin;
        menuMatin_ = nullptr;
        menuMidi_ = nullptr;
        menuSoir_ = nullptr;
        capaciteTables_ = INTTABLES;
//        tables_ = new Table*[capaciteTables_]; //yanis 
        tables_ = nullptr; // Me 
        nbTables_ = 0 ;
}

Restaurant::Restaurant(const string& fichier, const string& nom,  TypeMenu moment){
        // Nom restaurant
        nom_ = new string;
        *nom_ = nom;
//        nom_= &nom; // ceci ne marche pas lattribut pointe vers la variable locale qui sera detruite 
        // Tables
        // Le chiffre d'affaire sera calcule dans le main lorsqu'on libere les tables
        chiffreAffaire_ = 0.0;
        
        //Menu, why dynamically ?
        momentJournee_ = moment;
        menuMatin_ = new Menu(fichier, Matin);
        menuMidi_ = new Menu(fichier, Midi);
        menuSoir_ = new Menu(fichier, Soir);
        
        capaciteTables_ = INTTABLES;
        nbTables_ = 0; // GROSSE ERREUR: Attribut oublie!!
        tables_ = new Table*[capaciteTables_];
        lireTable(fichier);
}

Restaurant::~Restaurant(){
        for(unsigned int i = 0; i < nbTables_; i++){
                delete tables_[i];
        }
        delete[] tables_;
        tables_ = nullptr;

        // Ce sont des pointeurs vers des menus (dyn) donc on supprime le menu 
        delete menuMatin_;
        menuMatin_ = nullptr;
        delete menuMidi_;
        menuMidi_ = nullptr;
        delete menuSoir_;
        menuSoir_ = nullptr;
        delete nom_;
        nom_ = nullptr;
}
                

string Restaurant::getNom() const {
        return *nom_;
}

TypeMenu Restaurant::getMoment() const {
        return momentJournee_;
}

void Restaurant::setMoment(TypeMenu moment){
        momentJournee_ = moment;
}

void Restaurant::lireTable(const string& fichier){
        ifstream fichierTable(fichier);

        if (fichierTable.fail()) {
                cout<< "Erreur d'ouverture de fichier"<<endl;
        }else {
                while (!ws(fichierTable).eof()) {
                        string motLu;
                        fichierTable >> motLu;
                        if (motLu == "-TABLES" ){
                                while (!ws(fichierTable).eof()) {
                                        int id, nbPlaces;
                                        fichierTable >> id >> nbPlaces;
// Lorsqu'on appelle une méthode de la classe dans une autre méthode, elle agit sur l'objet courant. C'est comme faire : this->ajouterTable(...)
                                        ajouterTable(id, nbPlaces);
                                }
                        }
                }
        }
}
void Restaurant::ajouterTable(int id, int nbPlaces){
        if (nbTables_ == capaciteTables_){
                capaciteTables_ *= 2;
                Table ** nouvelleTables = new Table*[capaciteTables_];
                for(unsigned int i = 0; i<nbTables_; i++){
                        nouvelleTables[i] = tables_[i];
                }
                delete[] tables_;
                // GROSSE ERREUR : Le pointeur continu d'exister !! pas besoin de creer un autre
                // Table** tables_ = new Table*[capaciteTables_]; Me 
                tables_= nouvelleTables;
        }
        /* On a pas le choix que ce soit dynamique. tables_ ne prend 
           que des pointeurs vers des tables, donc il faut que ce qui lui soit 
           assigne soit une adresse. On pourrait creer une table et ensuite 
           assigne son adresse au tableau tables_ mais cette variable serait 
           locale et donc detruite a la fin de la methode, on aurait donc un
           pointeur qui pointe vers rien. RAPPEL : lorsqu'on INITIALISE une 
           variable dans une methode, on veut que ce soit dynamique, sinon 
           elle est mise sur le stack et detruite lorsqu'on quitte la fonction.*/
        tables_[nbTables_++]= new Table(id, nbPlaces);
}

void Restaurant::libererTable(int id){
        // Needs to find the right table with it's id
        //tables_ pointeur vers un tableau de pointeurs de tables
        //table[i] pointeur vers une table
        
          bool tableTrouvee =false; //Me 
                for(unsigned int i = 0; i < nbTables_; i++){
                        if (tables_[i]->getId() == id){
                                chiffreAffaire_ += tables_[i]->getChiffreAffaire();
                                tables_[i]->libererTable();
                                tableTrouvee = true; // Me 
                        }
                }
                
        // Me 
        if (!tableTrouvee){
                cout << "La table n'a pas été trouvée. Aucune table libérée."
                << endl;
        }
        
}
   

void Restaurant::commanderPlat(const string& nom, int idTable){
        /* you just need to understand the context ! Table is an array
           of orders. This method will add an order to the corresponding 
           table using the ID of the table and the name of the plate */

        /* La classe restaurant contient trois pointeurs vers des menus
           On les dereferences pour utiliser la methode trouverPlat sur le
           menu qui varie en fonction du moment de la journee */
        /* platCommande doit etre dynamique on veut ajoute ce pointeur au
           tableau tables_ on ne veut pas qu'il soit detruit a la fin de la 
           fonction */
        //Part 1 : find the plate
        
        Plat* platCommande = new Plat; // Me 
        platCommande = nullptr; // Me 
        // Plat* platCommande = nullptr; // yanis 
        switch(momentJournee_){
        case Matin:
                platCommande = menuMatin_->trouverPlat(nom);
        case Midi:
                platCommande = menuMidi_->trouverPlat(nom);
        case Soir:
                platCommande = menuSoir_->trouverPlat(nom);       
        }
        //Part 2 : find the table 
        int index = -1 ;
        // DIFFERENCE GRAVE ... javais mit capacite au lieu de nbtables
        for(unsigned int i = 0; i < nbTables_; i++){
                if (tables_[i]->getId() == idTable){
                        index = i;
                }
        }
        
        if((platCommande!=nullptr) & (index != -1)){
                tables_[index]->commander(platCommande);
        }
        
}

void Restaurant::placerClients(int nbClients){
        // Une table de 1000000 personnes est impossible
        int placeSEPP =  1000000; // Suffisante et plus petite (SEPP)
        unsigned int indexMeilleurTable;
        
        for(unsigned int i = 0; i < nbTables_; i++){
                if (!(tables_[i]->estOccupee()) & (nbClients < tables_[i]->getNbPlaces())){
                        if((tables_[i]->getNbPlaces()) < placeSEPP){
                                placeSEPP = tables_[i]->getNbPlaces();
                                indexMeilleurTable = i;
                        }
                }
                        
        }
        if(placeSEPP == 1000000){
                cout << "Erreur : il n'y a plus/pas de table disponible pour le client" << endl;    
        }else{
                tables_[indexMeilleurTable]->placerClient();
        }
        
}

void Restaurant:: afficher() const {
        /*afficher les tables, rappel afficher() de classe Table affiche une 
          seul table */
        if (chiffreAffaire_ == 0.0){
                cout << "Le restaurant " << nom_ << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
        } else {
                cout << "Le restaurant" << nom_ << "a fait un chiffre d'affaire de :" << chiffreAffaire_ << "$" << endl; 
                }
        
        cout << "- Voici les tables :" << endl;
        for (unsigned int i = 0; i < nbTables_; i++){
                tables_[i]->afficher();
        }
        // Afficher le menu courant
        cout << "- Voici son menu : " << endl;
        
        menuMatin_->afficher();    
        menuMidi_->afficher();    
        menuSoir_->afficher();    
        
}
