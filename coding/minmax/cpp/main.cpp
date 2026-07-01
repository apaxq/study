// This solution is O(n), where n is the number of integers in the file
#include <iostream>
#include <fstream>

int getMinMaxFromFile(const std::string& fileName) {
    int min,max;
    std::ifstream file(fileName);
    std::string line;

    // Grab first number as benchmark
    if (file.is_open()) {
        getline(file, line);
        const int integer = std::stoi(line);
        min = integer;
        max = integer;
    }else{
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    // Compare all numbers with benchmarks
    while (std::getline(file, line)) {
        const int integer = std::stoi(line);
        if (integer < min) {
            min = integer;
        }else if (integer > max) {
            max = integer;
        }
    }
    
    file.close();

    std::cout << "The min is " << min << "\nThe max is " << max << std::endl;
    return 0;
}

int main(const int argc, char* argv[]) {
    if (argc > 1) {
        return getMinMaxFromFile(argv[1]);
    }

    std::cerr << "Usage: " << argv[0] << " <file>" <<  std::endl;
    return 1;
}
