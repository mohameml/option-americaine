#pragma once

#include "Option.hpp"
#include "BlackScholesModel.hpp"
#include "pnl/pnl_random.h"

class MonteCarlo
{
public:
    BlackScholesModel *mod_; /*! pointeur vers le modèle */
    Option *opt_;            /*! pointeur sur l'option */
    int fixing_dates_number; /*! N Nombre de dates de discrétisation : */
    int sample_number;
    PnlRng *rng;
    /**
     * Calcule le prix de l'option à la date 0
     *
     * @return valeur de l'estimateur Monte Carlo
     */
    double price();

    /**
     * Constructeur :
     */
    MonteCarlo(const nlohmann::json json);

    /**
     * Destructeur :
     */
    ~MonteCarlo();
};
