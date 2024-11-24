#pragma once

#include "pnl/pnl_vector.h"
#include "pnl/pnl_matrix.h"
#include "string.h"
#include "json_helper.hpp"

/// \brief Classe Option abstraite
class Option
{
public:
    double T_;  /// maturité
    int dates_; /// nombre de dates d'exercice
    int size_;  /// dimension du modèle, redondant avec BlackScholesModel::size_

    /**
     * Calcule la valeur du payoff
     *
     * @param[in] St est un un vecteur de taille size_
     * contenant la valeur des sous-jacents à un instant donné.
     */
    virtual double payoff(const PnlVect *St) = 0;
    /**
     * Constructeur
     */
    Option();

    /**
     * Constructeur de parsing :
     */
    Option(const nlohmann::json json);

    /**
     * Destructeur
     */
    virtual ~Option() {};
};

/**
 * return la classe de l'option selon OptionType
 */
extern Option *instance_option(const nlohmann::json json);
