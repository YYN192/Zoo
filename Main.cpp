#include <iostream>
#include <fstream>
#include <string>
#include "Animal.h"
#include "ZooUtils.h"

int main() {
    displayArt();
    Animal newAnimal;
    char repeat = 'y';


    while (repeat == 'y' || repeat == 'Y') {
        inputAnimalDetails(newAnimal);
        displayAnimalDetails(newAnimal);
        saveAnimalToFile(newAnimal, "animal_records.txt");
        countAnimalsAndSave("animal_records.txt");

        std::cout << "\nAdd another animal? (y/n): ";
        std::cin >> repeat;
        std::cin.ignore(); // Ignore the newline left in input buffer
    }

    return 0;

}