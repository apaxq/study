#include <fstream>
#include <iostream>

#include "LinkedList.h"

LinkedList getIntegersFromFile(const std::string& fileName) {
    LinkedList list;
    std::ifstream file(fileName);
    std::vector<int> integers;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (std::stoi(line) % 6 != 0 || std::stoi(line) % 7 != 0)
            list.insert(std::stoi(line));
        }
    }

    return list;
}

int main() {
    LinkedList list = getIntegersFromFile("../integers.txt");
    list.print();
    std::cout << list.sum() << std::endl;
}