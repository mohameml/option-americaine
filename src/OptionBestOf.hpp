#ifndef _Option_Best_Of_H
#define _Option_Best_Of_H

#include "Option.hpp"
#include "json_helper.hpp"

class OptionBestOf : public Option
{

public:
    double strike;
    PnlVect *payoff_coeffcients;

    OptionBestOf();
    OptionBestOf(const nlohmann::json json);
    ~OptionBestOf();
    double payoff(const PnlVect *St) override;
};

#endif