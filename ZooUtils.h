#pragma once
#include <string>
#include "Animal.h"

// Function to input animal details from the user
void inputAnimalDetails(Animal& animal);

// Function to display animal details
void displayAnimalDetails(const Animal& animal);

// Function to save animal details to a file
void saveAnimalToFile(const Animal& animal, const std::string& filename);

// Function to count animals in the file and save the count to a file
void countAnimalsAndSave(const std::string& filename);

// Function to display ASCII art
void displayArt();
