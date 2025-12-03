#include <iostream>
#include <fstream>
#include <string>
#include <regex>

long findDuplicates(long start, long end, std::regex pattern) {
    long total = 0;

    for(long i = start; i <= end; i++) {
        if(std::regex_search(std::to_string(i), pattern)) total += i;
    }

    return total;
}

void partOne(std::ifstream *productIDs) {
    std::regex regex_patern("^(\\S+)\\1$");
    long start = 0, end = 0;
    long total = 0;

    while(*productIDs >> start) {
        productIDs->get(); // Consume the '-'
        *productIDs >> end;
        productIDs->get(); // Consume the ','
        total += findDuplicates(start, end, regex_patern);
    }

    std::cout << "The sum of all product IDs containing a sequence repeated twice is: " << total << std::endl;
    return;
}

void partTwo(std::ifstream *productIDs) {
    std::regex regex_patern("^(.+)\\1+$");
    long start = 0, end = 0;
    long total = 0;

    while(*productIDs >> start) {
        productIDs->get(); // Consume the '-'
        *productIDs >> end;
        productIDs->get(); // Consume the ','
        total += findDuplicates(start, end, regex_patern);
    }

    std::cout << "The sum of all product IDs containing a sequence repeated at least twice: " << total << std::endl;
    return;
}

int main(int argc, char**argv) {
    if(argc < 2) {
        std::cerr << "No input file provided\n";
        return -1;
    }

    std::ifstream productIDs(argv[1]);

    partOne(&productIDs);
    productIDs.clear();
    productIDs.seekg(0, std::ios::beg);
    partTwo(&productIDs);

    return 0;
}
