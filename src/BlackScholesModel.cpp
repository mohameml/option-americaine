#include "BlackScholesModel.hpp"

BlackScholesModel::BlackScholesModel(const nlohmann::json json)
{
    json.at("model size").get_to(size_);
    json.at("interest rate").get_to(r_);
    json.at("correlation").get_to(rho_);
    json.at("volatility").get_to(sigma_);
    if (sigma_->size == 1 && size_ > 1)
    {
        pnl_vect_resize_from_scalar(sigma_, size_, GET(sigma_, 0));
    }
    json.at("spot").get_to(spot_);
    if (spot_->size == 1 && size_ > 1)
    {
        pnl_vect_resize_from_scalar(spot_, size_, GET(spot_, 0));
    }
    json.at("dividend rate").get_to(divid);
    if (divid->size == 1 && size_ > 1)
    {
        pnl_vect_resize_from_scalar(divid, size_, GET(divid, 0));
    }
    L = pnl_mat_create(size_, size_);
    pnl_mat_set_all(L, rho_);

    for (int i = 0; i < size_; i++)
        pnl_mat_set_diag(L, 1.0, i);

    pnl_mat_chol(L);
}

BlackScholesModel::~BlackScholesModel()
{
    pnl_vect_free(&sigma_);
    pnl_vect_free(&spot_);
    pnl_vect_free(&divid);
    pnl_mat_free(&L);
}

void BlackScholesModel::asset(PnlMat *path, double T, int dates, PnlRng *rng)
{
}

double BlackScholesModel::discount(double t)
{
    return 0.0;
}
