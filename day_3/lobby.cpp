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

void partTwo(std::ifstream *banks) {
    std::vector<int> batteries;
    long total = 0;
    std::string bank;
    while(std::getline(*banks, bank)) {
        for(std::string::iterator it = bank.begin(); it != bank.end(); it++) {
            size_t remaining = std::distance(it, bank.end());
            int digit = *it - '0';

            while(!batteries.empty() && digit > batteries.back() && batteries.size() + remaining > 12) {
                batteries.pop_back();
            }

            if(batteries.size() < 12) {
                batteries.push_back(digit);
            }
        }

        total += [stack = &batteries]() -> long {
            long x = 0;
            for(int &e : *stack) {
                x += e;
                x *= 10;
            }
            return x /= 10;
        }();

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
    banks.clear();
    banks.seekg(0, std::ios::beg);
    partTwo(&banks);

    banks.close();
    return 0;
}
