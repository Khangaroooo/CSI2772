//Khang Nguyen 300007277
#include "Person.h"

// à vous de le compléter

Person::~Person()
{
    std::cout << name << " (" << age << ") detruit\n";
}

void Person::addOrganization(std::shared_ptr<Organization> o){
    organizations.push_back(o);
}

void Person::removeOrganization(std::string oName){
    
    
    std::vector<std::weak_ptr<Organization>>::iterator it = std::find_if(organizations.begin(), organizations.end(), 
    [&oName] (const std::weak_ptr<Organization>& o) { 
        std::shared_ptr<Organization> org = o.lock();
        if(oName == org -> getName()){
            return true;
        }else{
            return false;
        }
    }
    );
    
    if(it != organizations.end()){
        std::shared_ptr<Organization> org = it -> lock();
        org -> removeMember(getName());
        organizations.erase(it);
    }
}

std::string Person::getOrganizationNames() const {
    std::string orgs = " ";
    orgs.append(std::to_string(getNumberofOrganizations())).append("[");
    for(auto o : organizations){
        if(!o.expired()){
            std::shared_ptr<Organization> org = o.lock();
            orgs.append(org -> getName());
            orgs.append(" ");
        }
    }
    orgs.append("]");
    return orgs;
}

int Person::getNumberofOrganizations() const {
    int numOrg = 0;
    for(auto o : organizations){
        if(!o.expired()){
            numOrg++;
        }
    }
    return numOrg;
}

std::ostream& operator<<(std::ostream& os, const Person& p){
    os << p.getName() << p.getOrganizationNames();
    
    return os;
}