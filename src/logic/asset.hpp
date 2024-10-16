#pragma once

#include <string>

class Asset {
public:
    void SetAsset(double cost, double percent);

    std::pair<double, double> GetBuyRate() const;

    std::pair<double, double> GetSellRate() const;

    double GetDividends() const;

    void Iterate(double rand_num, double spread);

private:
    double cost, delta_cost;
    double percent;
};
