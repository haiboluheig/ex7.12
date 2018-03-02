

#ifndef NEWCLASS_H
#define NEWCLASS_H
#include<vector>
#include<iostream>

enum class HOBBIE {
    sport = 1, musique = 2, cinema = 3, lecture = 4
};

class Adress {
public:
    Adress(const std::string& nomRue = "", unsigned nmRue = 0, unsigned postal = 0, const std::string& localite = "");
    void setNomRue(const std::string& nomRue);
    void setNmRue(unsigned nmRue);
    void setPostal(unsigned postal);
    void setLocalite(const std::string localite);
    std::string toString() const;
    std::string getNomRue()const;
    std::string getLocalite()const;
    unsigned getNmRue()const;
    unsigned getPostal()const;
private:
    std::string nomRue;
    unsigned nmRue;
    unsigned postal;
    std::string localite;
};

class Personne {
   friend std::ostream& operator<<(std::ostream& os,const Personne& personne);
public:
    //constructeur
    Personne(const std::string& nom = "", const std::string& prenom = "");
    //setteur
    void setAdress(const std::string& nomRue, unsigned nmRue, unsigned postal, const std::string& localite);
    void ajouterHobbie(const HOBBIE& hobbie);
    void ajouterAmi(Personne& personne);
    std::string getNom() const;
    std::string getPrenom()const ;
    std::string getAdress()const ;
    std::string getHobbies()const;
    std::string getAmis()const;
    
private:
    std::string nom, prenom;
    Adress adress;
    std::vector<HOBBIE> hobbie;
    std::vector<Personne> ami;
};

#endif /* NEWCLASS_H */

