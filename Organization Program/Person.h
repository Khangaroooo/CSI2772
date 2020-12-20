//Khang Nguyen 300007277
#ifndef Person_H_
#define Person_H_
#include "Organization.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>

// Vous pouvez ajouter autant de code que nécessaire
// Remplacer les ??? par le code manquant
// Le code déjà présent ne doit pas être modifié ou effacé

class Organization;

class Person {

    std::string name;
    int age;
    
    // un vecteur de pointeurs intelligents à des organisations
    std::vector<std::weak_ptr<Organization>> organizations;  

  public:

    Person(std::string n, int a) : name(n),age(a) {}
    ~Person();
    
    // ajouter une organisation
    void addOrganization(std::shared_ptr<Organization> organization);
    // retirer une organisation (en spécifiant son nom)
    void removeOrganization(std::string org);

    std::string getOrganizationNames() const;

    int getNumberofOrganizations() const;
    std::string getName() const {return name;}
    int getAge() const {return age;}

};

std::ostream& operator<<(std::ostream& os, const Person& p);

#endif 