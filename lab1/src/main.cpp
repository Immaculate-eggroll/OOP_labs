#include <iostream>
#include <string>
#include "to24.h"


int main() {
    std::string input;
    std::getline(std::cin, input);


    std::string result = to24(input);
    if (result.empty()) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }


    std::cout << result << std::endl;
    return 0;
}
