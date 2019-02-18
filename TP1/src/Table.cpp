#include "Table.h"

Table::Table() {
        
        capacite_ = MAXCAP;
        commande_= new Plat*[MAXCAP];
        nbPlats_ = 0;
//        setId(-1); // yanis 
        id_ = -1; // Me 
        nbPlaces_ = 1;
        occupee_ = false;
}

Table::Table(int id, int nbPlaces){
        
        capacite_ = MAXCAP;
        commande_= new Plat*[capacite_];
        nbPlats_ = 0;
//        setId(id); // Yanis 
        id_= id; // Me 
        nbPlaces_ = nbPlaces;
        occupee_ = false;
        
        
}

Table::~Table(){
        // THIS IS A MISTAKE, TO UNDERSTAND !!! The if is necessary   --------------------------------------------------------------------------------
        if(commande_ != nullptr){ // Yanis 
                for(unsigned int i=0; i<nbPlats_;i++){
                        delete commande_[i];
                }
                delete[] commande_;
                commande_ = nullptr;
        }
}

int Table::getId() const{
        return id_;
}

int Table::getNbPlaces() const{
        return nbPlaces_;
}

bool Table::estOccupee() const{
        return occupee_;
}


void Table::libererTable(){
        
        // THIS IS A MISTAKE, TO UNDERSTAND !!!  ---------------------------------------------------------------------------------------------------
        /*
         * for(unsigned int i = 0; i < nbPlats_; i++){ // ME 
         *         // desalloue chaque pointeur vers un plat dans le tableau commande_
         *         delete commande_[i]; // ME 
         * }
         */
        
        // desalloue l'espace sur le heap du tableau commande_
       
        delete[] commande_;
        commande_=nullptr;
        occupee_ = false; 

}
// Basically, libererTable and placerClient are the setters for occupee_? 
void Table::placerClient(){
        occupee_ = true;
        
}

void Table::setId(int id){
        id_ = id;
}

void Table::commander(Plat* plat) {
        if (nbPlats_ == capacite_){
                capacite_ *=2;
                Plat** nouvelleCommande = new Plat*[capacite_];
                for(unsigned int i = 0; i<nbPlats_; i++){
                        nouvelleCommande[i] = commande_[i];
                }
                /* On ne supprime que le tableau de pointeurs et non les pointeurs 
                   eux-meme puisqu'on veut les conserver */
                delete[] commande_;
                
                // Plat** commande_ = new Plat*[capacite_]; // GROSSE ERREUR: le pointeur existe encore!!
                
                /* Ici le pointeur vers un tableau "nouvelleCommande" est copier dans
                 commande_, donc commande pointe désormais vers le tableau 
                nouvelleCommande lui aussi */ 
                commande_ = nouvelleCommande;
                commande_[nbPlats_++] = plat;
        } else{
                commande_[nbPlats_++] = plat;
        }
        
}

double Table::getChiffreAffaire() const{
        double profit = 0.0;       
        for(unsigned int i = 0; i < nbPlats_; i++){
                profit += ((commande_[i]->getPrix())-(commande_[i]->getCout()));
        }
        return profit; 

}

void Table::afficher() { 
        if (occupee_){
                if (nbPlats_ != 0){
                        cout << "\t\tLa table numero "
                             << id_ << " est occupee. Voici la commande passee par les clients: "
                             << endl; 
                        for (unsigned int i = 0; i <nbPlats_; i++){
                                commande_[i]->afficher();
                        }  
                } else {
                        cout  << "\t\tLa table numero"
                              << id_ << " est occupee, mais ils n'ont rien commande pour l'instant. "
                              << endl;
                }
        } else {
                cout << "La table numero " << id_ << " est libre." << endl;
        }
}
