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
    PnlVect *taux_n;     /// vect : store the value of taux_n_m m in {1 , .... , M}

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

    /**
     * fonction qui calcule le taux_n à l'instant t_n
     *
     * @param[in] tn : current time
     *
     */
    void update_taux_n(double tn);

    /**
     * fonction qui génère M trajectoires du sous-jacent  : (S_t0_(m) , ..... , S_tN_(m) ) avce m \in {1 , .... ,M}
     *
     * @param[in] path matrice de taille (M*(N + 1) , D)
     */
    void generate_path(PnlMat *path);
};
