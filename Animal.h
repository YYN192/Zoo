#pragma once
#include <string>
#include <iostream>

// Structure to hold animal details
class Animal {
private:
    std::string species;
    double weight; // in kg
    std::string habitat;
    std::string diet;
    bool endangered;

public:
    // NoArgs constructor
    Animal();

    // Parameterized constructor
    Animal(const std::string& newspecies, double newWeight, const std::string& newHabitat,
        const std::string& newDiet, bool newEndangered);

    // Getters
    std::string getSpecies() const;
    double getWeight() const;
    std::string getHabitat() const;
    std::string getDiet() const;
    bool isEndangered() const;

    // Setters with validation
    void setSpecies(const std::string& newSpecies);
    void setWeight(double newWeight);
    void setHabitat(const std::string& newHabitat);
    void setDiet(const std::string& newDiet);
    void setEndangered(bool newEndangered);
};

