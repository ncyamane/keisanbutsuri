#include "../include/all.hpp"

int main(int argc, char *argv[]) {
    float eps_f = 1.0 * std::pow(10, -5);
    double eps_d = 1.0 * std::pow(10, -14);
    long double eps = 1.0 * std::pow(10, -17);

    float a_f = 1.0;
    double a_d = 1.0;
    long double a = 1.0;

    std::cout << std::sqrt(a_f) - std::sqrt(a_f + eps_f) << "\n";
    std::cout << eps_f / (std::sqrt(a_f) + std::sqrt(a_f + eps_f)) << "\n";

    std::cout << std::sqrt(a_d) - std::sqrt(a_d + eps_d) << "\n";
    std::cout << eps_d / (std::sqrt(a_d) + std::sqrt(a_d + eps_d)) << "\n";

    std::cout << std::sqrt(a) - std::sqrt(a + eps) << "\n";
    std::cout << eps / (std::sqrt(a) + std::sqrt(a + eps)) << "\n";
}