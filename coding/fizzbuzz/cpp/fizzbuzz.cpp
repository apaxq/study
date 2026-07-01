#include <iostream>

void fizzbuzz(const int max) {
    if (max != 0) {
        fizzbuzz(max - 1);
    }

    if (max % 3 == 0 || max % 5 == 0) {
        if (max % 3 == 0) {
            std::cout << "Fizz";
        }
        if (max % 5 == 0) {
            std::cout << "Buzz";
        }
        std::cout << std::endl;
    } else {
        std::cout << max << std::endl;
    }
}

int main(const int argc, char* argv[]) {
    if (argc > 1) {
        fizzbuzz(std::stoi(argv[1]));
        return 0;
    }

    std::cerr << "Usage: " << argv[0] << " <number>" <<  std::endl;
    return 1;
}