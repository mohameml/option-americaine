#include "Option.hpp"
#include "OptionBasket.hpp"

OptionBasket::OptionBasket()
{
}

OptionBasket::OptionBasket(const nlohmann::json json) : Option(json)
{
    json.at("strike").get_to(strike);
    json.at("payoff coefficients").get_to(payoff_coeffcients);
    if (payoff_coeffcients->size == 1 && size_ > 1)
    {
        pnl_vect_resize_from_scalar(payoff_coeffcients, size_, GET(payoff_coeffcients, 0));
    }
}

OptionBasket::~OptionBasket()
{
    pnl_vect_free(&this->payoff_coeffcients);
}

double OptionBasket::payoff(const PnlVect *St)
{
    double res = 0;
    res = pnl_vect_scalar_prod(St, payoff_coeffcients);
    return std::max(res - strike, 0.0);
}
