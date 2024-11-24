#ifndef _Option_Basket_H
#define _Option_Basket_H

#include "Option.hpp"
#include "json_helper.hpp"

class OptionBasket : public Option
{

public:
    double strike;
    PnlVect *payoff_coeffcients;

    OptionBasket();
    OptionBasket(const nlohmann::json json);
    ~OptionBasket();

    double payoff(const PnlVect *St) override;
};

#endif
