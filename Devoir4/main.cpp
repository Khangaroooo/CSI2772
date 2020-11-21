//Khang Nguyen 3007277

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


// define your classes here
class Person {
    private:
        std::string _name;
        int _age;
    
    public:
        Person() {}
    
        Person(std::string name, int age) : _name(name), _age(age) {}
    
        int getAge() const {
            return _age;
        }
        
        std::string getName() const {
          return _name;
        }
};

class Organization {
    private:
        std::string _name = "default";
        Person* _members;
        int _size = 0;
        int _dim = 100;
        
        void doubleMembers() {
            _dim = _dim * 2;
            Person* resized = new Person[_dim];
            for (int i = 0; i < _dim/2; i++) {
                resized[i] = _members[i];
            }
            delete [] _members;
            _members = resized;
        }
    
    public:
        Organization() {
            _members = new Person[_dim];
        }
        
        Organization(const Organization &organization) {
            _size =  organization.getSize();
            _dim = organization.getDim();
            _members = new Person[_size];
            for (int i = 0; i < _size; i++) {
                _members[i] = organization.getMember(i);
            }
        }
        
        ~Organization() {
            delete [] _members;
        }
        
        Person getMember (int i) const {
            return _members[i];
        }
        
        int getSize() const {
            return _size;
        }
        
        int getDim() const {
            return _dim;
        }
        
        std::string getMemberNames() const {
            std::string names = "";
            for(int i = 0; i < _size; i++){
                names.append(_members[i].getName());
                names.append("; ");
            }
            return names;
        }
    
        void addPerson(Person tmpPerson) {
            if(_size == _dim) {
                doubleMembers();
            }
            _members[_size] = tmpPerson;
            _size++;
        }
        
};

// prints all members of an organization to std::cout
void printMembers( Organization organization) {
    std::cout << organization.getMemberNames();
}


int main() {
    Person p; //create a Person instance
    Organization org; //create an Organization instance
    
    org.addPerson(p); // add p to org
    cout<< "org contient: "<<endl;
    printMembers(org);
    
    //here we will add 250 persons to org
    for (int i =0 ; i<250; i++)
    {
        Person person("Person"+std::to_string(i), rand()% 30 +16); // create  a Person instance with the name "Person+i" and a random age
        org.addPerson(person);
    }
    cout<<endl<< "org contient: "<<endl;
    printMembers(org);
    
    Organization org1 = org;
    cout<<endl<< "org1 contient: "<<endl;
    printMembers(org1);

    return 0;
}













