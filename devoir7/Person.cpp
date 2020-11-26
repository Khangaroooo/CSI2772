//Khang Nguyen 300007277

#include "Person.h"
#include "OrganizationPayante.h"


Person::Person(std::string n, int a) {
    name = n;
    age = a;
};

Person::~Person()
{
    for (auto it=organizations.begin(); it!=organizations.end(); ++it){
        delete it -> second;
        organizations.erase(it);
    }
}

void Person::addOrganization(Organization* organization)
{
    organizations[organization -> getName()] = organization;
}

void Person::removeOrganization(Organization* organization)
{
    auto it = organizations.find(organization -> getName());
    if(it != organizations.end()) {
        organizations.erase(it);
    }else{
        std::cout << name << " is not part of " << organization -> getName() << std::endl;
    }
}


std::string Person::getName() { return name; }


int Person::getSize() const {
    return organizations.size();
}


string Person::getOrgNames()
{
    std::string name = "";
    for (auto it=organizations.begin(); it!=organizations.end(); ++it)
    {
        name = name + it -> second -> getName() + ", ";
    }
    return name;
}

float Person::getAPayer() {
    float total = 0;
    for (auto it=organizations.begin(); it!=organizations.end(); ++it) {

        OrganizationPayante* op = dynamic_cast<OrganizationPayante*>(it -> second);

        if (op != nullptr) {
            total += op->getFrais();
        }
    }
    return total;
}

string Person::printAPayer() {
    string name = "";

    for (auto it=organizations.begin(); it!=organizations.end(); ++it) {

        OrganizationPayante* op = dynamic_cast<OrganizationPayante*>(it -> second);

        if (op != nullptr) {
            name = name + op->getName() + ": " + to_string(op->getFrais()) + "; ";

        }
    }
    return name;

}



