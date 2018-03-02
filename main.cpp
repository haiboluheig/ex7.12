/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lvhb_
 *
 * Created on March 1, 2018, 5:39 PM
 */

#include <cstdlib>
#include<iostream>
#include "newClass.h"

using namespace std;

int main() {

    const string SEPARER = "*****************************************";
    cout << SEPARER<< endl;
    //Inisialisation
    Personne p1("Lu", "Haibo"), p2("Li", "li"), p3("Wang", "Xiaoyan");
    //Set adress
    p1.setAdress("Chemin de la vallombreuse", 10, 1004, "Lausanne");
    p2.setAdress("Avenue de france", 100, 1000, "Geneve");
    p3.setAdress("Avenue Pudong", 320, 304122, "Peiking");
    //ajouter amis
    p1.ajouterAmi(p2); // automatique  p2.ajouterAmi(p1);
    p2.ajouterAmi(p3); // automatique  p3.ajouterAmi(p2);
    p3.ajouterAmi(p1); // automatique  p1.ajouterAmi(p3);
    //ajouter hobbies
    p1.ajouterHobbie(HOBBIE::cinema);
    p1.ajouterHobbie(HOBBIE::lecture);
    p2.ajouterHobbie(HOBBIE::musique);
    p2.ajouterHobbie(HOBBIE::sport);
    p3.ajouterHobbie(HOBBIE::sport);
    p3.ajouterHobbie(HOBBIE::lecture);

    cout << p1;

    cout << SEPARER<< endl;
    cout << p2;
    
    cout << SEPARER<< endl;
    cout << p3;
   

    cout << SEPARER<< endl;

    return EXIT_SUCCESS;
}

