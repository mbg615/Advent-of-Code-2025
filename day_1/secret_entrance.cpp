// Link: https://adventofcode.com/2025/day/1

#include <iostream>
#include <fstream>
#include <string>

void partOne(std::ifstream *codes) {
    int direction = 1, amount = 0, position = 50, counter = 0;
    std::string movement;
    while(std::getline(*codes, movement)) {
        if(movement.empty()) break;
        direction = movement.at(0) == 'L' ? -1 : 1;
        amount = std::stoi(movement.substr(1, movement.length()));
        position = (position + (direction * amount)) % 100;
        if(!position) counter++;
    }

    std::cout << "The dial stops on 0: " << counter << " times" << std::endl;
}

void partTwo(std::ifstream *codes) {
    int direction = 1, amount = 0, position = 50, counter = 0;
    std::string movement;

    while(std::getline(*codes, movement)) {
        if(movement.empty()) break;
        direction = movement.at(0) == 'L' ? -1 : 1;
        amount = std::stoi(movement.substr(1, movement.length()));
        for(int i = 0; i < amount; i++) {
            position = (position + direction) % 100;
            if(!position) counter++;
        }
    }

    std::cout << "The dial passes or stops on 0: " << counter << " times" << std::endl;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cerr << "No input file provided\n";
        return -1;
    }

    std::ifstream codes(argv[1]);

    partOne(&codes);
    codes.clear();
    codes.seekg(0, std::ios::beg);
    partTwo(&codes);

    codes.close();
    return 0;
}
