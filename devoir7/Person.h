//Khang Nguyen 300007277
#ifndef Person_H_
#define Person_H_
#include <map>
#include "Organization.h"


class Person {

    std::string name;
    int age;
    std::map<std::string, Organization*> organizations;

public:

    Person(std::string n = "default", int a = rand() % 30 + 16);
    ~Person();
    void addOrganization(Organization* organization);
    void removeOrganization(Organization* organization);
    float getAPayer();
    string printAPayer();
    string getOrgNames();
    int getSize() const;
    std::string getName();
};


#endif 