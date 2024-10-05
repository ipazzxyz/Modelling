#pragma once
#include <string>

class Asset {
public:
    Asset(double cost, std::string name, double percent);

    double GetBuyRate() const;
    double GetSellRate() const;
    std::string GetName() const;
    double GetPercent() const;
    // TODO: где девиденты?

    void Iterate(double rand_num, double spread, double rng_max);

private:
    double cost;
    std::string name;
    double percent;
};
