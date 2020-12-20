//Khang Nguyen 300007277
#include "Organization.h"

// à vous de le compléter

Organization::~Organization()
{
    std::cout << name << "(" << getNumberOfMembers() << ") detruit\n";
}

void Organization::addMember(std::shared_ptr<Person> p){
    members.push_back(p);
}

void Organization::removeMember(std::string name){
    std::vector<std::shared_ptr<Person>>::iterator it = std::find_if(members.begin(), members.end(), 
    [&name] (const std::shared_ptr<Person>& p) { 
        if(name == p -> getName()){
            return true;
        }else{
            return false;
        }
    }
    );
    
    if(it != members.end()){
        members.erase(it);
    }
}

void inscription(std::shared_ptr<Organization> o, std::shared_ptr<Person> p ){
    o->addMember(p);
    p->addOrganization(o);
}