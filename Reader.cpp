#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Structure to hold the summary data for the animal records
struct AnimalSummary {
    int totalAnimals = 0; // Total number of animals processed
    int endangeredCount = 0; // Number of endangered animals
    double totalWeight = 0.0; // Total weight of all animals
    std::vector<int> habitatCount; // Count of animals for each habitat
    std::vector<std::string> habitats; // Names of habitats
    std::vector<int> dietCount; // Count of animals for each diet type
    std::vector<std::string> diets; // Types of diets
};

// Helper function to find the index of a string in a vector
// @param vec: Vector of strings to search in
// @param value: The string value to search for
// @return: Index of the value if found, otherwise -1
int findIndex(const std::vector<std::string>& vec, const std::string& value) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) return i; // Return the index if found
    }
    return -1; // Return -1 if not found
}

// Function to read animal details from the file and generate the summary
// @param filename: The name of the file containing animal records
// @return: AnimalSummary structure containing summary of the records
AnimalSummary analyzeAnimalRecords(const std::string& filename) {
    std::ifstream file(filename); // Open the file for reading
    if (!file.is_open()) { // Check if the file was opened successfully
        std::cerr << "Unable to open file for reading." << std::endl;
        return {}; // Return an empty AnimalSummary structure
    }

    AnimalSummary summary; // Structure to hold the summary data
    std::string line; // Variable to read each line from the file
    std::string species, habitat, diet; // Variables for different attributes
    double weight = 0.0; // Weight of the current animal
    bool endangered = false; // Endangered status of the current animal

    // Read the file line by line
    while (std::getline(file, line)) {
        // Check if the line starts with "Species: " indicating a new animal record
        if (line.rfind("Species: ", 0) == 0) {
            summary.totalAnimals++; // Increment total number of animals
        }
        // Check if the line starts with "Weight: " indicating the animal's weight
        else if (line.rfind("Weight: ", 0) == 0) {
            size_t kgPos = line.find(" kg"); // Find the position of " kg" in the line
            // Extract and convert the weight from string to double
            weight = std::stod(line.substr(8, kgPos - 8));
            summary.totalWeight += weight; // Add the weight to the total weight
        }
        // Check if the line starts with "Habitat: " indicating the habitat type
        else if (line.rfind("Habitat: ", 0) == 0) {
            habitat = line.substr(9); // Extract the habitat type from the line

            // Find the index of the habitat in the habitats list
            int idx = findIndex(summary.habitats, habitat);
            if (idx == -1) { // If the habitat is not found in the list
                summary.habitats.push_back(habitat); // Add new habitat to the list
                summary.habitatCount.push_back(1); // Initialize its count to 1
            }
            else { // If the habitat is already in the list
                summary.habitatCount[idx]++; // Increment the count of this habitat
            }
        }
        // Check if the line starts with "Diet: " indicating the diet type
        else if (line.rfind("Diet: ", 0) == 0) {
            diet = line.substr(6); // Extract the diet type from the line

            // Find the index of the diet in the diets list
            int idx = findIndex(summary.diets, diet);
            if (idx == -1) { // If the diet is not found in the list
                summary.diets.push_back(diet); // Add new diet to the list
                summary.dietCount.push_back(1); // Initialize its count to 1
            }
            else { // If the diet is already in the list
                summary.dietCount[idx]++; // Increment the count of this diet
            }
        }
        // Check if the line starts with "Endangered: " indicating endangered status
        else if (line.rfind("Endangered: ", 0) == 0) {
            std::string endangeredStr = line.substr(12); // Extract the status
            if (endangeredStr == "Yes") { // If the animal is endangered
                summary.endangeredCount++; // Increment endangered animal count
            }
        }
    }

    file.close(); // Close the file after reading
    return summary; // Return the summary structure
}

// Function to display the analysis summary
// @param summary: The AnimalSummary structure containing data to be displayed
void displaySummary(const AnimalSummary& summary) {
    std::cout << "\nAnimal Records Summary:\n";
    std::cout << "Total Number of Animals: " << summary.totalAnimals << "\n";
    std::cout << "Total Weight of All Animals: " << summary.totalWeight << " kg\n";

    // Calculate and display average weight if there are animals in the record
    if (summary.totalAnimals > 0) {
        double averageWeight = summary.totalWeight / summary.totalAnimals;
        std::cout << "Average Weight: " << averageWeight << " kg\n";
    }

    // Display the number of endangered animals
    std::cout << "Number of Endangered Animals: " << summary.endangeredCount << "\n";

    // Display the habitat summary
    std::cout << "\nHabitat Summary:\n";
    for (size_t i = 0; i < summary.habitats.size(); ++i) {
        std::cout << summary.habitats[i] << ": " << summary.habitatCount[i] << " animals\n";
    }

    // Display the diet summary
    std::cout << "\nDiet Summary:\n";
    for (size_t i = 0; i < summary.diets.size(); ++i) {
        std::cout << summary.diets[i] << ": " << summary.dietCount[i] << " animals\n";
    }
}

int main() {
    const std::string filename = "animal_records.txt"; // File name containing animal records
    // Analyze the records and generate a summary
    AnimalSummary summary = analyzeAnimalRecords(filename);
    // Display the summary of the analysis
    displaySummary(summary);
    return 0;
}
