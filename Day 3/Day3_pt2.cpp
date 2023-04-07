#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector <std::vector <char>> clothOfFabric (1000, std::vector<char> (1000, '.'));
std::vector <std::vector <bool>> perfectSpots (1000, std::vector<bool> (1000, false));

// Als een positie 'true' is en er wordt wéér uitgesneden, maak het false.
void cutFabric (int leftPos, int topPos, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(perfectSpots.at(topPos + i).at(leftPos + j)) {
                perfectSpots.at(topPos + i).at(leftPos + j) = false;
            }
            else {
                perfectSpots.at(topPos + i).at(leftPos + j) = true;
            }
        }
    }
}

// Ga elke afmeting opnieuw langs om te kijken of elk plekje nog 'true' is.
void findPerfectClaim(int leftPos, int topPos, int width, int height, int numberOfMove) {
    bool perfectClaim = true;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!(perfectSpots.at(topPos + i).at(leftPos + j))) {
                perfectClaim = false;
            }
        }
    }
    // Als elk plekje true is, cout de afmetingen en ID van de opdracht
    if (perfectClaim) {
        std::cout << "#" << numberOfMove << " @ " << leftPos << "," << topPos << ": " << width << "x" << height << std::endl;
    }
} 

int main() {
    std::fstream inputFile;
    std::vector <int> posFromTop;
    std::vector <int> posFromLeft;
    std::vector <int> widthOfFabric;
    std::vector <int> heightOfFabric;
    std::vector <int> numOfMoves;
    int numberOfAction, inputNumber1, inputNumber2, inputNumber3, inputNumber4;
    inputFile.open("Day3_Input.txt");
    while (inputFile >> numberOfAction >> inputNumber1 >> inputNumber2 >> inputNumber3 >> inputNumber4) {
        numOfMoves.push_back(numberOfAction);
        posFromLeft.push_back(inputNumber1);
        posFromTop.push_back(inputNumber2);
        widthOfFabric.push_back(inputNumber3);
        heightOfFabric.push_back(inputNumber4);
    }
    // Snij de stukjes eruit
    for (int i = 0; i < posFromLeft.size(); i++) {
        cutFabric(posFromLeft.at(i), posFromTop.at(i), widthOfFabric.at(i), heightOfFabric.at(i));
    }
    // Zoek de perfecte claim die maar 1 keer gebruikt wordt
    for (int j = 0; j < posFromLeft.size(); j++) {
        findPerfectClaim(posFromLeft.at(j), posFromTop.at(j), widthOfFabric.at(j), heightOfFabric.at(j), numOfMoves.at(j)); 
    }
}
