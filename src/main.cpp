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

    std::cout << mc->fixing_dates_number << std::endl;
    std::cout << mc->sample_number << std::endl;
    std::cout << mc->mod_->r_ << std::endl;

    // double directPrice;
    // double newPrice;
    // double newPriceStd;

    // PricingResults res(directPrice,newPrice, newPriceStd);
    // std::cout << res << std::endl;

    delete mc;
    file.close();
    return 0;
}