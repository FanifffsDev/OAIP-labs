#include <iostream>
#include <string>
#include <limits>
#include <sstream>

int getInt() {
    std::string input;
    int value;
    while (true) {
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (ss >> value && ss.eof()) {
            return value;
        }
        else {
            std::cout << "Ошибка: введено не int. Попробуйте снова." << std::endl;
        }
    }
}

int getIntInRange(int minVal, int maxVal) {
    int value;
    while (true) {
        value = getInt();

        if (value >= minVal && value <= maxVal) {
            return value;
        }
        std::cout << "Ошибка! Введите число от " << minVal << " до " << maxVal << ".\n";
    }
}

float getFloat() {
    float value;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (ss >> value && ss.eof()) {
            return value;
        }
        else {
            std::cout << "Ошибка: введено не float. Попробуйте снова." << std::endl;
        }
    }
}

double getDouble() {
    double value;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (ss >> value && ss.eof()) {
            return value;
        }
        else {
            std::cout << "Ошибка: введено не double. Попробуйте снова." << std::endl;
        }
    }
}