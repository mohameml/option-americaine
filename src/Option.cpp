#include "Option.hpp"

#include "string.h"
#include "OptionBasket.hpp"
#include "OptionBestOf.hpp"
#include "OptionGeometricPut.hpp"
#include <iostream>

using namespace std;

Option::Option()
{
}

Option::Option(const nlohmann::json json)
{

    json.at("maturity").get_to(T_);
    json.at("model size").get_to(size_);
    json.at("dates").get_to(dates_);
}

Option *instance_option(const nlohmann::json json)
{
    Option *opt = NULL;
    string optionType;
    json.at("option type").get_to(optionType);

    if (optionType == "basket")
        opt = new OptionBasket(json);
    else if (optionType == "geometric_put")
        opt = new OptionGeometricPut(json);
    else if (optionType == "bestof")
        opt = new OptionBestOf(json);
    else
    {
        cout << "Option " << optionType << " unknow. Abort." << endl;
        abort();
    }

    return opt;
}
