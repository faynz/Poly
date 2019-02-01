//
//  Table.cpp
//  Tp1
//
//  Created by Yanis Toubal on 2019-01-31.
//  Copyright © 2019 Yanis Toubal. All rights reserved.
//

#include "Table.h"

Table::Table() {
    capacite_ = MAXCAP;
    id_ = -1;
    nbPlats_ = 1;
    occupee_ = false;
    commande_ = new Plat*[capacite_];
    
}

Table::Table(int id, int nbPlaces){
    id_ = id;
    nbPlats_ = nbPlaces;
    capacite_ = MAXCAP;
    occupee_ = false;
    commande_ = new Plat*[capacite_];
    
}

int Table::getId(){
    return id_;
}

int Table::getNbPlaces(){
    return nbPlats_;
}

bool Table::estOccupee(){
    return occupee_;
    
}

void Table::libererTable(){
    occupee_ = true;
    delete [] commande_;
    
}

void Table::placerClient(){
    occupee_ = true;
    
}

void Table::setId(int id){
    id_ = id;
    
}

void Table::commander(Plat* plat){
    
    if( capacite_ == 0)
        capacite_= MAXPLAT;
    
    if (capacite_ == nbPlats_ ){
        capacite_ *= 2;
        Plat** nouveauTableau = new Plat* [capacite_];
        
        for (unsigned i=0; i < nbPlats_; i++) {
            nouveauTableau[i] = commande_[i];
            
        }
        delete [] commande_;
        commande_= nouveauTableau;
        commande_[nbPlats_++] = plat;
        
    } else {
        commande_[nbPlats_++] = plat;
    }
}

double Table::getChiffreAffaire(){
    double chiffreAffaire = 0.0;
    
    for (unsigned i=0; i< nbPlats_; i++){
        chiffreAffaire += (commande_[i]->getPrix() - commande_[i]->getCout());
    }
    return chiffreAffaire;
}

void Table::afficher(){ //à revoir!!!
    cout << "Voici les tables ";
    cout << "La table numéro" << id_;
    
}
