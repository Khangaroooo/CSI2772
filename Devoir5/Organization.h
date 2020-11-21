#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include "Person.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//entrer d�claration de classe

/*
Class Organization: classe organization du devoir 4

- certaines modifications des types de valeurs n�cessaires

*/

class Organization {

    std::string name; // name of the org
    Person* members; // list of members
    int size;  // actual size of the org
    int dim;  // max size of the org


public:

    Organization(std::string n = "default") : name(n), size(0), dim(100)
    {
        members = new Person[dim];
    };


    Organization(const Organization& organization) : name(organization.name), size(organization.size), dim(organization.dim)
    {
        members = new Person[dim];
        for (int i = 0; i < size; i++) {

            members[i] = organization.members[i];
        }

    }

    virtual ~Organization()
    {
        delete[] members;
    }

    // return the name of all members entolled in the organization
    // all members written in onre string separated by semi-colons
    // returns empty string if no member is enrolled in the organization
    std::string getMemberNames()
	{
	    std::string name ="";
	    for (int i = 0; i<size;i++)
	    {
	        name = name + members[i].getName()+ ":"+ std::to_string(members[i].getAge()) + "; ";
	    }
	    return name;
    }
    
    std::string getName() {
        return name;
    }

    // adds a Person to the members array of the organization
    // Should double the members array size if array is full
    void addPerson(Person person)
    {
        if( size>= dim)
        {
            Person *tmp= new Person[dim*2];
            for (int i=0; i<size; i++)
            {
                tmp[i]= members[i];
            }
            delete[] members;
            members=tmp;
            dim*= 2;
        }

        members[size++] = person;
    }
};

class OrganizationPayante : public Organization {
    float _pay;
    public:
        using Organization::Organization;
    
        void setFrais(int amount) {
            _pay = amount;
        }
        
        float getFrais() const {
            return _pay;
        }
        
};

#endif
