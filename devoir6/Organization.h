//Khang Nguyen 300007277
#ifndef OrganizationH
#define OrganizationH 
#include "PList.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Person;

class Organization {
    string name;
    PList<Person> members; 
    int dim;
    int size;

public:

    Organization(std::string n = "default");
    Organization(const Organization& registered);
    virtual ~Organization();
    void addMember(Person* Person);
    int getSize() const;
    int getDim() const;
    Person* getPersons(int i) const;
    bool removeMember(Person* Person);
    string getName();



};

#endif 