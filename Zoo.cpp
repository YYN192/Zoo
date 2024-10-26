#include <iostream>
#include <fstream>
#include <string>

// Structure to hold animal details
struct Animal {
private:
    std::string species;
    double weight; // in kg
    std::string habitat;
    std::string diet;
    bool endangered;

public:
    // NoArgs constructor
    Animal() {
        species = "NULL";
        weight = 0;
        habitat = "NULL";
        diet = "NULL";
        endangered = true;
    }

    // Parameterized constructor
    Animal(std::string newspecies, double newWeight, std::string newHabitat, std::string newdiet, bool newendangered) {
        species = newspecies;
        weight = newWeight;
        habitat = newHabitat;
        diet = newdiet;
        endangered = newendangered;
    }

    // Getters
    std::string getSpecies() const { return species; }
    double getWeight() const { return weight; }
    std::string getHabitat() const { return habitat; }
    std::string getDiet() const { return diet; }
    bool isEndangered() const { return endangered; }
};

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

        std::cout << "\nAdd another animal? (y/n): ";
        std::cin >> repeat;
        std::cin.ignore(); // Ignore the newline left in input buffer
    }

    return 0;
}
