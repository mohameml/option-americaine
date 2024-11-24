#ifndef _Option_Geometric_Put_H
#define _Option_Geometric_Put_H

#include "Option.hpp"
#include "json_helper.hpp"

class OptionGeometricPut : public Option
{

public:
    double strike;

    OptionGeometricPut();
    ~OptionGeometricPut();
    OptionGeometricPut(const nlohmann::json json);

    double payoff(const PnlVect *St) override;
};

#endif