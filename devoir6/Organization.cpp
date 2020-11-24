//Khang Nguyen 300007277
#include "Person.h"


Organization::Organization(std::string n): members(100) {
    name = n;
    size = 0;
    dim = 100;
    //members(dim);
};

Organization::~Organization()
{
}

void Organization::addMember(Person* Person)
{
    members.add(Person);
}

bool Organization::removeMember(Person* Person)
{
    return members.remove(Person);
}

int Organization::getSize() const {
    return size;
}

int Organization::getDim() const {
    return dim;
}

Person* Organization::getPersons(int i) const {
    members.getItem(i);
}

string Organization::getName() { return name; }



