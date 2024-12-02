#include "MonteCarlo.hpp"

MonteCarlo::MonteCarlo(const nlohmann::json json)
{
    json.at("dates").get_to(fixing_dates_number);
    json.at("MC iterations").get_to(sample_number);
    json.at("degree for polynomial regression").get_to(nb_func);
    mod_ = new BlackScholesModel(json);
    opt_ = instance_option(json);
    rng = pnl_rng_create(PNL_RNG_MERSENNE);
    pnl_rng_sseed(rng, time(NULL));

    base = pnl_basis_create(0, nb_func, opt_->size_);
    coef_alpha = pnl_vect_create_from_zero(nb_func);
    y = pnl_vect_create_from_zero(sample_number);
    X = pnl_mat_create_from_zero(sample_number, opt_->size_);
}

MonteCarlo::~MonteCarlo()
{
    pnl_basis_free(&base);
    pnl_vect_free(&coef_alpha);
    pnl_vect_free(&y);
    pnl_mat_free(&X);
    delete opt_;
    delete mod_;
    pnl_rng_free(&rng);
}

double MonteCarlo::price()
{
    return 0.0;
}
