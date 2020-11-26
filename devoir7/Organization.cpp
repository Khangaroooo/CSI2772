//Khang Nguyen 300007277

#include "Person.h"


Organization::Organization(std::string n) {
    name = n;
    size = 0;
    dim = 100;
};


Organization::~Organization()
{
    for (auto it=members.begin(); it!=members.end(); ++it){
        delete it -> second;
        members.erase(it);
    }
}

void Organization::addMember(Person* Person)
{
    if (members.size() == dim) {
        throw std::out_of_range(getName() + " has already 100 members");
    }

    else {
        members.insert(std::make_pair(Person -> getName(), Person));
    }

}

void Organization::removePerson(Person* person)
{
    auto it = members.find(person -> getName());
    if(it != members.end()) {
        members.erase(it -> second -> getName());
    }else{
        std::cout << name << " has no member " << person -> getName() << std::endl;
    }

}

string Organization::getMemberNames()
{
    std::string name = "";

    for (auto it=members.begin(); it!=members.end(); ++it){
        name = name + it -> second -> getName() + ", ";
    }

    return name;
}


int Organization::getSize() const {
    return members.size();
}


string Organization::getName() { return name; }



