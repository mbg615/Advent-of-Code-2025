#include <iostream>
#include <fstream>
#include <string>

void partOne(std::ifstream *banks) {
    int total = 0;
    std::string bank;
    while(std::getline(*banks, bank)) {
        int bankSize = bank.length();
        int highest = 0, highestIndex = 0;

        for(int i = 0; i < bankSize; i++) {
            int battery = (bank[i] - '0');
            if(battery > highest) {
                highest = battery;
                highestIndex = i;
            }
        }

        int secondHighest = 0;
        if(bankSize - 1 == highestIndex) {
            for(int i = 0; i < bankSize - 1; i++) {
                int battery = (bank[i] - '0');
                if(battery > secondHighest) {
                    secondHighest = battery;
                }
            }

            total += (secondHighest * 10) + (highest);
            std::cout << (secondHighest * 10) + (highest) << std::endl;
        } else {
            for(int i = highestIndex + 1; i < bankSize - 1; i++) {
                int battery = (bank[i] - '0');
                if(battery > secondHighest) {
                    secondHighest = battery;
                }
            }

             total += (highest * 10) + (secondHighest);
             std::cout << (highest * 10) + (secondHighest) << std::endl;
        }
    }

    std::cout << "The total output joltage is: " << total << " jolts." << std::endl;

}

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cerr << "No input file provided\n";
        return -1;
    }

    std::ifstream banks(argv[1]);

    partOne(&banks);

}
