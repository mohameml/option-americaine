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
     * Destructeur :
     */
    ~BlackScholesModel();
};
