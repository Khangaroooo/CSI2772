//Khang Nguyen 300007277
#include "Person.h"
#include "OrganizationPayante.h"


Person::Person(std::string n, int a): organizations(5) {
    name = n;
    age = a;
    dim = 5;
    size = 0;
};

Person::~Person()
{
}

void Person::addOrganization(Organization* organization)
{
    try{
    organizations.add(organization);
    }catch(std::out_of_range e){
        std::cout << "Error: Cannot add "<< name << " to " << organization -> getName() << " he is enrolled in 5 organisations already" << endl;
    }
}

bool Person::removeOrganization(Organization* organization)
{
    return organizations.remove(organization);
}


int Person::getage() { return age; }
std::string Person::getName() { return name; }


int Person::getSize() const {
    return organizations.getSize();
}

int Person::getDim() const {
    return dim;
}

Organization* Person::getOrg(int i) const {

    return organizations.getItem(i);
}

string Person::getOrgNames()
{
    std::string name = "";
    for (int i = 0; i < organizations.getSize(); i++)
    {
        name = name + organizations.getItem(i)->getName() + ", ";
    }
    return name;
}

float Person::getAPayer() {
    float total = 0;
    for (int i = 0; i < organizations.getSize(); i++) {

        OrganizationPayante* op = dynamic_cast<OrganizationPayante*>(organizations.getItem(i));

        if (op != nullptr) {
            total += op->getFrais();
        }
    }
    return total;
}

string Person::printAPayer() {
    string name = "";

    for (int i = 0; i < organizations.getSize(); i++) {

        OrganizationPayante* op = dynamic_cast<OrganizationPayante*>(organizations.getItem(i));

        if (op != nullptr) {
            name = name + op->getName() + ": " + to_string(op->getFrais()) + "; ";

        }
    }
    return name;

}



