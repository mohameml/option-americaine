#include "Option.hpp"
#include "OptionGeometricPut.hpp"

OptionGeometricPut::OptionGeometricPut()
{
}

OptionGeometricPut::~OptionGeometricPut()
{
}

OptionGeometricPut::OptionGeometricPut(const nlohmann::json json) : Option(json)
{
    json.at("strike").get_to(strike);
}

double OptionGeometricPut::payoff(const PnlVect *St)
{
    return 0.0;
}
