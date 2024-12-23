#include <iostream>
#include <fstream>
#include <string>
#include "Animal.h"

// NoArgs constructor
Animal::Animal() : species("NULL"), weight(0), habitat("NULL"), diet("NULL"), endangered(true) {}

// Parameterized constructor
Animal::Animal(const std::string& newspecies, double newWeight, const std::string& newHabitat,
    const std::string& newDiet, bool newEndangered) {
    setSpecies(newspecies);
    setWeight(newWeight);
    setHabitat(newHabitat);
    setDiet(newDiet);
    setEndangered(newEndangered);
}

// Getters
std::string Animal::getSpecies() const { return species; }
double Animal::getWeight() const { return weight; }
std::string Animal::getHabitat() const { return habitat; }
std::string Animal::getDiet() const { return diet; }
bool Animal::isEndangered() const { return endangered; }

// Setters with validation
void Animal::setSpecies(const std::string& newSpecies) {
    if (!newSpecies.empty()) {
        species = newSpecies;
    }
    else {
        std::cerr << "Species cannot be empty.\n";
    }
}

void Animal::setWeight(double newWeight) {
    if (newWeight > 0) {
        weight = newWeight;
    }
    else {
        std::cerr << "Weight must be positive.\n";
    }
}

void Animal::setHabitat(const std::string& newHabitat) {
    if (!newHabitat.empty()) {
        habitat = newHabitat;
    }
    else {
        std::cerr << "Habitat cannot be empty.\n";
    }
}

void Animal::setDiet(const std::string& newDiet) {
    if (!newDiet.empty()) {
        diet = newDiet;
    }
    else {
        std::cerr << "Diet cannot be empty.\n";
    }
}

void Animal::setEndangered(bool newEndangered) {
    endangered = newEndangered;
}

// Function to input animal details from the user
void inputAnimalDetails(Animal& animal) {
    std::cout << "Enter Species: ";
    std::string newspecies;
    std::getline(std::cin, newspecies);

    std::cout << "Enter Weight (in kg): ";
    double newWeight;
    std::cin >> newWeight;
    std::cin.ignore(); // Ignore the newline left in input buffer

    std::cout << "Enter Habitat: ";
    std::string newHabitat;
    std::getline(std::cin, newHabitat);

    std::cout << "Enter Diet: ";
    std::string newDiet;
    std::getline(std::cin, newDiet);

    // Input for endangered status
    char endangeredInput;
    std::cout << "Is this animal endangered? (y/n): ";
    std::cin >> endangeredInput;
    bool newEndangered = (endangeredInput == 'y' || endangeredInput == 'Y');
    std::cin.ignore(); // Ignore the newline left in input buffer

    animal = Animal(newspecies, newWeight, newHabitat, newDiet, newEndangered);
}

// Function to display animal details
void displayAnimalDetails(const Animal& animal) {
    std::cout << "\nAnimal Details:\n";
    std::cout << "Species: " << animal.getSpecies() << std::endl;
    std::cout << "Weight: " << animal.getWeight() << " kg" << std::endl;
    std::cout << "Habitat: " << animal.getHabitat() << std::endl;
    std::cout << "Diet: " << animal.getDiet() << std::endl;
    std::cout << "Endangered: " << (animal.isEndangered() ? "Yes" : "No") << std::endl; // Display endangered status
}

// Function to save animal details to a file
void saveAnimalToFile(const Animal& animal, const std::string& filename) {
    std::ofstream file(filename, std::ios_base::app); // Open in append mode
    if (file.is_open()) {
        file << "Species: " << animal.getSpecies() << std::endl;
        file << "Weight: " << animal.getWeight() << " kg" << std::endl;
        file << "Habitat: " << animal.getHabitat() << std::endl;
        file << "Diet: " << animal.getDiet() << std::endl;
        file << "Endangered: " << (animal.isEndangered() ? "Yes" : "No") << std::endl;
        file << "\n";
        file.close();
        std::cout << "Details saved to " << filename << std::endl;
    }
    else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

// Function to count animals and save the count to a file
void countAnimalsAndSave(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file for reading." << std::endl;
        return;
    }

    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            count++;
        }
    }
    file.close();

    std::ofstream countFile("number_of_animals.txt");
    if (countFile.is_open()) {
        countFile << "Number of animals: " << count << std::endl;
        countFile.close();
        std::cout << "Animal count saved to number_of_animals.txt" << std::endl;
    }
    else {
        std::cerr << "Unable to open number_of_animals.txt for writing." << std::endl;
    }
}

// Display ASCII art
void displayArt() {
    std::cout <<
        " _______  _______  _______  _        _______  _______  _________           \n"
        "/ ___   )(  ___  )(  ___  )( \\      (  ___  )(  ____ \\ \\__   __/|\\    /| \n"
        "\\/   )  || (   ) || (   ) || (      | (   ) || (    \\/   ) (   ( \\   / ) \n"
        "    /   )| |   | || |   | || |      | |   | || |         | |    \\ (_) /  \n"
        "   /   / | |   | || |   | || |      | |   | || | ____    | |     ) _ (   \n"
        "  /   /  | |   | || |   | || |      | |   | || | \\_  )   | |    / ( ) \\  \n"
        " /   (_/\\| (___) || (___) || (____/\\| (___) || (___) |___) (___( /   \\ ) \n"
        "(_______/(_______)(_______)(_______/(_______)(_______)\\_______/|/     \\| \n";
}

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
