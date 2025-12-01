#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cerr << "No input file provided\n";
        return -1;
    }

    std::ifstream codes(argv[1]);
    int direction = 1, amount = 0, position = 50, counter = 0;
    std::string movement;
    while(std::getline(codes, movement)) {
        std::cout << position << std::endl;
        if(movement.empty()) break;
        direction = movement.at(0) == 'L' ? -1 : 1;
        amount = std::stoi(movement.substr(1, movement.length()));
        position = (position + (direction * amount)) % 100;
        if(!position) counter++;
    }

    std::cout << "The dial stops on 0: " << counter << " times" << std::endl;
    codes.close();
}
