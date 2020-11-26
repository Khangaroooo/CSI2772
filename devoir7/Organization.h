//Khang Nguyen 300007277
#ifndef OrganizationH
#define OrganizationH 

#include <map>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Person;

class Organization {
    string name;
    std::multimap<std::string, Person*> members;
    int dim;
    int size;

public:

    Organization(std::string n = "default");
    virtual ~Organization();
    void addMember(Person* members);
    void removePerson(Person* members);
    string getMemberNames();
    string getName();
    int getSize() const;


};

#endif 