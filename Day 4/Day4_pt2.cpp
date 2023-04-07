#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int findGuardWhoSleepsMost(std::vector <std::string> inputLines) {
    int guardNumber = 0;
    int timeAsleep = 0;
    int endOfGuardNumber = 0;
    int maxTimeAsleep = 0;
    int guardWhoSleepsMost = 0;
    int sleepiestMinute = 0;
    int answer = 0;
    std::vector <std::vector <int>> minutes (5000, std::vector <int> (59, 0));
    std::vector <int> Guards(5000, 0);
    // Verander het nummer van de bewaker als er een wisseling van de wacht plaatsvindt
    for (int i = 0; i < inputLines.size(); i++) {
        if (inputLines.at(i).at(19) == 'G') {
            endOfGuardNumber = inputLines.at(i).find('b');
            guardNumber = std::stoi(inputLines.at(i).substr(26, endOfGuardNumber - 2));
        }
        if (inputLines.at(i).at(19) == 'f') {
            int currentMinute = std::stoi(inputLines.at(i).substr(15, 16));
            timeAsleep = std::stoi(inputLines.at(i + 1).substr(15, 16)) - currentMinute;
            for (int i = currentMinute; i < (currentMinute + timeAsleep); i++) {
                minutes.at(guardNumber).at(i)++;
            } 
            Guards.at(guardNumber) += timeAsleep;
        }
    }
    int max = 0;
    // Zoek de minuut waar één bewaker het vaakst in slaap was en zoek de nummer van de bijbehorende bewaker erbij
    for (int i = 0; i < minutes.size(); i++) {
        for (int j = 0; j < minutes.at(i).size(); j++) {
            if (minutes.at(i).at(j) > max) {
                sleepiestMinute = j;
                guardWhoSleepsMost = i;
                max = minutes.at(i).at(j);
            }
        }
    }
    answer = guardWhoSleepsMost * sleepiestMinute;
    return answer;
}

int main() {
    std::fstream inputFile;
    std::string inputLine;
    std::vector <std::string> fullInput;
    inputFile.open("Day4_Input.txt");
    while (std::getline(inputFile, inputLine)) {
        fullInput.push_back(inputLine);
    }
    // Sorteer de inputlines in chronologische volgorde
    std::sort(fullInput.begin(), fullInput.end());
    std::cout << findGuardWhoSleepsMost(fullInput);
}