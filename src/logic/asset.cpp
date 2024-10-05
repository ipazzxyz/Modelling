#include "asset.hpp"

Asset::Asset(double cost, double percent)
    : cost(cost), percent(percent), deltaCost(0) {}

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
    cost *= 2 * spread * rand_num + 1 - spread;
}
