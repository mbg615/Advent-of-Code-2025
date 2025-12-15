#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void partOne(std::ifstream *banks) {
    std::vector<int> batteries;
    int total = 0;
    std::string bank;
    while(std::getline(*banks, bank)) {
        for(int i = 0; i < bank.length(); i++) {
            for(int j = i + 1; j < bank.length(); j++) {
                batteries.push_back(((bank[i] - '0') * 10) + (bank[j] - '0'));
            }
        }

        std::sort(batteries.begin(), batteries.end());
        total += batteries.back();
        batteries.clear();
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
