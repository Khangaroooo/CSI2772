#include <iostream>
#include <string>
#include <stdlib.h>
#include "Person.h"
#include "Organization.h"
using namespace std;

//ajouter d�pendances n�cessaires 

/**
Classe Person: Fichier a modifi�
Cr�er une instance de Person, utilis� pour ajouter des organisations � une personne
Variable priv�: name, age and others to define

Ajouter toutes les m�thodes manquantes
*/

    Person::Person(std::string n, int a)  {
        _name = n;
        _age = a;
    };
    //ajouter les classes du constructeur manquantes  


    // Ajouter une organisation a une personne 
    // Exception lanc�e si size > 5
    void Person::addOrganization(Organization* organization) {
        if (_size < 5) {
            _orgs[_size++] = organization;
        } else {
            throw std::out_of_range("more than 5 orgs");
        }
    }

    //retourne une valeur total de toutes les frais annuels des organisations qui sont payantes en faisant un downcasting 
    float Person::getAPayer() {
        float tmp = 0;
	    for (int i = 0; i<_size;i++)
	    {
	        OrganizationPayante *org = dynamic_cast<OrganizationPayante*>(_orgs[i]);
	        if(org) {
	            tmp = tmp + org -> getFrais();
	        }
	    }
	    return tmp;
    }

    //retourne un string de toutes les noms des organisations payantes en faisant un downcasting 
    string Person::printAPayer() {
        
        std::string name ="";
	    for (int i = 0; i<_size;i++)
	    {
	        OrganizationPayante *org = dynamic_cast<OrganizationPayante*>(_orgs[i]);
	        if(org)
	            name = name + org -> getName()+ " - " + std::to_string(static_cast<int>(org -> getFrais()))+ "; ";
	    }
	    return name;
    }

    //retourne un string contenant toutes les organisations de la personnne 
    string Person::getOrgNames() {
	    std::string name ="";
	    for (int i = 0; i<_size;i++)
	    {
	        name = name + _orgs[i] -> getName()+ "; ";
	    }
	    return name;
    }


    int Person::getAge() { return _age; }
    std::string Person::getName() { return _name; }
    int Person::getSize() { return _size; }

