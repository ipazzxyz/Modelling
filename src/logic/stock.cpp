#include "stock.hpp"

Stock::Stock(double cost_, int period_):
    Asset(cost_), period(period_), how_months(0) {}

int Stock::WhenIsThePayment() const {
    return period - (how_months % period);
}

void Stock::Iterate(double spread, double tax, double rand_num, int month) {
    cost = cost * (2. * spread * rand_num - spread + 1.);
    how_months = (how_months % period) + 1;
    if (how_months == period)
        dividends = cost * (1. - rand_num) * (1. - tax) / 12.;
    else
        dividends = 0;
    graph.emplace_back(month, cost);
}
