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

    base = pnl_basis_create(PNL_BASIS_HERMITE, nb_func, opt_->size_);
    coef_alpha = pnl_vect_create_from_zero(nb_func);
    y = pnl_vect_create_from_zero(sample_number);
    X = pnl_mat_create_from_zero(sample_number, opt_->size_);

    taux_n = pnl_vect_create_from_scalar(sample_number, opt_->T_);
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

void MonteCarlo::update_taux_n(double tn)
{
    PnlVect *St = pnl_vect_create_from_zero(opt_->size_);
    for (size_t m = 0; m < sample_number; m++)
    {
        mod_->simulation_of_st(St, tn, rng);
        int a = opt_->payoff(St) >= pnl_basis_eval_vect(base, coef_alpha, St) ? 1 : 0;
        LET(taux_n, m) = tn * (double)a + GET(taux_n, m) * (1 - (double)a);
    }

    pnl_vect_free(&St);
}

void MonteCarlo::generate_path(PnlMat *path)
{
    double M = sample_number;
    double N = fixing_dates_number;
    double D = opt_->size_;

    PnlMat *matrix = pnl_mat_create_from_zero(N + 1, D);

    for (size_t m = 0; m < M; m++)
    {
        mod_->asset(matrix, opt_->size_, N, rng);

        // path[m:m + N + 1 , : ] = matrix
        int start_index = m * (N + 1);
        for (size_t i = 0; i < N + 1; i++)
        {
            for (size_t j = 0; j < D; j++)
            {
                MLET(path, start_index + i, j) = MGET(matrix, i, j);
            }
        }
    }

    pnl_mat_free(&matrix);
}

double MonteCarlo::price()
{
    int M = sample_number;
    int N = fixing_dates_number;
    double D = opt_->size_;
    double time_step = opt_->T_ / (double)N;

    PnlMat *path = pnl_mat_create_from_zero(M * (N + 1), D);
    generate_path(path);

    for (size_t n = N - 1; n > 0; n--)
    {
        double t_n = n * time_step;

        // calcul de X et  y :
        for (size_t m = 0; m < M; m++)
        {
            // X :
            PnlVect St_n_m = pnl_vect_wrap_mat_row(path, m + n);
            pnl_mat_set_row(X, &St_n_m, m);

            // y :
            double taux_n_m = GET(taux_n, m);
            int index_taux_n_m = taux_n_m / time_step;
            PnlVect S_taux_m = pnl_vect_wrap_mat_row(path, m + index_taux_n_m);
            LET(y, m) = std::exp(-mod_->r_ * (taux_n_m - t_n)) * opt_->payoff(&S_taux_m);
        }

        // calcul de coef_alpha :
        pnl_basis_fit_ls(base, coef_alpha, X, y);

        // mis jour de taux_n :
        update_taux_n(t_n);
    }

    // calcul de prix à t = 0 :
    PnlVect St_0 = pnl_vect_wrap_mat_row(path, 0);
    double price_1 = opt_->payoff(&St_0);

    double price_2 = 0.0;
    for (size_t m = 0; m < M; m++)
    {
        double taux1_m = GET(taux_n, m);
        int index_taux1_m = taux1_m / time_step;
        PnlVect S_taux1_m = pnl_vect_wrap_mat_row(path, m + index_taux1_m);
        price_2 += std::exp(-mod_->r_ * taux1_m) * opt_->payoff(&S_taux1_m);
    }
    price_2 /= M;

    double price = std::max(price_1, price_2);

    pnl_mat_free(&path);

    return price;
}
