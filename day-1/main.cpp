#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    // Open the file
    std::ifstream file("input.txt");

    // A vector to store int for each block
    std::vector<int> elfCalories(1, 0);

    // Check if the file is open
    if (file.is_open()) {
        // Read the file line by line
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) {
                elfCalories.push_back(0);
            }
            else {
                // Convert the string to int
                int calories = std::stoi(line);
                // Add the int to the last element in the vector
                elfCalories.back() += calories;
            }
        }
    }

    // Close the file
    file.close();

    // Print the size of elfCalories
    std::cout << "Total number of elves: " << elfCalories.size() << std::endl;

    // Print the largest value in elfCalories, store in a variable
    int maxCalories = *std::max_element(elfCalories.begin(), elfCalories.end());
    std::cout << "Max calories: " << maxCalories << std::endl;

    // Sort the vector
    std::sort(elfCalories.begin(), elfCalories.end());

    // Print the second largest value in elfCalories, store in a variable
    int secondLargest = elfCalories[elfCalories.size() - 2];
    std::cout << "Second largest elf is carrying: " << secondLargest << std::endl;

    // Print the third largest value in elfCalories, store in a variable
    int thirdLargest = elfCalories[elfCalories.size() - 3];
    std::cout << "Third largest elf is carrying: " << thirdLargest << std::endl;

    // Total of the top three elves
    int total = maxCalories + secondLargest + thirdLargest;
    std::cout << "Total of the top three elves: " << total << std::endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
