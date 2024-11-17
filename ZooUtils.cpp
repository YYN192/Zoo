// ZooUtils.cpp
#include <iostream>
#include <fstream>
#include "ZooUtils.h"

// Function to input animal details
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
    std::cout << "Endangered: " << (animal.isEndangered() ? "Yes" : "No") << std::endl;
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

// Function to display ASCII art
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
