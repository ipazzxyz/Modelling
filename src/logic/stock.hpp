#pragma once
#include "asset.hpp"

class Stock final : public Asset {
public:
    Stock(double cost_, int period_);
    int WhenIsThePayment() const;
    void Iterate(double spread, double tax, double rand_num, int month) override final;
private:
    double dividends;
    int period, how_months;
};