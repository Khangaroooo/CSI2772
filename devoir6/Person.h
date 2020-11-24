//Khang Nguyen 300007277
#ifndef Person_H_
#define Person_H_
#include "Organization.h"


class Person {

    std::string name;   
    int age;            
    PList<Organization> organizations; 
    int dim;
    int size;

public:

    Person(std::string n = "default", int a = rand() % 30 + 16);
    Person(const Person& registered);
    ~Person();
    string getOrgNames();
    void addOrganization(Organization* organization);
    int getSize() const;
    Organization* getOrg(int i) const;
    int getage();
    std::string getName();
    int getDim() const;
    float getAPayer();
    string printAPayer();
    bool removeOrganization(Organization* organization);
};


#endif 