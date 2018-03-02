

#ifndef NEWCLASS_H
#define NEWCLASS_H
#include<vector>
#include<iostream>


enum class Hobby {
    SPORT = 1, MUSIQUE = 2, CINEMA = 3, LECTURE = 4
};

class Adress {
public:
    Adress(const std::string& nomRue = "", const std::string& nmRue = "", unsigned postal = 0, const std::string& localite = "");
    void setNomRue(const std::string& nomRue);
    void setNmRue(const std::string& nmRue);
    void setPostal(unsigned postal);
    void setLocalite(const std::string localite);
    std::string toString() const;
    std::string getNomRue()const;
    std::string getLocalite()const;
    std::string getNmRue()const;
    unsigned getPostal()const;
private:
    std::string nomRue;
    std::string nmRue;
    unsigned postal;
    std::string localite;
};

class Personne {
    friend std::ostream& operator<<(std::ostream& os, const Personne& personne);
public:
    //constructeur
    Personne(const std::string& nom, const std::string& prenom,
            const Adress& ad, const std::initializer_list<Hobby>& hb, const std::initializer_list<Personne*>& amis);
    Personne(const std::string& nom, const std::string& prenom,
           const Adress& ad, const std::initializer_list<Hobby>& hb);
    //setteur
    void setAdress(const std::string& nomRue, const std::string& nmRue, unsigned postal, const std::string& localite);
    void ajouterHobbie(const std::initializer_list<Hobby>& hb);
    void ajouterAmi(const std::initializer_list<Personne*>& amis);
    std::string getNom() const;
    std::string getPrenom()const;
    std::string getAdress()const;
    std::string getHobbies()const;
    std::string getAmis()const;

private:
    std::string nom, prenom;
    Adress adress;
    std::vector<Hobby> hobbie;
    std::vector<Personne*> ami;
};

#endif /* NEWCLASS_H */

