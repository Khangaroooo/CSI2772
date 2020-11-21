#include <stdio.h>
#include <fstream>
#include <iostream>

int main() {
    
    std::string fileName;
    std::cout << "Entrer le nom du fichier: ";
    std::cin >> fileName;
    std::ifstream myfile(fileName);
    
    int totalGirls(0);
    std::string name;
    char gender;
    int age;
    
    while(myfile >> name >> gender >> age) {
        if(gender == 'f' && age > 25) {
            std::cout << name << " - " << age << " ans\n";
            totalGirls++;
        }
    }
    std::cout << "\nIl y a " << totalGirls << " filles avec plus de 25 ans.";

    return 0;
}


