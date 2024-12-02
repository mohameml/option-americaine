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
    double res = pnl_vect_prod(St);
    res = std::exp(std::log(res) / size_); // on utilise res**(1/d) = exp(ln(res) /d) au lien de pow (pour avoir une bonne précision );
    return std::max(strike - res, 0.0);
}
