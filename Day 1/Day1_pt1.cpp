#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

int main() {
    std::fstream inputFile;
    inputFile.open("Day1_input.txt");
    int inputNumber;
    std::vector <int> inputNumbers;
    // Lees inputfile
    while (inputFile >> inputNumber) {
        inputNumbers.push_back(inputNumber);
    }
    // Tel alle getallen bij elkaar op om het totaal te krijgen
    std::cout << std::accumulate(inputNumbers.begin(), inputNumbers.end(), 0) << std::endl;
}