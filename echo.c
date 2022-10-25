#include <iostream>

int main() {
    char buffer[256];

    printf("Hello! Please enter some text:\n");
    while (std::cin >> buffer) {
        std::cout << buffer << std::endl;
        std::cout << ">> ";
    }

    return 0;
}
