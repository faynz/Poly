#include "Menu.h"

Menu::Menu() {
        capacite_ = MAXPLAT;
        listePlats_ = new Plat* [capacite_];  
        nbPlats_ = 0; 
        type_ = Matin; 
}

Menu::Menu(const string& fichier, TypeMenu type) {
        capacite_ = MAXPLAT;
        listePlats_ = new Plat* [capacite_];  
        type_ = type;
        nbPlats_ = 0;
        // Ajoute les plats dans le menu.
        lireMenu(fichier);
}

Menu::~Menu(){
        for (unsigned int i = 0; i < nbPlats_; i++){
                /* (FAUX:  listePlats_[i] retourne un pointeur vers un tableau de Plats 
                   On appelle l'opérateur delete[] lorsqu'il s'agit d'un tableau
                   On désalloue la mémoire de chaque pointeurs vers un tableau)

                   listePlats_[i] retourne un pointeur vers un Plat. On appelle
                   l'opérateur delete pour désalloué l'espace alloué à ce pointeur */

                delete listePlats_[i];
        }
        
        /* 2. On désalloue enfin l'espace attribué à listePlats un pointeur
           vers un tableau de pointeurs qui se trouvait également sur le heap
        */
        delete[] listePlats_;
        
        listePlats_ = nullptr;
}

int Menu::getNbPlats() const{
        return nbPlats_;
}

//listePlats est un tableau de pointeurs, listePlats_[i] retourne un pointeur contenant 'adresse du Plat en question.
Plat* Menu::trouverPlat(const string& nom) const{
        
        if (nbPlats_ != 0){ // difference (pas change)
                for (unsigned int i = 0; i < nbPlats_; i++){
                        if (listePlats_[i]->getNom() == nom){
                                return listePlats_[i];
                        }
                }
        }
        cout << "Plat inexistant";
        return nullptr;
        
}

void Menu::ajouterPlat(Plat & plat) {
        if (nbPlats_ == capacite_){
                capacite_*=2;
                Plat** nouveauTableau = new Plat*[capacite_];
                for(unsigned int i = 0; i < nbPlats_; i++){
                        // Copie les pointeurs vers des plats dans le nouveauTableau
                        nouveauTableau[i]= listePlats_[i];
                }
                // On ne veut pas supprimer les pointeurs v 
                delete[] listePlats_;
                listePlats_ = nouveauTableau;
                /* Le contenu de listePlats a ete supprime, mais le pointeur continu
                   d'exister, donc il est possible de simplement le reutiliser
                   en le faisant egaler a nouveauTableau il pointe simplement vers ce tableau
                */
                listePlats_[nbPlats_++] = &plat;
        }else{
                
                listePlats_[nbPlats_++] = &plat;
        }

}

void Menu::ajouterPlat(const string& nom, double montant, double cout){
        /* Doit être un dynamique parce que sinon la variable sera
           détruite à la fin de cette méthode (var. loc.) */
        Plat* nouveauPlat = new Plat(nom, montant, cout);
        ajouterPlat(*nouveauPlat);                
}

bool Menu::lireMenu(const string& fichier) {
        ifstream fichierPlats(fichier);
        if (fichierPlats.fail()) {
        
                cout << "Erreur d'ouverture de fichier" << endl;
                return false;
        
        } else {
                while (!ws(fichierPlats).eof()) {
            
                        string motLu; // Me, its fine 
                        fichierPlats >> motLu;

                        static const string enteteFichierTexte[4] = {"-MATIN", "-MIDI", "-SOIR", "-TABLES"};
                        if (enteteFichierTexte[type_] == motLu){
                                while(true){
                                        string nom;
                                        double prix,coutResto;
                                        fichierPlats >> nom >> prix >> coutResto;
                    
                                        if(nom == "-MIDI" || nom == "-SOIR" || nom == "-TABLES")
                                                return true;
                                        // Lorsqu'on appelle une méthode de la classe dans une autre méthode, elle agit sur l'objet courant. C'est comme faire : this->ajouterPlat(...)
                                        ajouterPlat(nom, prix, coutResto);
                                }          
                        }
            
                }
                return false;
        }
}
// Me, its fine 
void Menu::afficher() const{
        const string moment[3] = {"Matin : ", "Midi :", "Soir :"};
        cout << moment[type_] << endl;
        for(unsigned int i=0; i<nbPlats_ ; i++){
                
                listePlats_[i]->afficher();
        }
               
}
