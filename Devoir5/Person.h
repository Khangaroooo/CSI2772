#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Organization;

//ajouter d�pendances n�cessaires 

/**
Classe Person: Fichier a modifi�
Cr�er une instance de Person, utilis� pour ajouter des organisations � une personne
Variable priv�: name, age and others to define

Ajouter toutes les m�thodes manquantes
*/
class Person {

    string _name;
    int _age;
    int _size = 0;
    Organization* _orgs[5];

public:

    Person(std::string n = "default", int a = rand() % 30 + 16);
    // Ajouter une organisation a une personne 
    // Exception lanc�e si size > 5
    void addOrganization(Organization* organization);

    //retourne une valeur total de toutes les frais annuels des organisations qui sont payantes en faisant un downcasting 
    float getAPayer();

    //retourne un string de toutes les noms des organisations payantes en faisant un downcasting 
    string printAPayer();

    //retourne un string contenant toutes les organisations de la personnne 
    string getOrgNames();

    int getAge();
    std::string getName();
    int getSize();
};

#endif
