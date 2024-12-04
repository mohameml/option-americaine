#include <iostream>
#include "MonteCarlo.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cout << "Le nombre d'arguments attendu est 2" << std::endl;
        exit(1);
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
    nlohmann::json json = nlohmann::json::parse(file);
    MonteCarlo *mc = new MonteCarlo(json);

    double directPrice = 0.0;
    // double newPrice;
    // double newPriceStd;

    directPrice = mc->price();
    std::cout << "price MC = " << directPrice << std::endl;

    // PricingResults res(directPrice,newPrice, newPriceStd);
    // std::cout << res << std::endl;

    delete mc;
    file.close();
    return 0;
}