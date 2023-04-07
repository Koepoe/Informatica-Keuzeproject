#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

// Als het woord 2 letters heeft, return true anders false
bool hasTwoLetters(std::string letterInput) {
    for (int i = 0; i < letterInput.length(); i++) {
        if (std::count(letterInput.begin(), letterInput.end(), letterInput.at(i)) == 2) {
            return true;
        }
    }
    return false;
}

// Als het woord 3 letters heeft, return true anders false
bool hasThreeLetters(std::string letterInput) {
    for (int i = 0; i < letterInput.length(); i++) {
        if (std::count(letterInput.begin(), letterInput.end(), letterInput.at(i)) == 3) {
            return true;
        }
    }
    return false;
}

int main() {
    std::fstream inputFile;
    inputFile.open("Day2_Input.txt");
    std::string stringOfLetters;
    std::vector <std::string> inputStrings;
    int countTwoLetters;
    int countThreeLetters;
    while (inputFile >> stringOfLetters) {
        inputStrings.push_back(stringOfLetters);
    }
    // Loop over alle woorden en kijk of ze 2 en/of 3 dezelfde letters hebben
    for (int i = 0; i < inputStrings.size(); i++) {
        if (hasTwoLetters(inputStrings.at(i))) {
            countTwoLetters++;
        }
        if (hasThreeLetters(inputStrings.at(i))) {
            countThreeLetters++;
        }
    }
    std::cout << countTwoLetters * countThreeLetters;
}