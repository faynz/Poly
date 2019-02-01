//
//  Restaurant.cpp
//  Tp1
//
//  Created by Yanis Toubal on 2019-01-25.
//  Copyright © 2019 Yanis Toubal. All rights reserved.
//

#include "Restaurant.h"


Restaurant::Restaurant(){
    nom_ = nullptr;
    chiffreAffaire_ = 0.0;
    momentJournee_ = Matin;
    menuMatin_ = nullptr;
    menuMidi_ = nullptr;
    menuSoir_ = nullptr;
    capaciteTables_ = INTTABLES;
    tables_ = new Table*[capaciteTables_];
    nbTables_ = 0;
    
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
    nom_ = nullptr;
    chiffreAffaire_ = 0.0;
    momentJournee_ = moment;
    menuMatin_ = new Menu(fichier, Matin);
    menuMidi_ = new Menu(fichier, Midi);
    menuSoir_ = new Menu(fichier, Soir);
    capaciteTables_ = INTTABLES;
    tables_ = new Table*[capaciteTables_];
    nbTables_ = 0;
    
}

string Restaurant::getNom(){
    return *nom_;
    
}

TypeMenu Restaurant::getMoment(){
    return momentJournee_;
    
}

void Restaurant::setMoment(TypeMenu moment){
    momentJournee_ = moment;
    
}

void Restaurant::lireTable(string& fichier){
    ifstream fichierLu(fichier);
    
    string motLu;
    while(!ws(fichierLu).eof()){
        
        fichierLu >> motLu;
        if(motLu == "-TABLE"){
            while(!ws(fichierLu).eof()){
                int id, nbPlaces;
                cin >> id >> nbPlaces;
                ajouterTable(id, nbPlaces);
            
            }
        }
    }
    
}

void Restaurant::ajouterTable(int id, int nbPlaces){
        tables_[nbTables_] = new Table(id, nbPlaces);
    }
    

