#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int numberOfPoints;
    int numberOfInCircle = 0;

    std::cout << "请输入随机点的数量（输入'exit'退出）: ";
    std::string input;

    while (true) {
        std::getline(std::cin, input);

        if (***pare("exit") == 0) {
            break;
        }

        try {
            numberOfPoints = std::stoi(input);
        } catch (std::invalid_argument e) {
            std::cout << "输入错误，请输入一个整数。" << std::endl;
            continue;
        }

        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < numberOfPoints; i++) {
            double x = static_cast<double>(rand()) / RAND_MAX;
            double y = static_cast<double>(rand()) / RAND_MAX;
            double distance = std::sqrt(x * x + y * y);

            if (distance <= 1.0) {
                numberOfInCircle++;
            }
        }

        double piEstimate = 4.0 * numberOfInCircle / numberOfPoints;
        std::cout << "Estimated value of Pi: " << piEstimate << std::endl;
    }

    return 0;
}
