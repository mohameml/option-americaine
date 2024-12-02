#include "Option.hpp"
#include "OptionBestOf.hpp"

OptionBestOf::OptionBestOf()
{
}

OptionBestOf::OptionBestOf(const nlohmann::json json) : Option(json)
{
    json.at("strike").get_to(strike);
    json.at("payoff coefficients").get_to(payoff_coeffcients);
    if (payoff_coeffcients->size == 1 && size_ > 1)
    {
        pnl_vect_resize_from_scalar(payoff_coeffcients, size_, GET(payoff_coeffcients, 0));
    }
}

OptionBestOf::~OptionBestOf()
{
    pnl_vect_free(&this->payoff_coeffcients);
}

double OptionBestOf::payoff(const PnlVect *St)
{
    PnlVect *res_vect = pnl_vect_copy(St);
    pnl_vect_mult_vect_term(res_vect, payoff_coeffcients);
    double res = std::max(pnl_vect_max(res_vect) - strike, 0.0);
    pnl_vect_free(&res_vect);
    return res;
}
