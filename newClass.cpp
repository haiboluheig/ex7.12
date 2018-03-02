#include<string>
#include<cstdlib>
#include<iostream>
#include <vector>
#include<algorithm>

#include "newClass.h"
using namespace std;

Adress::Adress(const string& nomRue, unsigned nmRue, unsigned postal, const string& localite)
: nomRue(nomRue), nmRue(nmRue), postal(postal), localite(localite) {
}

void Adress::setNomRue(const string& nomRue) {
    this->nomRue = nomRue;
}

void Adress::setNmRue(unsigned nmRue) {
    this->nmRue = nmRue;
}

void Adress::setPostal(unsigned postal) {
    this->postal = postal;
}

void Adress::setLocalite(const string localite) {
    this->localite = localite;
}

string Adress::toString() const {
    if (nomRue.size() == 0) {
        return "";
    } else {
        string str = nomRue + ' ' + to_string(nmRue) + ','
                + to_string(postal) + ',' + localite;
        return str;
    }
}

string Adress::getNomRue()const {
    return nomRue;
}

string Adress::getLocalite()const {
    return localite;
}

unsigned Adress::getNmRue()const {
    return nmRue;
}

unsigned Adress::getPostal()const {
    return postal;
}


//personne class*******************************************
//constructeur

Personne::Personne(const string& nom, const string& prenom)
: nom(nom), prenom(prenom) {
}
//setteur

void Personne::setAdress(const string& nomRue, unsigned nmRue, unsigned postal, const string& localite) {
    this->adress = Adress(nomRue, nmRue, postal, localite);

}

void Personne::ajouterHobbie(const HOBBIE& hobbie) {

    this->hobbie.push_back(hobbie);
}

void Personne::ajouterAmi(Personne& personne) {
    bool find = 0;
    for (const Personne& p : ami) {
        if (p.nom == personne.nom && p.prenom == personne.prenom) {
            find = 1;
            return;
        }
    }
    if (!find&&!(personne.nom == this->nom && personne.prenom == this->prenom)) {
        this->ami.push_back(personne);
        personne.ami.push_back(*this);
    }
}

//getteur

string Personne::getNom() const {
    return nom;
}

string Personne::getPrenom() const {
    return prenom;
}

string Personne::getAdress() const {
    return adress.toString();
}

string Personne::getHobbies() const {
    string str;
    if (hobbie.size() == 0) {
        str = "Il n'y a aucune hobbie.\n";
    } else {
        for (const HOBBIE& h : hobbie) {
            switch ((int) h) {
                case 1:
                    str += "sport  ";
                    break;
                case 2:
                    str += "musique  ";
                    break;
                case 3:
                    str += "cinema  ";
                    break;
                case 4:
                    str += "lecture  ";
                    break;
                default:
                    break;
            }
        }
        return str;
    }
}

string Personne::getAmis()const {
    string str;
    if (ami.size() == 0) {
        str = "Il n'y a aucun d'ami.\n";
    } else {
        for (const Personne& p : ami)
            str += p.nom + '.' + p.prenom + "   ";
    }
    return str;
}

ostream& operator<<(ostream& os, const Personne& personne) {
    os << personne.getNom() << '.' << personne.getPrenom()
            << "\nAdress  : " << personne.getAdress()
            << "\nHobbies : " << personne.getHobbies()
            << "\nAmis    : " << personne.getAmis() << endl;
    return os;
}