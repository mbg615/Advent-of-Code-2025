// Link: https://adventofcode.com/2025/day/4

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int processMatrix(std::vector<std::string> &floorMatrix) {
    std::vector<std::tuple<int, int>> indices;
    size_t rowLength = floorMatrix[0].size() - 2;
    int empty = 0;
    int total = 0;
    for(int i = 1; i < floorMatrix.size() - 1; i++) {
        for (int j = 1; j < rowLength + 1; j++) {
            if (floorMatrix[i - 1][j - 1] == '.') empty++;
            if (floorMatrix[i - 1][j] == '.') empty++;
            if (floorMatrix[i - 1][j + 1] == '.') empty++;
            if (floorMatrix[i][j - 1] == '.') empty++;
            if (floorMatrix[i][j + 1] == '.') empty++;
            if (floorMatrix[i + 1][j - 1] == '.') empty++;
            if (floorMatrix[i + 1][j] == '.') empty++;
            if (floorMatrix[i + 1][j + 1] == '.') empty++;

            if (empty > 4 && floorMatrix[i][j] == '@') {
                indices.emplace_back(i,j);
                total++;
            }

            empty = 0;
        }
    }

    for(std::tuple<int, int> &index : indices) {
        floorMatrix[std::get<0>(index)][std::get<1>(index)] = '.';
    }

    return total;
}

void partOne(std::ifstream *floor) {
    std::vector<std::string> floorMatrix;
    std::string row;
    size_t rowLength;
    while(std::getline(*floor, row)) {
        if(floorMatrix.empty()) {
            rowLength = row.length();
            floorMatrix.emplace_back(rowLength + 2, '.');
        }

        row.insert(row.begin(), '.');
        row.insert(row.end(), '.');

        floorMatrix.push_back(row);
    }
    floorMatrix.emplace_back(row.length() + 2, '.');

    int total = processMatrix(floorMatrix);
    std::cout << "There are " << total << " rolls of paper that can be accessed by the forklifts" << std::endl;
}

void partTwo(std::ifstream *floor) {
    std::vector<std::string> floorMatrix;
    std::string row;
    size_t rowLength;
    while(std::getline(*floor, row)) {
        if(floorMatrix.empty()) {
            rowLength = row.length();
            floorMatrix.emplace_back(rowLength + 2, '.');
        }

        row.insert(row.begin(), '.');
        row.insert(row.end(), '.');

        floorMatrix.push_back(row);
    }
    floorMatrix.emplace_back(row.length() + 2, '.');

    int accessibleRolls = 0;
    int total = 0;

    do {
        accessibleRolls = processMatrix(floorMatrix);
        total += accessibleRolls;
    } while(accessibleRolls != 0);

    std::cout << "There are " << total << " rolls of paper that can be accessed by the forklifts eventually" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "No input file provided\n";
        return -1;
    }

    std::ifstream floor(argv[1]);

    partOne(&floor);
    floor.clear();
    floor.seekg(0, std::ios::beg);
    partTwo(&floor);

    floor.close();
    return 0;
}