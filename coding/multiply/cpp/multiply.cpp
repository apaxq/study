#include <iostream>

int multiply (const int a, const int b) {
    if (b == 0) {
        return 0;
    }

    if (b < 0) {
        return -a + multiply(a, b+1);
    }

    return a + multiply(a, b-1);
}

int main(const int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << argv[1] << " * " << argv[2] << " = "
        << multiply(std::stoi(argv[1]), std::stoi(argv[2]));
        return 0;
    }

    std::cerr << "Usage: " << argv[0] << " <multiplicand> <multiplier>" << std::endl;
}