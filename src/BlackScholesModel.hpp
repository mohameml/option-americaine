#pragma once

#include "pnl/pnl_random.h"
#include "pnl/pnl_vector.h"
#include "pnl/pnl_matrix.h"
#include "json_helper.hpp"

/// \brief Modèle de Black Scholes
class BlackScholesModel
{
public:
    int size_;       /// nombre d'actifs du modèle
    double r_;       /// taux d'intérêt
    double rho_;     /// paramètre de corrélation
    PnlVect *sigma_; /// vecteur de volatilités
    PnlVect *divid;  /// vecteur des dividendes
    PnlVect *spot_;  /// valeurs initiales des sous-jacents
    PnlMat *L;       /// raccine carrée de matrice de corrélation
    PnlVect *G;      /// vect for simulation

    /**
     * Génère une trajectoire du modèle et la stocke dans path
     *
     * @param[out] path contient une trajectoire du modèle.
     * C'est une matrice de taille (nbTimeSteps+1) x d
     * @param[in] T  maturité
     * @param[in] nbTimeSteps nombre de dates de constatation
     */
    void asset(PnlMat *path, double T, int dates, PnlRng *rng);

    /**
     * Calcule l'actualisation à la date t
     */
    double discount(double t);

    /**
     * Constructeur :
     */
    BlackScholesModel(const nlohmann::json json);

    /**
     * fonction qui simule S_tn = S_0*exp((r -sigma**2/2)*tn + sigma*sqrt(tn)*G) avce G suit une loi normale (0,1)
     *
     * @param[in] St : vecteur de taille D qui stocke la simulation de prix du sous-jacent à l'instant tn .
     * @param[in] tn : current time  .
     * @param[in] rng : génerateur des nombres aléatoires .
     *
     */
    void simulation_of_st(PnlVect *St, double tn, PnlRng *rng);

    /**
     * Destructeur :
     */
    ~BlackScholesModel();
};
