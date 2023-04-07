#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

// Tel hoeveel letters er tussen de zinnen verschillen
int countDifferences(std::string input1, std::string input2) {
    int amountOfDifferences = 0;
    for (int i = 0; i < input1.length(); i++) {
        if (input1.at(i) != input2.at(i)) {
            amountOfDifferences++;
        }
    }
    return amountOfDifferences;
}
// Vind de zinnen die het minst van elkaar verschillen
std::vector <std::string> findCorrectBoxes(std::vector <std::string> inputStrings) {
    int lowestAmountOfDifferences;
    std::vector <std::string> correctBoxes;
    std::string correctBox1;
    std::string correctBox2;
    for (int i = 0; i < inputStrings.size(); i++) {
        for (int j = i + 1; j < inputStrings.size(); j++) {
            if (countDifferences(inputStrings.at(i), inputStrings.at(j)) < lowestAmountOfDifferences) {
                correctBox1 = inputStrings.at(i);
                correctBox2 = inputStrings.at(j);
                lowestAmountOfDifferences = countDifferences(inputStrings.at(i), inputStrings.at(j));
            }
        }
    }
    correctBoxes.push_back(correctBox1);
    correctBoxes.push_back(correctBox2);
    return correctBoxes;
} 

int main() {
    std::fstream inputFile;
    inputFile.open("Day2_Input.txt");
    std::string stringOfLetters;
    std::vector <std::string> inputStrings;
    std::vector <std::string> matchingBoxes;
    std::string commonLetters;
    while (inputFile >> stringOfLetters) {
        inputStrings.push_back(stringOfLetters);
    }
    matchingBoxes = findCorrectBoxes(inputStrings);
    // Maak een zin met alle overeenkomende letters tussen de 2 correcte zinnen
    for (int i = 0; i < matchingBoxes.at(0).size(); i++) {
        if (matchingBoxes.at(0).at(i) == matchingBoxes.at(1).at(i)) {
            commonLetters += matchingBoxes.at(0).at(i);
        } 
    } 
    std::cout << commonLetters;
}