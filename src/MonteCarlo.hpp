#pragma once

#include "Option.hpp"
#include "BlackScholesModel.hpp"
#include "pnl/pnl_random.h"
#include "pnl/pnl_basis.h"

class MonteCarlo
{
public:
    BlackScholesModel *mod_; /*! pointeur vers le modèle */
    Option *opt_;            /*! pointeur sur l'option */
    int fixing_dates_number; /*! N Nombre de dates de discrétisation : */
    int sample_number;
    PnlRng *rng;
    int nb_func;         /// nb_func for the basis : degree for polynomial regression
    PnlBasis *base;      /// Basis to compute the conditional expected value
    PnlVect *coef_alpha; ///  store coef alpha
    PnlVect *y;          /// store the y_i for the regression problem
    PnlMat *X;           /// store the x_i (vect) for the regression problem

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
