#include <iostream>
#include "pnl/pnl_basis.h"

int main()
{

    PnlBasis *base = pnl_basis_create(0, 3, 1);
    // pnl_basis_print(base);
    PnlVect *x = pnl_vect_create_from_scalar(1, 2.0);
    double res = pnl_basis_i_vect(base, x, 2);
    std::cout << "res = f_2 (" << x->array[0] << ", " << x->array[1] << ") =" << res << std::endl;
    pnl_basis_free(&base);
    return 0;
}