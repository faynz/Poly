#include "Menu.h"

Menu::Menu() {
    capacite_ = MAXPLAT;
    listePlats_ = new Plat* [capacite_];
    nbPlats_ = 0;
    type_ = Matin;
}

Menu::Menu(const string& fichier, TypeMenu type ) {
    capacite_ = MAXPLAT;
    type_ = type;
    listePlats_ = new Plat* [capacite_];
    nbPlats_ = 0;
    lireMenu(fichier);
    
}
//(*************ajouter un destructor!!!!!*******
Menu::~Menu() {
    delete [] listePlats_;
    
}
int Menu::getNbPlats() {
    return nbPlats_;
}

Plat* Menu::trouverPlat(string& nom) {
    
    if (nbPlats_ != 0){
        for(unsigned i =0; i < nbPlats_ ; i++) {
            if (listePlats_[i]->getNom() == nom)
                return listePlats_[i];
        }
    }
    return nullptr;
}

void Menu::ajouterPlat(Plat& plat) {
   
    if( capacite_ == 0)
        capacite_= MAXPLAT;
    
    if (capacite_ == nbPlats_ ){
        capacite_ *= 2;
        Plat** nouveauTableau = new Plat* [capacite_];
        
        for (unsigned i=0; i < nbPlats_; i++) {
            nouveauTableau[i] = listePlats_[i];
            
        }
        delete [] listePlats_;
        listePlats_= nouveauTableau;
        listePlats_[nbPlats_++] = &plat;
   
    } else {
        listePlats_[nbPlats_++] = &plat;
    }
}


void Menu::ajouterPlat(string& nom, double montant, double cout) {
    
    Plat* nouveauPlat = new Plat(nom, montant, cout);
    ajouterPlat(*nouveauPlat);
    
}

bool Menu::lireMenu(const string& fichier) {
    ifstream fichierPlats(fichier);
    if (fichierPlats.fail()) {
        
        cout<< "Erreur d'ouverture de fichier"<<endl;
        return false;
        
    }else {
        while (!ws(fichierPlats).eof()) {
            
            string motLu="";
            fichierPlats >> motLu;

            static const string enteteFichierTexte[4] = {"-MATIN", "-MIDI", "-SOIR", "-TABLES"};
            if (enteteFichierTexte[type_] == motLu){
                while(true){
                    string nom;
                    double prix,coutResto;
                    fichierPlats >> nom >> prix >> coutResto;
                    
                    if(nom == "-MIDI" || nom == "-SOIR" || nom == "-TABLES")
                        return true;
                    ajouterPlat(nom, prix, coutResto);
                }
                
            }
            
        }
            return false;
    }
}

void Menu::afficher() {
    static const string typeMenu[3] = {"Matin", "Midi", "SOIR"};
    cout << "-Voici le menu :\n";
    cout << typeMenu[type_] << " -" << endl;
    
    for (unsigned i=0; i < nbPlats_; i++) {
        listePlats_[i]->afficher();
        
    }
}
