#include <iostream>
#include <limits>
#include <cmath>

void handleFloatLiterals() {
    // Positif sonsuz (inf) değeri
    float positiveInfinity = std::numeric_limits<float>::infinity();
    std::cout << "Positive Infinity: " << positiveInfinity << std::endl;

    // Negatif sonsuz (-inf) değeri
    float negativeInfinity = -std::numeric_limits<float>::infinity();
    std::cout << "Negative Infinity: " << negativeInfinity << std::endl;

    // NaN (Not a Number) değeri
    float nanValue = std::numeric_limits<float>::quiet_NaN();
    std::cout << "NaN: " << nanValue << std::endl;
}

void handleDoubleLiterals() {
    // Positif sonsuz (inf) değeri
    double positiveInfinity = std::numeric_limits<double>::infinity();
    std::cout << "Positive Infinity: " << positiveInfinity << std::endl;

    // Negatif sonsuz (-inf) değeri
    double negativeInfinity = -std::numeric_limits<double>::infinity();
    std::cout << "Negative Infinity: " << negativeInfinity << std::endl;

    // NaN (Not a Number) değeri
    double nanValue = std::numeric_limits<double>::quiet_NaN();
    std::cout << "NaN: " << nanValue << std::endl;
}

int main() {
    handleFloatLiterals();
    std::cout << "-------------------" << std::endl;
    handleDoubleLiterals();

    return 0;
}