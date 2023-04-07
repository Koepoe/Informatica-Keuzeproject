#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int main() {
    std::fstream inputFile;
    inputFile.open("Day1_input.txt");
    std::string inputLine;
    int result = 0;
    int i = 0;
    std::vector <char> subtracters;
    std::vector <int> numbers;
    std::vector <int> results = {0};
    bool hasDuplicate = false;
    while (inputFile >> inputLine) {
        subtracters.push_back(inputLine.at(0));
        numbers.push_back(std::stoi(inputLine.substr(1, inputLine.length() - 1)));
    }
    // Zolang er geen duplicate is gevonden, ga telkens opnieuw door de vector heen en voer de acties uit
    while (!(hasDuplicate)) {
        if (i == subtracters.size()) {
            i = 0;
        }
        // Bij een +, tel de getallen bij elkaar op. Bij een -, haal de getallen van elkaar af
        switch(subtracters.at(i)) {
                case '+':
                    result += numbers.at(i);
                    break;
                case '-':
                    result -= numbers.at(i);
                    break;
        }
        results.push_back(result);
        // Ga door de hele vector heen om te kijken of er al een duplicate voorkomt, zo ja: verander de variabele waardoor de while loop stopt
        for (int j = 0; j < results.size() - 1; j++) {
            if (results.at(j) == results.at(results.size() - 1)) {
                hasDuplicate = true;
                break;
            }
        }
        i++;    
    }
    std::cout << results.at(results.size() - 1) << std::endl;
}