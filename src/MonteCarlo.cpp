#include "MonteCarlo.hpp"

MonteCarlo::MonteCarlo(const nlohmann::json json)
{
    json.at("dates").get_to(fixing_dates_number);
    json.at("MC iterations").get_to(sample_number);
    mod_ = new BlackScholesModel(json);
    opt_ = instance_option(json);
    rng = pnl_rng_create(PNL_RNG_MERSENNE);
    pnl_rng_sseed(rng, time(NULL));
}

MonteCarlo::~MonteCarlo()
{
    delete opt_;
    delete mod_;
    pnl_rng_free(&rng);
}

double MonteCarlo::price()
{
    return 0.0;
}
