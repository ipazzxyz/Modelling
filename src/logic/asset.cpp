#include "asset.hpp"

void Asset::SetAsset(double cost_, double percent_) {
    cost = cost_;
    percent = percent_;
}

std::pair<double, double> Asset::GetBuyRate() const {
    return {cost * 1.1, deltaCost * 1.1};
}

std::pair<double, double> Asset::GetSellRate() const {
    return {cost, deltaCost};
}

double Asset::GetDividends() const {
    return cost * percent;
}

void Asset::Iterate(double rand_num, double spread) {
    deltaCost = -cost;
    deltaCost += cost *= 2 * spread * rand_num - spread + 1;
}
