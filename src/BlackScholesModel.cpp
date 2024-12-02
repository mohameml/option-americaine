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

    G = pnl_vect_create_from_scalar(size_, 0.0);
}

BlackScholesModel::~BlackScholesModel()
{
    pnl_vect_free(&sigma_);
    pnl_vect_free(&spot_);
    pnl_vect_free(&divid);
    pnl_vect_free(&G);
    pnl_mat_free(&L);
}

void BlackScholesModel::asset(PnlMat *path, double T, int dates, PnlRng *rng)
{
    int D = this->size_;
    double r = this->r_;
    double time_step = T / (double)dates;
    pnl_mat_set_row(path, spot_, 0);

    for (int i = 1; i < path->m; i++)
    {
        pnl_vect_rng_normal(G, D, rng);
        for (int d = 0; d < D; d++)
        {
            double sigma_d = GET(sigma_, d);
            PnlVect L_d = pnl_vect_wrap_mat_row(L, d);
            MLET(path, i, d) = MGET(path, i - 1, d) * exp((r - sigma_d * sigma_d / 2.0) * (time_step) + sigma_d * sqrt(time_step) * pnl_vect_scalar_prod(&L_d, G));
        }
    }
}

double BlackScholesModel::discount(double t)
{
    return 0.0;
}
