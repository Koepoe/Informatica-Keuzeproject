#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector <std::vector <char>> clothOfFabric (1000, std::vector<char> (1000, '.'));
std::vector <std::vector <int>> overlappingCloths (1000, std::vector<int> (1000, 0));

// Update de 2D vector door op alle plekken waar gesneden wordt, een '#' te zetten en update de 2D vector die bijhoudt waar gesneden 
void cutFabric (int leftPos, int topPos, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            clothOfFabric.at(topPos + i).at(leftPos + j) = '#';
            overlappingCloths.at(topPos + i).at(leftPos + j)++;
        }
    }
}

// Tel de plekken op het doen die mkeer dan 1 keer gebruikt worden
void countOverlapping() {
    int amountOfOverlapping = 0;
    for (int i = 0; i < overlappingCloths.size(); i++) {
        for (int j = 0; j < overlappingCloths.at(i).size(); j++) {
            if (overlappingCloths.at(i).at(j) >= 2) {
                amountOfOverlapping++;
            }
        }
    }
    std::cout << amountOfOverlapping << std::endl;
} 

int main() {
    std::fstream inputFile;
    std::vector <int> posFromTop;
    std::vector <int> posFromLeft;
    std::vector <int> widthOfFabric;
    std::vector <int> heightOfFabric;
    int numberOfAction, inputNumber1, inputNumber2, inputNumber3, inputNumber4;
    inputFile.open("Day3_Input.txt");
    while (inputFile >> numberOfAction >> inputNumber1 >> inputNumber2 >> inputNumber3 >> inputNumber4) {
        posFromLeft.push_back(inputNumber1);
        posFromTop.push_back(inputNumber2);
        widthOfFabric.push_back(inputNumber3);
        heightOfFabric.push_back(inputNumber4);
    }
    // Snij een stuk uit het doek
    for (int i = 0; i < posFromLeft.size(); i++) {
        cutFabric(posFromLeft.at(i), posFromTop.at(i), widthOfFabric.at(i), heightOfFabric.at(i));
    }
    countOverlapping();
}
