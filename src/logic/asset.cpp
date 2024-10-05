#include "asset.hpp"

Asset::Asset(double cost, std::string name, double percent)
    : cost(cost), name(name), percent(percent) {}

double Asset::GetBuyRate() const {
    return cost * 1.1;
}

double Asset::GetSellRate() const {
    return cost;
}

std::string Asset::GetName() const {
    return name;
}

double Asset::GetPercent() const {
    return percent;
}

void Asset::Iterate(double rand_num, double spread, double rng_max) {
    cost *= 2 * spread * rand_num / rng_max + 1 - spread;
}
